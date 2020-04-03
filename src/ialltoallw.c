
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Ialltoallw
 */

#include <_mpi.h>
#include <stdlib.h>
#include <string.h>

int
MPI_Ialltoallw (void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
    static void *address=0;
    int mpi_return;
    int is_intercomm = 0;
    int i, size, lsize, asize = 0;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Ialltoallw")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Ialltoallw",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    MPI_Comm_size(comm,&size);
    MPI_Comm_test_inter(comm,&is_intercomm);
    if (is_intercomm) {
	lsize = size;
	MPI_Comm_remote_size(comm,&size);
	// asize = (remote_size > size ? remote_size : size);
    }

    *request = new_index(active_requests);
    if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
       api_use_ptrs *local_a1= active_datatypes->api_declared;
       api_use_ptrs *local_a2= active_comms->api_declared;
       void *temp[128],**dtemp=0, **dfill;
       if (size > 64) {
	 dfill = dtemp = (void *)calloc(size*2,sizeof(void *));
       } else dfill = temp;
       if (sendbuf == (void *)ISC_IN_PLACE) 
	   memset(dfill,0, sizeof(void *) *size);
       else {
	   for(i=0; i<size; i++) {
	       dfill[i] = local_a0[sendtypes[i]].mpi_const;
	   }
       }
       if (recvbuf == (void *)ISC_IN_PLACE)
	   memset(&dfill[size],0, sizeof(void *) *size);
       else {
	   for(i=0; i<size; i++) {
	       dfill[size + i] = local_a1[recvtypes[i]].mpi_const;
	   }
       }
       if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ialltoallw)(void *sendbuf,int sendcounts[],int sdispls[],void *,void *recvbuf,int recvcounts[],int rdispls[],void *,void *, void **) = address;
	   mpi_return = (*VendorMPI_Ialltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       }
       else { api_use_ints *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ialltoallw)(void *sendbuf,int sendcounts[],int sdispls[],void *,void *recvbuf,int recvcounts[],int rdispls[],void *,void *, int *) = address;
	   mpi_return = (*VendorMPI_Ialltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       }
       if (dtemp) free(dtemp);
    } else { api_use_ints *local_a0 = active_datatypes->api_declared;
       api_use_ints *local_a1= active_datatypes->api_declared;
       api_use_ints *local_a2= active_comms->api_declared;
       int temp[128],*dtemp=0, *dfill;
       if (size > 64)
	 dfill = dtemp = (int *)calloc(size*2,sizeof(int));
       else dfill = temp;
       if (sendbuf == (void *)ISC_IN_PLACE) 
	   memset(dfill,0, sizeof(int) *size);
       else {
	   for(i=0; i<size; i++) {
	       dfill[i] = local_a0[sendtypes[i]].mpi_const;
	   }
       }
       if (recvbuf == (void *)ISC_IN_PLACE)
	   memset(&dfill[size],0, sizeof(int) *size);	   
       else {
	   for(i=0; i<size; i++) {
	       dfill[size + i] = local_a1[recvtypes[i]].mpi_const;
	   }
       }
       if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ialltoallw)(void *sendbuf,int sendcounts[],int sdispls[],int *,void *recvbuf,int recvcounts[],int rdispls[],int *,int, void **) = address;
	   mpi_return = (*VendorMPI_Ialltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       } else { api_use_ints *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ialltoallw)(void *sendbuf,int sendcounts[],int sdispls[],int *,void *recvbuf,int recvcounts[],int rdispls[],int *,int, int *) = address;	   
	   mpi_return = (*VendorMPI_Ialltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       }
       if (dtemp) free(dtemp);
    }
    return mpi_return;
}
