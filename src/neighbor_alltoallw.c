
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Neighbor_alltoallw
 */

#include <_mpi.h>
#include <stdlib.h>


int
MPI_Neighbor_alltoallw (void *sendbuf, int sendcounts[], MPI_Aint sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], MPI_Aint rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm)
{
    static void *address=0;
    int mpi_return;
    int i, size;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Neighbor_alltoallw")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Neighbor_alltoallw",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    MPI_Comm_size(comm,&size);

    if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
       api_use_ptrs *local_a1= active_datatypes->api_declared;
       api_use_ptrs *local_a2= active_comms->api_declared;
       void *temp[128],**dtemp=0, **dfill;
       if (size > 64) {
	 dfill = dtemp = (void *)calloc(size*2,sizeof(void *));
       } else dfill = temp;
       for(i=0; i<size; i++) {
	 dfill[i] = local_a0[sendtypes[i]].mpi_const;
       }
       for(i=0; i<size; i++) {
	 dfill[size + i] = local_a1[recvtypes[i]].mpi_const;
       }
       
       int (*VendorMPI_Neighbor_alltoallw)(void *sendbuf,int sendcounts[],MPI_Aint sdispls[],void *,void *recvbuf,int recvcounts[],MPI_Aint rdispls[],void *,void *) = address;
       mpi_return = (*VendorMPI_Neighbor_alltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const);
       if (dtemp) free(dtemp);
    } else { api_use_ints *local_a0 = active_datatypes->api_declared;
       api_use_ints *local_a1= active_datatypes->api_declared;
       api_use_ints *local_a2= active_comms->api_declared;
       int temp[128],*dtemp=0, *dfill;
       if (size > 64)
	 dfill = dtemp = (int *)calloc(size*2,sizeof(int));
       else dfill = temp;
       for(i=0; i<size; i++) {
	 dfill[i] = local_a0[sendtypes[i]].mpi_const;
       }
       for(i=0; i<size; i++) {
	 dfill[size + i] = local_a1[recvtypes[i]].mpi_const;
       }

       int (*VendorMPI_Neighbor_alltoallw)(void *sendbuf,int sendcounts[],MPI_Aint sdispls[],int *,void *recvbuf,int recvcounts[],MPI_Aint rdispls[],int *,int) = address;
       mpi_return = (*VendorMPI_Neighbor_alltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const);
       if (dtemp) free(dtemp);
    }
    return mpi_return;
}
