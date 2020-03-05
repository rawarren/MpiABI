
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Ineighbor_alltoallw
 */

#include <_mpi.h>
#include <stdlib.h>

int
MPI_Ineighbor_alltoallw (void *sendbuf, int sendcounts[], MPI_Aint sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], MPI_Aint rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
    static void *address=0;
    int mpi_return;
    int i, size;
    int neighbor_size;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Ineighbor_alltoallw")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Ineighbor_alltoallw",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    /* FIXME:
     * I need to find a way to determine how many senttypes and recvtypes
     * to process.  My current approach attepts to something rational with
     * sendcounts and checking for valid send/recv types.  This is obviously
     * not the best way to work...
     */

    MPI_Comm_size(comm,&size);
    neighbor_size = 2;
    while((sendcounts[neighbor_size+1] > 0) && (sendtypes[neighbor_size+1] < active_datatypes->how_many))
	neighbor_size++;

    *request = new_index(active_requests);
    if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
       void *stemp[64],*rtemp[64];
       void **sfill, **rfill;
       api_use_ptrs *local_a1= active_datatypes->api_declared;
       api_use_ptrs *local_a2= active_comms->api_declared;
       if (neighbor_size > 64) {
	   sfill = (void **)calloc(neighbor_size,sizeof(void *));
	   rfill = (void **)calloc(neighbor_size,sizeof(void *));
       }
       else {
	   sfill = stemp;
	   rfill = rtemp;
       }
       for(i=0; i<neighbor_size; i++) {
	 sfill[i] = local_a0[sendtypes[i]].mpi_const;
       }

       neighbor_size = 2;
       while((recvcounts[neighbor_size+1] > 0) && (recvtypes[neighbor_size+1] < active_datatypes->how_many))
	   neighbor_size++;
       for(i=0; i<neighbor_size; i++) {
	 rfill[i] = local_a1[recvtypes[i]].mpi_const;
       }

       if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ineighbor_alltoallw)(void *sendbuf,int sendcounts[],MPI_Aint sdispls[],void *,void *recvbuf,int recvcounts[],MPI_Aint rdispls[],void *,void *, void **) = address;
	   mpi_return = (*VendorMPI_Ineighbor_alltoallw)(INPLACE(sendbuf),sendcounts,sdispls,&sfill[0],INPLACE(recvbuf),recvcounts,rdispls,&rfill[0],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       }
       else { api_use_ints *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ineighbor_alltoallw)(void *sendbuf,int sendcounts[],MPI_Aint sdispls[],void *,void *recvbuf,int recvcounts[],MPI_Aint rdispls[],void *,void *, int *) = address;
	   mpi_return = (*VendorMPI_Ineighbor_alltoallw)(INPLACE(sendbuf),sendcounts,sdispls,&sfill[0],INPLACE(recvbuf),recvcounts,rdispls,&rfill[0],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       }
       if (sfill != stemp) {
	   free(sfill);
	   free(rfill);
       }
    } else { api_use_ints *local_a0 = active_datatypes->api_declared;
       int stemp[64], rtemp[64];
       int *sfill, *rfill;
       api_use_ints *local_a1= active_datatypes->api_declared;
       api_use_ints *local_a2= active_comms->api_declared;
       if (neighbor_size > 64) {
	   sfill = (int *)calloc(neighbor_size,sizeof(int));
	   rfill = (int *)calloc(neighbor_size,sizeof(int));
       }
       else {
	   sfill = stemp;
	   rfill = rtemp;
       }
       for(i=0; i<neighbor_size; i++) {
	 sfill[i] = local_a0[sendtypes[i]].mpi_const;
       }
       neighbor_size = 2;
       while((recvcounts[neighbor_size+1] > 0) && (recvtypes[neighbor_size+1] < active_datatypes->how_many))
	   neighbor_size++;

       for(i=0; i<neighbor_size; i++) {
	 rfill[i] = local_a1[recvtypes[i]].mpi_const;
       }

       if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ineighbor_alltoallw)(void *sendbuf,int sendcounts[],MPI_Aint sdispls[],int *,void *recvbuf,int recvcounts[],MPI_Aint rdispls[],int *,int, void **) = address;
	   mpi_return = (*VendorMPI_Ineighbor_alltoallw)(INPLACE(sendbuf),sendcounts,sdispls,&sfill[0],INPLACE(recvbuf),recvcounts,rdispls,&rfill[0],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       } else { api_use_ints *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ineighbor_alltoallw)(void *sendbuf,int sendcounts[],MPI_Aint sdispls[],int *,void *recvbuf,int recvcounts[],MPI_Aint rdispls[],int *,int, int *) = address;	   
	   mpi_return = (*VendorMPI_Ineighbor_alltoallw)(INPLACE(sendbuf),sendcounts,sdispls,&sfill[0],INPLACE(recvbuf),recvcounts,rdispls,&rfill[0],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       }
       if (sfill != stemp) {
	   free(sfill);
	   free(rfill);
       }
    }
    return mpi_return;
}
