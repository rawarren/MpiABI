
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Reduce_scatter
 */

#include <_mpi.h>

int
MPI_Reduce_scatter (void *sendbuf, void *recvbuf, int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Reduce_scatter")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Reduce_scatter",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1=active_ops->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    int (*VendorMPI_Reduce_scatter)(void *sendbuf,void *recvbuf,int recvcounts[],void *,void *,void *) = address;
    mpi_return = (*VendorMPI_Reduce_scatter)(INPLACE(sendbuf),INPLACE(recvbuf),recvcounts,local_a0[datatype].mpi_const,local_a1[op].mpi_const,local_a2[comm].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1=active_ops->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    int (*VendorMPI_Reduce_scatter)(void *sendbuf,void *recvbuf,int recvcounts[],int,int,int) = address;
    mpi_return = (*VendorMPI_Reduce_scatter)(INPLACE(sendbuf),INPLACE(recvbuf),recvcounts,local_a0[datatype].mpi_const,local_a1[op].mpi_const,local_a2[comm].mpi_const);
  }
  return mpi_return;
}
