/*****************************************************************************
 *                                                                           *
 * Copyright (c) 2003-2015 Intel Corporation.                                *
 * All rights reserved.                                                      *
 *                                                                           *
 *****************************************************************************

This code is covered by the Community Source License (CPL), version
1.0 as published by IBM and reproduced in the file "license.txt" in the
"license" subdirectory. Redistribution in source and binary form, with
or without modification, is permitted ONLY within the regulations
contained in above mentioned license.

Use of the name and trademark "Intel(R) MPI Benchmarks" is allowed ONLY
within the regulations of the "License for Use of "Intel(R) MPI
Benchmarks" Name and Trademark" as reproduced in the file
"use-of-trademark-license.txt" in the "license" subdirectory. 

THE PROGRAM IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED INCLUDING, WITHOUT
LIMITATION, ANY WARRANTIES OR CONDITIONS OF TITLE, NON-INFRINGEMENT,
MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Each Recipient is
solely responsible for determining the appropriateness of using and
distributing the Program and assumes all risks associated with its
exercise of rights under this Agreement, including but not limited to
the risks and costs of program errors, compliance with applicable
laws, damage to or loss of data, programs or equipment, and
unavailability or interruption of operations.

EXCEPT AS EXPRESSLY SET FORTH IN THIS AGREEMENT, NEITHER RECIPIENT NOR
ANY CONTRIBUTORS SHALL HAVE ANY LIABILITY FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING
WITHOUT LIMITATION LOST PROFITS), HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OR
DISTRIBUTION OF THE PROGRAM OR THE EXERCISE OF ANY RIGHTS GRANTED
HEREUNDER, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 

EXPORT LAWS: THIS LICENSE ADDS NO RESTRICTIONS TO THE EXPORT LAWS OF
YOUR JURISDICTION. It is licensee's responsibility to comply with any
export regulations applicable in licensee's jurisdiction. Under
CURRENT U.S. export regulations this software is eligible for export
from the U.S. and can be downloaded by or otherwise exported or
reexported worldwide EXCEPT to U.S. embargoed destinations which
include Cuba, Iraq, Libya, North Korea, Iran, Syria, Sudan,
Afghanistan and any other country to which the U.S. has embargoed
goods and services.

 ***************************************************************************

For more documentation than found here, see

[1] doc/ReadMe_IMB.txt 

[2] Intel (R) MPI Benchmarks
    Users Guide and Methodology Description
    In 
    doc/IMB_Users_Guide.pdf
    
 File: IMB_rma_put.c 

 Implemented functions: 

 IMB_rma_single_get;
 IMB_rma_get_all;
 IMB_rma_get_local;
 IMB_rma_get_all_local;
 IMB_rma_exchange_get;

 ***************************************************************************/

#include "IMB_declare.h"
#include "IMB_benchmark.h"
#include "IMB_prototypes.h"


/* Unidirectional and bidirectional get: communication is done 
 * between two processes only. */ 
