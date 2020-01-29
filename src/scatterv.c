
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Scatterv
 */

#include <_mpi.h>

int
MPI_Scatterv (void *sendbuf, int sendcounts[], int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Scatterv")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Scatterv",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    int (*VendorMPI_Scatterv)(void *sendbuf,int sendcounts[],int displs[],void *,void *recvbuf,int recvcount,void *,int root,void *) = address;
    mpi_return = (*VendorMPI_Scatterv)(INPLACE(sendbuf),sendcounts,displs,local_a0[sendtype].mpi_const,INPLACE(recvbuf),recvcount,local_a1[recvtype].mpi_const,root,local_a2[comm].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    int (*VendorMPI_Scatterv)(void *sendbuf,int sendcounts[],int displs[],int,void *recvbuf,int recvcount,int,int root,int) = address;
    mpi_return = (*VendorMPI_Scatterv)(INPLACE(sendbuf),sendcounts,displs,local_a0[sendtype].mpi_const,INPLACE(recvbuf),recvcount,local_a1[recvtype].mpi_const,root,local_a2[comm].mpi_const);
  }
  return mpi_return;
}
