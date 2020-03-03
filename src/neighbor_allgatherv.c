
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Neighbor_allgatherv
 */

#include <_mpi.h>

int
MPI_Neighbor_allgatherv (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], MPI_Datatype recvtype, MPI_Comm comm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Neighbor_allgatherv")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Neighbor_allgatherv",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    int (*VendorMPI_Neighbor_allgatherv)(void *sendbuf,int sendcount,void *,void *recvbuf,int recvcounts[],int displs[],void *,void *) = address;
    mpi_return = (*VendorMPI_Neighbor_allgatherv)(INPLACE(sendbuf),sendcount,local_a0[sendtype].mpi_const,recvbuf,recvcounts,displs,local_a1[recvtype].mpi_const,local_a2[comm].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    int (*VendorMPI_Neighbor_allgatherv)(void *sendbuf,int sendcount,int,void *recvbuf,int recvcounts[],int displs[],int,int) = address;
    mpi_return = (*VendorMPI_Neighbor_allgatherv)(INPLACE(sendbuf),sendcount,local_a0[sendtype].mpi_const,recvbuf,recvcounts,displs,local_a1[recvtype].mpi_const,local_a2[comm].mpi_const);
  }
  return mpi_return;
}