void IMB_rma_single_get (struct comm_info* c_info, int size, 
                         struct iter_schedule* iterations, 
                         MODES run_mode, double* time)
{
    double res_time = -1.;
    int target = -1;
    int receiver = 0;
    Type_Size r_size;
    int r_num;
    int i;
    char *recv = (char *)c_info->r_buffer;
#ifdef CHECK 
    defect = 0;
#endif
    ierr = 0;

    if (c_info->rank == c_info->pair0)
    {
        target = c_info->pair1;
        receiver = 1;
    } 
    else if (c_info->rank == c_info->pair1)
    {
        target = c_info->pair0;
        if (run_mode->BIDIR) 
        {
            /* pair1 acts as origin  
             * in bidirectional mode only */
            receiver = 1;
        }    
    }    
    else if (c_info->rank < 0)
    {
        *time = res_time;
        return;
    } 
    
    /* Get size: recv and send sizes are equial, so just use one set of vars*/
    MPI_Type_size(c_info->s_data_type, &r_size);
    r_num = size/r_size;

    for(i = 0; i < N_BARR; i++) MPI_Barrier(c_info->communicator);
     
    /* in case of MPI_Get sender is target */     
    if (receiver)
    {    
        MPI_Win_lock(MPI_LOCK_SHARED, target, 0, c_info->WIN);
        if (run_mode->AGGREGATE)
        {
            res_time = MPI_Wtime();
            for (i = 0; i < iterations->n_sample; i++)
            {
                ierr = MPI_Get((void*)(recv+i%iterations->r_cache_iter*iterations->r_offs), 
                                r_num, c_info->r_data_type, target, 
                                i%iterations->s_cache_iter*iterations->s_offs,
                                r_num, c_info->s_data_type, c_info->WIN);
                
                MPI_ERRHAND(ierr);
            }
            ierr = MPI_Win_flush(target, c_info->WIN);
            MPI_ERRHAND(ierr);
            res_time = (MPI_Wtime() - res_time)/iterations->n_sample;
        }    
        else if ( !run_mode->AGGREGATE )    
        {
            res_time = MPI_Wtime();
            for (i = 0; i < iterations->n_sample; i++)
            {
                ierr = MPI_Get((void*)(recv+i%iterations->r_cache_iter*iterations->r_offs), 
                                r_num, c_info->r_data_type, target, 
                                i%iterations->s_cache_iter*iterations->s_offs,
                                r_num, c_info->s_data_type, c_info->WIN);

                MPI_ERRHAND(ierr);
                ierr = MPI_Win_flush(target, c_info->WIN);
                MPI_ERRHAND(ierr);
            }
            res_time = (MPI_Wtime() - res_time)/iterations->n_sample;
        }

        MPI_Win_unlock(target, c_info->WIN);
    }     
   
    /* Synchronize target and origin processes */
    MPI_Barrier(c_info->communicator);

#ifdef CHECK
    if (receiver || run_mode->BIDIR)
    {
         for(i = 0; i < ITER_MIN(iterations); i++)
         {
             CHK_DIFF("MPI_Get",c_info, (void*)(recv+i%iterations->r_cache_iter*iterations->r_offs), 
                      0, size, size, asize, get, 0, iterations->n_sample, i, target , &defect);
             
         }
    }     
#endif     
    
    *time = res_time; 
    return;
}


/* Implements "One_get_all" and "All_get_all" benchmarks:
 * run_mode Collective corresponds to "All_get_all",
 * run_mode MultPassiveTransfer corresponds to "One_get_all"
 * */
void IMB_rma_get_all (struct comm_info* c_info, int size, 
                      struct iter_schedule* iterations, 
                      MODES run_mode, double* time)
{
    double res_time = -1.;
    int target = 0;
    int peer = 0;
    int receiver = 0;
    Type_Size r_size;
    int r_num;
    int i;
    char *recv = (char *)c_info->r_buffer;
    ierr = 0;

    if (c_info->rank < 0)
    {
        *time = res_time;
        return;
    } 
    
    if (c_info->rank == 0 || run_mode->type == Collective)
    {
        receiver = 1;
    }    

    MPI_Type_size(c_info->r_data_type,&r_size);
    r_num=size/r_size;

    for(i=0; i<N_BARR; i++) MPI_Barrier(c_info->communicator);
    
    if (receiver)
    {    
        MPI_Win_lock_all(0, c_info->WIN);
        
        res_time = MPI_Wtime();
        for (i = 0; i < iterations->n_sample; i++)
        {
            for (peer = 0; peer < c_info->num_procs; peer++)
            {
                /* choose different target for each process to avoid congestion */
                target = (peer + c_info->rank)%c_info->num_procs;
                if (target == c_info->rank)
                {
                    continue; /* do not get from itself*/
                }    
                
                ierr = MPI_Get((void*)(recv+i%iterations->r_cache_iter*iterations->r_offs), 
                                r_num, c_info->r_data_type, target, 
                                i%iterations->s_cache_iter*iterations->s_offs,
                                r_num, c_info->s_data_type, c_info->WIN);
                MPI_ERRHAND(ierr);
            }
        }    
        ierr = MPI_Win_flush_all(c_info->WIN);
        MPI_ERRHAND(ierr);
        res_time = (MPI_Wtime() - res_time)/iterations->n_sample;
    
        MPI_Win_unlock_all(c_info->WIN);
    }     
   
    /* Synchronize origin and target processes */
    MPI_Barrier(c_info->communicator);
    
    *time = res_time; 
    return;
}


/* Implements "Get_local" benchmark. One process gets some data
 * from the other and make sure of completion by MPI_Win_flush_local call 
 * */
