/*
 * The function prototypes and constants defined within this and other
 * included files are based on the MPI-1.2 and MPI-2.0 standards:
 *   “MPI: A Message-Passing Interface Standard, June 12, 1995”
 *          (MPI-1.1) from the MPI-1 Forum, and
 *   “MPI-2: Extensions to the Message-Passing Interface, July, 1997”
 * respectively, found at the MPI-2 Forum, along with errata documents 
 * also at the MPI Forum.
 *
 */
#ifndef MPI_H
#define MPI_H

#if defined(__cplusplus)
extern "C" {
#endif

#if !defined(DLLDEF)
#ifndef SERVER_WIN64
#define DLLDEF
#else
#ifdef BUILDING_MPI
#define DLLDEF __declspec(dllexport)
#else
#define DLLDEF __declspec(dllimport)
#endif

// Doesn't like the cast of the (void*)
#pragma warning(disable:144)

#endif
#endif

#define MPI_VERSION 3
#define MPI_SUBVERSION 0
#define MPIX_HAVE_MPI_STATUS_GETSET 1

/* We redefine all MPI constants to be ISC constants */
#include "mpi2isc.h"

/* The following MPIX_Status_{get,set} functions
 * allow libraries such as mpi4py to utilize these
 * to access, i.e. read or write the known MPI Status
 * struture elements without having to understand the
 * actual structure size and layout of each native
 * MPI implementation.
 */
DLLDEF int MPIX_Status_set_source(MPI_Status *, int);
DLLDEF int MPIX_Status_get_source(MPI_Status *, int *);
DLLDEF int MPIX_Status_set_tag(MPI_Status *, int);
DLLDEF int MPIX_Status_get_tag(MPI_Status *, int *);
DLLDEF int MPIX_Status_set_error(MPI_Status *, int);
DLLDEF int MPIX_Status_get_error(MPI_Status *, int *);

DLLDEF int MPI_Send(void*, int, MPI_Datatype, int, int, MPI_Comm);
DLLDEF int MPI_Recv(void*, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);
DLLDEF int MPI_Get_count(MPI_Status *, MPI_Datatype, int *);
DLLDEF int MPI_Bsend(void*, int, MPI_Datatype, int, int, MPI_Comm);
DLLDEF int MPI_Ssend(void*, int, MPI_Datatype, int, int, MPI_Comm);
DLLDEF int MPI_Rsend(void*, int, MPI_Datatype, int, int, MPI_Comm);
DLLDEF int MPI_Buffer_attach( void*, int);
DLLDEF int MPI_Buffer_detach( void*, int *);
DLLDEF int MPI_Isend(void*, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Ibsend(void*, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Issend(void*, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Irsend(void*, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Irecv(void*, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Wait(MPI_Request *, MPI_Status *);
DLLDEF int MPI_Test(MPI_Request *, int *, MPI_Status *);
DLLDEF int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status);
DLLDEF int MPI_Request_free(MPI_Request *);
DLLDEF int MPI_Waitany(int, MPI_Request *, int *, MPI_Status *);
DLLDEF int MPI_Testany(int, MPI_Request *, int *, int *, MPI_Status *);
DLLDEF int MPI_Waitall(int, MPI_Request *, MPI_Status *);
DLLDEF int MPI_Testall(int, MPI_Request *, int *, MPI_Status *);
DLLDEF int MPI_Waitsome(int, MPI_Request *, int *, int *, MPI_Status *);
DLLDEF int MPI_Testsome(int, MPI_Request *, int *, int *, MPI_Status *);
DLLDEF int MPI_Iprobe(int, int, MPI_Comm, int *, MPI_Status *);
DLLDEF int MPI_Probe(int, int, MPI_Comm, MPI_Status *);
DLLDEF int MPI_Cancel(MPI_Request *);
DLLDEF int MPI_Test_cancelled(MPI_Status *, int *);
DLLDEF int MPI_Send_init(void*, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Bsend_init(void*, int, MPI_Datatype, int,int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Ssend_init(void*, int, MPI_Datatype, int,int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Rsend_init(void*, int, MPI_Datatype, int,int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Recv_init(void*, int, MPI_Datatype, int,int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Start(MPI_Request *);
DLLDEF int MPI_Startall(int, MPI_Request *);
DLLDEF int MPI_Sendrecv(void *, int, MPI_Datatype,int, int, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);
DLLDEF int MPI_Sendrecv_replace(void*, int, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Status *);
DLLDEF int MPI_Type_contiguous(int, MPI_Datatype, MPI_Datatype *);
DLLDEF int MPI_Type_vector(int, int, int, MPI_Datatype, MPI_Datatype *);
DLLDEF int MPI_Type_hvector(int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);
DLLDEF int MPI_Type_indexed(int, int *, int *, MPI_Datatype, MPI_Datatype *);
DLLDEF int MPI_Type_hindexed(int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);
DLLDEF int MPI_Type_create_indexed_block (int , int , int *, MPI_Datatype , MPI_Datatype *);
DLLDEF int MPI_Type_create_hindexed_block (int , int , MPI_Aint *, MPI_Datatype , MPI_Datatype *);  
DLLDEF int MPI_Type_create_resized (MPI_Datatype , MPI_Aint , MPI_Aint , MPI_Datatype *);
DLLDEF int MPI_Type_struct(int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);
DLLDEF int MPI_Address(void*, MPI_Aint *);
DLLDEF int MPI_Type_extent(MPI_Datatype, MPI_Aint *);
DLLDEF int MPI_Type_get_extent(MPI_Datatype, MPI_Aint *, MPI_Aint *);
DLLDEF int MPI_Type_get_extent_x(MPI_Datatype, MPI_Count *, MPI_Count *);
DLLDEF int MPI_Type_size(MPI_Datatype, int *);
DLLDEF int MPI_Type_size_x(MPI_Datatype, MPI_Count *);
DLLDEF int MPI_Type_lb(MPI_Datatype, MPI_Aint *);
DLLDEF int MPI_Type_ub(MPI_Datatype, MPI_Aint *);
DLLDEF int MPI_Type_commit(MPI_Datatype *);
DLLDEF int MPI_Type_free(MPI_Datatype *);
DLLDEF int MPI_Get_elements(MPI_Status *, MPI_Datatype, int *);
DLLDEF int MPI_Get_elements_x(MPI_Status *, MPI_Datatype, MPI_Count *);
DLLDEF int MPI_Pack(void*, int, MPI_Datatype, void *, int, int *,  MPI_Comm);
DLLDEF int MPI_Unpack(void*, int, int *, void *, int, MPI_Datatype, MPI_Comm);
DLLDEF int MPI_Pack_size(int, MPI_Datatype, MPI_Comm, int *);
DLLDEF int MPI_Barrier(MPI_Comm );
DLLDEF int MPI_Bcast(void*, int, MPI_Datatype, int, MPI_Comm );
DLLDEF int MPI_Gather(void* , int, MPI_Datatype, void*, int, MPI_Datatype, int, MPI_Comm);
DLLDEF int MPI_Gatherv(void* , int, MPI_Datatype, void*, int *, int *, MPI_Datatype, int, MPI_Comm);
DLLDEF int MPI_Scatter(void* , int, MPI_Datatype, void*, int, MPI_Datatype, int, MPI_Comm);
DLLDEF int MPI_Scatterv(void* , int *, int *,  MPI_Datatype, void*, int, MPI_Datatype, int, MPI_Comm);
DLLDEF int MPI_Allgather(void* , int, MPI_Datatype, void*, int, MPI_Datatype, MPI_Comm);
DLLDEF int MPI_Allgatherv(void* , int, MPI_Datatype, void*, int *, int *, MPI_Datatype, MPI_Comm);
DLLDEF int MPI_Alltoall(void* , int, MPI_Datatype, void*, int, MPI_Datatype, MPI_Comm);
DLLDEF int MPI_Alltoallv(void* , int *, int *, MPI_Datatype, void*, int *, int *, MPI_Datatype, MPI_Comm);
DLLDEF int MPI_Reduce(void* , void*, int, MPI_Datatype, MPI_Op, int, MPI_Comm);
DLLDEF int MPI_Reduce_local(void* , void*, int, MPI_Datatype, MPI_Op);
DLLDEF int MPI_Op_create(MPI_User_function *, int, MPI_Op *);
DLLDEF int MPI_Op_free( MPI_Op *);
DLLDEF int MPI_Allreduce(void* , void*, int, MPI_Datatype, MPI_Op, MPI_Comm);
DLLDEF int MPI_Reduce_scatter(void* , void*, int *, MPI_Datatype, MPI_Op, MPI_Comm);
DLLDEF int MPI_Scan(void* , void*, int, MPI_Datatype, MPI_Op, MPI_Comm );
DLLDEF int MPI_Group_size(MPI_Group, int *);
DLLDEF int MPI_Group_rank(MPI_Group, int *);
DLLDEF int MPI_Group_translate_ranks (MPI_Group, int, int *, MPI_Group, int *);
DLLDEF int MPI_Group_compare(MPI_Group, MPI_Group, int *);
DLLDEF int MPI_Comm_group(MPI_Comm, MPI_Group *);
DLLDEF int MPI_Group_union(MPI_Group, MPI_Group, MPI_Group *);
DLLDEF int MPI_Group_intersection(MPI_Group, MPI_Group, MPI_Group *);
DLLDEF int MPI_Group_difference(MPI_Group, MPI_Group, MPI_Group *);
DLLDEF int MPI_Group_incl(MPI_Group, int, int *, MPI_Group *);
DLLDEF int MPI_Group_excl(MPI_Group, int, int *, MPI_Group *);
DLLDEF int MPI_Group_range_incl(MPI_Group, int, int [][3], MPI_Group *);
DLLDEF int MPI_Group_range_excl(MPI_Group, int, int [][3], MPI_Group *);
DLLDEF int MPI_Group_free(MPI_Group *);
DLLDEF int MPI_Comm_size(MPI_Comm, int *);
DLLDEF int MPI_Comm_rank(MPI_Comm, int *);
DLLDEF int MPI_Comm_compare(MPI_Comm, MPI_Comm, int *);
DLLDEF int MPI_Comm_dup(MPI_Comm, MPI_Comm *);
DLLDEF int MPI_Comm_dup_with_info(MPI_Comm, MPI_Info, MPI_Comm *);
DLLDEF int MPI_Comm_set_info(MPI_Comm, MPI_Info);
DLLDEF int MPI_Comm_get_info(MPI_Comm, MPI_Info *);  
DLLDEF int MPI_Comm_create(MPI_Comm, MPI_Group, MPI_Comm *);
DLLDEF int MPI_Comm_create_group(MPI_Comm, MPI_Group, int, MPI_Comm *);
DLLDEF int MPI_Comm_split_type(MPI_Comm, int, int, int, MPI_Comm *);
DLLDEF int MPI_Comm_split(MPI_Comm, int, int, MPI_Comm *);
DLLDEF int MPI_Comm_free(MPI_Comm *);
DLLDEF int MPI_Comm_test_inter(MPI_Comm, int *);
DLLDEF int MPI_Comm_remote_size(MPI_Comm, int *);
DLLDEF int MPI_Comm_remote_group(MPI_Comm, MPI_Group *);
DLLDEF int MPI_Intercomm_create(MPI_Comm, int, MPI_Comm, int, int, MPI_Comm * );
DLLDEF int MPI_Intercomm_merge(MPI_Comm, int, MPI_Comm *);
DLLDEF int MPI_Keyval_create(MPI_Copy_function *, MPI_Delete_function *, int *, void*);
DLLDEF int MPI_Keyval_free(int *);
DLLDEF int MPI_Attr_put(MPI_Comm, int, void*);
DLLDEF int MPI_Attr_get(MPI_Comm, int, void *, int *);
DLLDEF int MPI_Attr_delete(MPI_Comm, int);
DLLDEF int MPI_Topo_test(MPI_Comm, int *);
DLLDEF int MPI_Cart_create(MPI_Comm, int, int *, int *, int, MPI_Comm *);
DLLDEF int MPI_Dims_create(int, int, int *);
DLLDEF int MPI_Graph_create(MPI_Comm, int, int *, int *, int, MPI_Comm *);
DLLDEF int MPI_Graphdims_get(MPI_Comm, int *, int *);
DLLDEF int MPI_Graph_get(MPI_Comm, int, int, int *, int *);
DLLDEF int MPI_Cartdim_get(MPI_Comm, int *);
DLLDEF int MPI_Cart_get(MPI_Comm, int, int *, int *, int *);
DLLDEF int MPI_Cart_rank(MPI_Comm, int *, int *);
DLLDEF int MPI_Cart_coords(MPI_Comm, int, int, int *);
DLLDEF int MPI_Graph_neighbors_count(MPI_Comm, int, int *);
DLLDEF int MPI_Graph_neighbors(MPI_Comm, int, int, int *);
DLLDEF int MPI_Cart_shift(MPI_Comm, int, int, int *, int *);
DLLDEF int MPI_Cart_sub(MPI_Comm, int *, MPI_Comm *);
DLLDEF int MPI_Cart_map(MPI_Comm, int, int *, int *, int *);
DLLDEF int MPI_Graph_map(MPI_Comm, int, int *, int *, int *);
DLLDEF int MPI_Get_processor_name(char *, int *);
DLLDEF int MPI_Get_version(int *, int *);
DLLDEF int MPI_Get_library_version(char *, int *);
DLLDEF int MPI_Errhandler_create(MPI_Handler_function *, MPI_Errhandler *);
DLLDEF int MPI_Errhandler_set(MPI_Comm, MPI_Errhandler);
DLLDEF int MPI_Errhandler_get(MPI_Comm, MPI_Errhandler *);
DLLDEF int MPI_Errhandler_free(MPI_Errhandler *);

DLLDEF int MPI_Error_string(int, char *, int *);
DLLDEF int MPI_Error_class(int, int *);
DLLDEF double MPI_Wtime(void);
DLLDEF double MPI_Wtick(void);
DLLDEF int MPI_Init(int *, char ***);
DLLDEF int MPI_Finalize(void);
DLLDEF int MPI_Initialized(int *);
DLLDEF int MPI_Abort(MPI_Comm, int);

/* MPI-2 functions */

/* Process Creation and Management */
DLLDEF int MPI_Pcontrol(const int level, ...);
DLLDEF int MPI_Close_port(char *);
DLLDEF int MPI_Comm_accept(char *, MPI_Info, int, MPI_Comm, MPI_Comm *);
DLLDEF int MPI_Comm_connect(char *, MPI_Info, int, MPI_Comm, MPI_Comm *);
DLLDEF int MPI_Comm_disconnect(MPI_Comm *);
DLLDEF int MPI_Comm_get_parent(MPI_Comm *);
DLLDEF int MPI_Comm_join(int, MPI_Comm *);
DLLDEF int MPI_Comm_spawn(char *, char *[], int, MPI_Info, int , MPI_Comm, MPI_Comm *, int []);
DLLDEF int MPI_Comm_spawn_multiple(int, char *[], char **[], int [], MPI_Info [], int,
			    MPI_Comm, MPI_Comm *, int []); 
DLLDEF int MPI_Lookup_name(char *, MPI_Info, char *);
DLLDEF int MPI_Open_port(MPI_Info, char *);
DLLDEF int MPI_Publish_name(char *, MPI_Info, char *);
DLLDEF int MPI_Unpublish_name(char *, MPI_Info, char *);

/* One-Sided Communications */
DLLDEF int MPI_Accumulate(void *, int, MPI_Datatype, int, MPI_Aint, int,
		   MPI_Datatype,  MPI_Op, MPI_Win);

DLLDEF int MPI_Get_accumulate (void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
	    void *result_addr, int result_count, MPI_Datatype result_datatype,
            int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);
DLLDEF int MPI_Fetch_and_op (void *origin_addr, void *result_addr, MPI_Datatype datatype,
            int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win);
DLLDEF int MPI_Compare_and_swap (void *origin_addr, void *compare_addr, void *result_addr, MPI_Datatype datatype,
            int target_rank, MPI_Aint target_disp, MPI_Win win);
DLLDEF int MPI_Get(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
	    MPI_Win);
DLLDEF int MPI_Put(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
	    MPI_Win);
DLLDEF int MPI_Win_complete(MPI_Win);
DLLDEF int MPI_Win_create(void *, MPI_Aint, int, MPI_Info, MPI_Comm, MPI_Win *);
DLLDEF int MPI_Win_fence(int, MPI_Win);
DLLDEF int MPI_Win_free(MPI_Win *);
DLLDEF int MPI_Win_get_group(MPI_Win, MPI_Group *);
DLLDEF int MPI_Win_lock(int, int, int, MPI_Win);
DLLDEF int MPI_Win_lock_all(int, MPI_Win);
DLLDEF int MPI_Win_post(MPI_Group, int, MPI_Win);
DLLDEF int MPI_Win_start(MPI_Group, int, MPI_Win);
DLLDEF int MPI_Win_test(MPI_Win, int *);
DLLDEF int MPI_Win_unlock(int, MPI_Win);
DLLDEF int MPI_Win_unlock_all(MPI_Win);
DLLDEF int MPI_Win_wait(MPI_Win);
DLLDEF int MPI_Win_flush(int, MPI_Win);
DLLDEF int MPI_Win_flush_all(MPI_Win);
DLLDEF int MPI_Win_flush_local(int, MPI_Win);
DLLDEF int MPI_Win_flush_local_all(MPI_Win);

DLLDEF int MPI_Alloc_mem(MPI_Aint, MPI_Info, void *);
DLLDEF int MPI_Free_mem(void *);
 
/* Extended Collective Operations */
DLLDEF int MPI_Alltoallw(void *, int [], int [], MPI_Datatype [], void *, int [],
		  int [], MPI_Datatype [], MPI_Comm);
DLLDEF int MPI_Exscan(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm) ;
 
/* Nonblocking Collectives */
DLLDEF int MPI_Ibarrier(MPI_Comm, MPI_Request *);
DLLDEF int MPI_Ibcast(void*, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Igather(void* , int, MPI_Datatype, void*, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Iscatter(void* , int, MPI_Datatype, void*, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Igatherv(void *, int, MPI_Datatype, void *,int [], int[], MPI_Datatype, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Iscatter(void* , int, MPI_Datatype, void*, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Iscatterv(void* , int *, int *,  MPI_Datatype, void*, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Iallgather(void* , int, MPI_Datatype, void*, int, MPI_Datatype, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Iallgatherv(void* , int, MPI_Datatype, void*, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Ialltoall(void* , int, MPI_Datatype, void*, int, MPI_Datatype, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Ialltoallv(void* , int *, int *, MPI_Datatype, void*, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Ireduce(void* , void*, int, MPI_Datatype, MPI_Op, int, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Ialltoallw(void *, int [], int [], MPI_Datatype [], void *, int [], int [], MPI_Datatype [], MPI_Comm, MPI_Request *);
DLLDEF int MPI_Iexscan(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *) ;
DLLDEF int MPI_Iallreduce(void* , void*, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Ireduce_scatter(void* , void*, int *, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);
DLLDEF int MPI_Iscan(void* , void*, int, MPI_Datatype, MPI_Op, MPI_Comm , MPI_Request *);
DLLDEF int MPI_Ireduce_scatter_block(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);


/* External Interfaces */
DLLDEF int MPI_Add_error_class(int *);
DLLDEF int MPI_Add_error_code(int, int *);
DLLDEF int MPI_Add_error_string(int, char *);
DLLDEF int MPI_Comm_call_errhandler(MPI_Comm, int);
DLLDEF int MPI_Comm_create_errhandler (MPI_Comm_errhandler_function *, MPI_Errhandler *);
DLLDEF int MPI_Comm_get_errhandler (MPI_Comm , MPI_Errhandler *);
DLLDEF int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *,
                           MPI_Comm_delete_attr_function *, int *, void *);
DLLDEF int MPI_Comm_delete_attr(MPI_Comm, int);
DLLDEF int MPI_Comm_free_keyval(int *);
DLLDEF int MPI_Comm_get_attr(MPI_Comm, int, void *, int *);
DLLDEF int MPI_Comm_get_name(MPI_Comm, char *, int *);
DLLDEF int MPI_Comm_set_attr(MPI_Comm, int, void *);
DLLDEF int MPI_Comm_set_name(MPI_Comm, char *);
DLLDEF int MPI_Comm_set_errhandler(MPI_Comm , MPI_Errhandler);
DLLDEF int MPI_File_create_errhandler (MPI_File_errhandler_function *, MPI_Errhandler *);
DLLDEF int MPI_File_get_errhandler(MPI_File , MPI_Errhandler *);
DLLDEF int MPI_File_set_errhandler (MPI_File , MPI_Errhandler );
DLLDEF int MPI_File_call_errhandler(MPI_File, int);
DLLDEF int MPI_Finalized (int *);
DLLDEF int MPI_Get_address (void *, MPI_Aint *);
DLLDEF int MPI_Grequest_complete(MPI_Request);
DLLDEF int MPI_Grequest_start (MPI_Grequest_query_function *, 
                               MPI_Grequest_free_function *,
			       MPI_Grequest_cancel_function *,
			       void *, 
			       MPI_Request *);
DLLDEF int MPI_Init_thread(int *, char ***, int, int *);
DLLDEF int MPI_Is_thread_main(int *);
DLLDEF int MPI_Info_dup (MPI_Info , MPI_Info *);
DLLDEF int MPI_Info_get (MPI_Info , char *, int , char *, int *);
DLLDEF int MPI_Info_get_nkeys (MPI_Info , int *);
DLLDEF int MPI_Info_get_nthkey (MPI_Info , int, char *);
DLLDEF int MPI_Info_create (MPI_Info *);
DLLDEF int MPI_Info_delete (MPI_Info, char *);
DLLDEF int MPI_Info_set(MPI_Info, char *, char *);
DLLDEF int MPI_Info_free(MPI_Info *);
DLLDEF int MPI_Info_get_valuelen (MPI_Info , char *, int *, int *);


DLLDEF int MPI_Query_thread(int *);
DLLDEF int MPI_Status_set_cancelled(MPI_Status *, int);
DLLDEF int MPI_Status_set_elements(MPI_Status *, MPI_Datatype, int);
DLLDEF int MPI_Status_set_elements_x(MPI_Status *, MPI_Datatype, MPI_Count);

DLLDEF int MPI_Type_create_keyval(MPI_Type_copy_attr_function *, MPI_Type_delete_attr_function *, int *, void *);
DLLDEF int MPI_Type_create_hindexed (int , int [], MPI_Aint [], MPI_Datatype , MPI_Datatype *);
DLLDEF int MPI_Type_create_hvector (int, int, MPI_Aint , MPI_Datatype , MPI_Datatype *);
DLLDEF int MPI_Type_create_struct (int , int [], MPI_Aint [], MPI_Datatype [], MPI_Datatype *);

DLLDEF int MPI_Type_delete_attr(MPI_Datatype, int);
DLLDEF int MPI_Type_dup(MPI_Datatype, MPI_Datatype *);
DLLDEF int MPI_Type_free_keyval(int *);
DLLDEF int MPI_Type_get_attr(MPI_Datatype, int, void *, int *);
DLLDEF int MPI_Type_get_contents(MPI_Datatype, int, int, int, int [], MPI_Aint [],
                          MPI_Datatype []);
DLLDEF int MPI_Type_create_f90_real (int , int, MPI_Datatype *);
DLLDEF int MPI_Type_create_f90_integer (int , MPI_Datatype *);
DLLDEF int MPI_Type_create_f90_complex (int , int , MPI_Datatype *);
DLLDEF int MPI_Type_get_true_extent (MPI_Datatype , MPI_Aint *, MPI_Aint *);
DLLDEF int MPI_Type_get_true_extent_x (MPI_Datatype , MPI_Count *, MPI_Count *);
DLLDEF int MPI_Type_get_envelope(MPI_Datatype, int *, int *, int *, int *);
DLLDEF int MPI_Type_get_name(MPI_Datatype, char *, int *);
DLLDEF int MPI_Type_set_attr(MPI_Datatype, int, void *);
DLLDEF int MPI_Type_set_name(MPI_Datatype, char *);
DLLDEF int MPI_Type_match_size( int, int, MPI_Datatype *);
DLLDEF int MPI_Unpack_external(char *, void *, MPI_Aint , MPI_Aint *, void *, int , MPI_Datatype);
DLLDEF int MPI_Pack_external (char *, void *, int , MPI_Datatype , void *, MPI_Aint , MPI_Aint *);
DLLDEF int MPI_Pack_external_size (char *, int , MPI_Datatype , MPI_Aint *);

DLLDEF int MPI_Win_call_errhandler(MPI_Win, int);
DLLDEF int MPI_Win_create_errhandler (MPI_Win_errhandler_function *, MPI_Errhandler *);
DLLDEF int MPI_Win_set_errhandler (MPI_Win , MPI_Errhandler );
DLLDEF int MPI_Win_get_errhandler (MPI_Win , MPI_Errhandler *);
DLLDEF int MPI_Win_create_keyval(MPI_Win_copy_attr_function *,
                         MPI_Win_delete_attr_function *, int *, void *);
DLLDEF int MPI_Win_delete_attr(MPI_Win, int);
DLLDEF int MPI_Win_free_keyval(int *);
DLLDEF int MPI_Win_get_attr(MPI_Win, int, void *, int *);
DLLDEF int MPI_Win_get_name(MPI_Win, char *, int *);
DLLDEF int MPI_Win_set_attr(MPI_Win, int, void *);
DLLDEF int MPI_Win_set_name(MPI_Win, char *);

/* FIXME!! C and Fortran representations are simple integers so these SHOULD be simple cast operations
 * At this point however, they're implemented as real functions 8-(
 */
DLLDEF MPI_Fint MPI_Comm_c2f(MPI_Comm);
DLLDEF MPI_Fint MPI_Type_c2f(MPI_Datatype);
DLLDEF MPI_Fint MPI_Group_c2f(MPI_Group);
DLLDEF MPI_Fint MPI_Op_c2f(MPI_Op);
DLLDEF MPI_Fint MPI_Request_c2f(MPI_Request);
DLLDEF MPI_Fint MPI_Win_c2f(MPI_Win);
DLLDEF MPI_Fint MPI_Info_c2f(MPI_Info);
DLLDEF MPI_Fint MPI_Errhandler_c2f(MPI_Errhandler);
DLLDEF MPI_Fint MPI_Message_c2f(MPI_Message);

DLLDEF MPI_Comm MPI_Comm_f2c(MPI_Fint);
DLLDEF MPI_Datatype MPI_Type_f2c(MPI_Fint);
DLLDEF MPI_Group MPI_Group_f2c(MPI_Fint);
DLLDEF MPI_Op MPI_Op_f2c(MPI_Fint);
DLLDEF MPI_Request MPI_Request_f2c(MPI_Fint);
DLLDEF MPI_Win MPI_Win_f2c(MPI_Fint);
DLLDEF MPI_Info MPI_Info_f2c(MPI_Fint);
DLLDEF MPI_Errhandler MPI_Errhandler_f2c(MPI_Fint);
DLLDEF MPI_Message MPI_Message_f2c(MPI_Fint);


/* MPI-IO File related functions */
/* Section 9.2 */
DLLDEF int MPI_File_open(MPI_Comm, char *, int, MPI_Info, MPI_File *);
DLLDEF int MPI_File_close(MPI_File *);
DLLDEF int MPI_File_delete(char *, MPI_Info);
DLLDEF int MPI_File_set_size(MPI_File, MPI_Offset);
DLLDEF int MPI_File_preallocate(MPI_File, MPI_Offset);
DLLDEF int MPI_File_get_size(MPI_File, MPI_Offset *);
DLLDEF int MPI_File_get_group(MPI_File, MPI_Group *);
DLLDEF int MPI_File_get_amode(MPI_File, int *);
DLLDEF int MPI_File_set_info(MPI_File, MPI_Info);
DLLDEF int MPI_File_get_info(MPI_File, MPI_Info *);
/* Section 9.3 */
DLLDEF int MPI_File_set_view(MPI_File, MPI_Offset, MPI_Datatype,
	         MPI_Datatype, char *, MPI_Info);
DLLDEF int MPI_File_get_view(MPI_File, MPI_Offset *,
                 MPI_Datatype *, MPI_Datatype *, char *);

/* Section 9.4.2 */
DLLDEF int MPI_File_read_at(MPI_File, MPI_Offset, void *,
	      int, MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_read_at_all(MPI_File, MPI_Offset, void *,
	      int, MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_write_at(MPI_File, MPI_Offset, void *,
	      int, MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_write_at_all(MPI_File, MPI_Offset, void *,
	      int, MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_iread_at(MPI_File, MPI_Offset, void *,
	      int, MPI_Datatype, MPIO_Request *);
DLLDEF int MPI_File_iwrite_at(MPI_File, MPI_Offset, void *,
	      int, MPI_Datatype, MPIO_Request *);

/* Section 9.4.3 */
DLLDEF int MPI_File_read(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_read_all(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_write(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_write_all(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_iread(MPI_File, void *, int, MPI_Datatype, MPIO_Request *);
DLLDEF int MPI_File_iwrite(MPI_File, void *, int, MPI_Datatype, MPIO_Request *);

DLLDEF int MPI_File_seek(MPI_File, MPI_Offset, int);
DLLDEF int MPI_File_get_position(MPI_File, MPI_Offset *);
DLLDEF int MPI_File_get_byte_offset(MPI_File, MPI_Offset, MPI_Offset *);

/* Section 9.4.4 */
DLLDEF int MPI_File_read_shared(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_write_shared(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_iread_shared(MPI_File, void *, int, MPI_Datatype, MPIO_Request *);
DLLDEF int MPI_File_iwrite_shared(MPI_File, void *, int,
			   MPI_Datatype, MPIO_Request *);
DLLDEF int MPI_File_read_ordered(MPI_File, void *, int,
                          MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_write_ordered(MPI_File, void *, int,
                           MPI_Datatype, MPI_Status *);
DLLDEF int MPI_File_seek_shared(MPI_File, MPI_Offset, int);
DLLDEF int MPI_File_get_position_shared(MPI_File, MPI_Offset *);

/* Section 9.4.5 */
DLLDEF int MPI_File_read_at_all_begin(MPI_File, MPI_Offset, void *,
                               int, MPI_Datatype);
DLLDEF int MPI_File_read_at_all_end(MPI_File, void *, MPI_Status *);
DLLDEF int MPI_File_write_at_all_begin(MPI_File, MPI_Offset, void *,
                                int, MPI_Datatype);
DLLDEF int MPI_File_write_at_all_end(MPI_File, void *, MPI_Status *);
DLLDEF int MPI_File_read_all_begin(MPI_File, void *, int, MPI_Datatype);
DLLDEF int MPI_File_read_all_end(MPI_File, void *, MPI_Status *);
DLLDEF int MPI_File_write_all_begin(MPI_File, void *, int, MPI_Datatype);
DLLDEF int MPI_File_write_all_end(MPI_File, void *, MPI_Status *);
DLLDEF int MPI_File_read_ordered_begin(MPI_File, void *, int, MPI_Datatype);
DLLDEF int MPI_File_read_ordered_end(MPI_File, void *, MPI_Status *);
DLLDEF int MPI_File_write_ordered_begin(MPI_File, void *, int, MPI_Datatype);
DLLDEF int MPI_File_write_ordered_end(MPI_File, void *, MPI_Status *);

/* Section 9.5.1 */
DLLDEF int MPI_File_get_type_extent(MPI_File, MPI_Datatype, MPI_Aint *);

/* Section 9.5.3 */
DLLDEF int MPI_Register_datarep(char *,
			 MPI_Datarep_conversion_function *,
			 MPI_Datarep_conversion_function *,
			 MPI_Datarep_extent_function *,
			 void *);

/* Section 9.6.1 */
DLLDEF int MPI_File_set_atomicity(MPI_File, int);
DLLDEF int MPI_File_get_atomicity(MPI_File, int *);
DLLDEF int MPI_File_sync(MPI_File);

/* Section 4.14.4 */
DLLDEF int MPI_Type_create_subarray(int, int *, int *, int *, int,
                      MPI_Datatype, MPI_Datatype *);

/* Section 4.14.5 */
DLLDEF int MPI_Type_create_darray(int, int, int,
                    int *, int *, int *, int *, 
                    int, MPI_Datatype, MPI_Datatype *);

/* MPI 3 functionality */
DLLDEF int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status);
DLLDEF int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status);
DLLDEF int MPI_Imrecv(void* buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request);
DLLDEF int MPI_Mrecv(void *buf, int count, MPI_Datatype type, MPI_Message *message, MPI_Status *status);

/* Graph Neighbors */
DLLDEF int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors);
DLLDEF int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int *neighbors);
DLLDEF int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree, int *weighted);
DLLDEF int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int *sources, int *sourceweights,
                             int maxoutdegree, int *destinations, int *destweights);

#if defined(__cplusplus)
}
#endif

#endif