void IMB_rma_get_local (struct comm_info* c_info, int size, 
                        struct iter_schedule* iterations, 
                        MODES run_mode, double* time)
{
    double res_time = -1.;
    Type_Size r_size;
    int r_num;
    int i;
    char *recv = (char *)c_info->r_buffer;
    ierr = 0;

    if (c_info->rank < 0)
    {
        *time = res_time;
        return;
    } 
    
    MPI_Type_size(c_info->r_data_type,&r_size);
    r_num=size/r_size;

    for(i=0; i<N_BARR; i++) MPI_Barrier(c_info->communicator);
    
    if (c_info->rank == c_info->pair0)
    {    
        MPI_Win_lock(MPI_LOCK_SHARED, c_info->pair1, 0, c_info->WIN);
        if (run_mode->AGGREGATE)
        {
            res_time = MPI_Wtime();
            for (i = 0; i < iterations->n_sample; i++)
            {
                ierr = MPI_Get((void*)(recv+i%iterations->r_cache_iter*iterations->r_offs), 
                                r_num, c_info->r_data_type, c_info->pair1, 
                                i%iterations->s_cache_iter*iterations->s_offs,
                                r_num, c_info->s_data_type, c_info->WIN);
                MPI_ERRHAND(ierr);
            }
            ierr = MPI_Win_flush_local(c_info->pair1, c_info->WIN);
            MPI_ERRHAND(ierr);
            res_time = (MPI_Wtime() - res_time)/iterations->n_sample;
        }    
        else if (!run_mode->AGGREGATE)    
        {
            res_time = MPI_Wtime();
            for (i = 0; i < iterations->n_sample; i++)
            {

                ierr = MPI_Get((void*)(recv+i%iterations->r_cache_iter*iterations->r_offs), 
                                r_num, c_info->r_data_type, c_info->pair1, 
                                i%iterations->s_cache_iter*iterations->s_offs,
                                r_num, c_info->s_data_type, c_info->WIN);
                MPI_ERRHAND(ierr);
                ierr = MPI_Win_flush_local(c_info->pair1, c_info->WIN);
                MPI_ERRHAND(ierr);
            }
            res_time = (MPI_Wtime() - res_time)/iterations->n_sample;
        }

        MPI_Win_unlock(c_info->pair1, c_info->WIN);
    }     
   
    /* Synchronize target and origin processes */
    MPI_Barrier(c_info->communicator);

#ifdef CHECK
    if (c_info->rank == c_info->pair0)
    {
         /* Local completion of MPI_Get guarantees that recv buffer already contains target data,
          * so let's check the result */
         for(i = 0; ITER_MIN(iterations); i++)
         {
             CHK_DIFF("MPI_Get",c_info, (void*)(recv+i%iterations->r_cache_iter*iterations->r_offs), 
                      0, size, size, asize, get, 0, iterations->n_sample, i, c_info->pair1, &defect);
             
         }
    }     
#endif     
    
    *time = res_time; 
    return;
}

/* Implements "get_all_local" benchmark. One process gets some data
 * from all other processes and make sure of completion by 
 * MPI_Win_flush_local_all call 
 * */
void IMB_rma_get_all_local (struct comm_info* c_info, int size, 
                            struct iter_schedule* iterations, 
                            MODES run_mode, double* time)
{
    double res_time = -1.;
    int target = 0;
    int peer = 0;
    Type_Size r_size;
    int  r_num;
    int i;
    char *recv = (char *)c_info->r_buffer;
    ierr = 0;

    if (c_info->rank < 0)
    {
        *time = res_time;
        return;
    } 

    MPI_Type_size(c_info->r_data_type,&r_size);
    r_num=size/r_size;

    for(i=0; i<N_BARR; i++) MPI_Barrier(c_info->communicator);
    
    if (c_info->rank == 0)
    {    
        MPI_Win_lock_all(0, c_info->WIN);
        
        res_time = MPI_Wtime();
        for (i = 0; i < iterations->n_sample; i++)
        {
            for (peer = 0; peer < c_info->num_procs; peer++)
            {
                /* choose different target for each process to avoid congestion */
                target = (peer + c_info->rank)%c_info->num_procs;
                if (target == c_info->rank)
                {
                    continue; /* do not get from itself*/
                }    
                
                ierr = MPI_Get((void*)(recv+i%iterations->r_cache_iter*iterations->r_offs), 
                                r_num, c_info->r_data_type, target, 
                                i%iterations->s_cache_iter*iterations->s_offs,
                                r_num, c_info->s_data_type, c_info->WIN);
                MPI_ERRHAND(ierr);
            } 
        }    
        ierr = MPI_Win_flush_local_all(c_info->WIN);
        MPI_ERRHAND(ierr);
        res_time = (MPI_Wtime() - res_time)/iterations->n_sample;
    
        MPI_Win_unlock_all(c_info->WIN);
    }     
   
    /* Synchronize origin and target processes */
    MPI_Barrier(c_info->communicator);
    
    *time = res_time; 
    return;
}

/* Implements "Exchange_get" benchmark. Each process gets some data
 * from two neighbor processes
 * */
void IMB_rma_exchange_get (struct comm_info* c_info, int size, 
                           struct iter_schedule* iterations, 
                           MODES run_mode, double* time)
{
    double res_time = -1.;
    int left  = -1;
    int right = -1;
    Type_Size r_size;
    int r_num;
    int i;
    char *recv = (char *)c_info->r_buffer;
#ifdef CHECK 
    defect = 0;
#endif
    ierr = 0;
    
    if (c_info->rank < 0)
    {
        *time = res_time;
        return;
    } 
    
    MPI_Type_size(c_info->r_data_type,&r_size);
    r_num=size/r_size;
   
    left  = (c_info->rank == 0) ? c_info->num_procs - 1 : c_info->rank - 1;
    right = (c_info->rank + 1)%c_info->num_procs;     

    for(i=0; i<N_BARR; i++) MPI_Barrier(c_info->communicator);
    
    if (left != right)
    {    
        MPI_Win_lock(MPI_LOCK_SHARED, left,  0, c_info->WIN);
        MPI_Win_lock(MPI_LOCK_SHARED, right, 0, c_info->WIN);
    }
    else
    {
        /* Just two processes in the chain. Both messages will come
         * to the one peer */
        MPI_Win_lock(MPI_LOCK_SHARED, left,  0, c_info->WIN);
    }    

    res_time = MPI_Wtime();
    for (i = 0; i < iterations->n_sample; i++)
    {
        ierr = MPI_Get((void*)(recv+i%iterations->r_cache_iter*iterations->r_offs), 
                               r_num, c_info->r_data_type, right, 
                               i%iterations->s_cache_iter*iterations->s_offs,
                               r_num, c_info->s_data_type, c_info->WIN);
        MPI_ERRHAND(ierr);
        
        ierr = MPI_Get((void*)(recv + size + i%iterations->r_cache_iter*iterations->r_offs), 
                               r_num, c_info->r_data_type, left, 
                               size + i%iterations->s_cache_iter*iterations->s_offs,
                               r_num, c_info->s_data_type, c_info->WIN);
        MPI_ERRHAND(ierr);
       
        if (left != right)
        {    
            ierr = MPI_Win_flush(left, c_info->WIN);
            MPI_ERRHAND(ierr);
        
            ierr = MPI_Win_flush(right, c_info->WIN);
            MPI_ERRHAND(ierr);
        }
        else
        {
            ierr = MPI_Win_flush(left, c_info->WIN);
            MPI_ERRHAND(ierr);
        }    
    }
    res_time = (MPI_Wtime() - res_time)/iterations->n_sample;
    if (left != right)
    {    
        MPI_Win_unlock(left, c_info->WIN);
        MPI_Win_unlock(right, c_info->WIN);
    }
    else
    {
        MPI_Win_unlock(left, c_info->WIN);
    }    
      
    /* Synchronize target and origin processes */
    MPI_Barrier(c_info->communicator);

#ifdef CHECK
    for(i = 0; i < ITER_MIN(iterations); i++)
    {
        CHK_DIFF("MPI_Get",c_info, (void*)(recv+size+i%iterations->r_cache_iter*iterations->r_offs), 
                  size, size, size, asize, get, 0, iterations->n_sample, i, left , &defect);
        
        CHK_DIFF("MPI_Get",c_info, (void*)(recv+i%iterations->r_cache_iter*iterations->r_offs), 
                  0, size, size, asize, get, 0, iterations->n_sample, i, right , &defect);
    }
#endif     

    *time = res_time; 
    return;
}
