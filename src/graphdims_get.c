
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graphdims_get
 */

#include <_mpi.h>

int
MPI_Graphdims_get (MPI_Comm comm, int *nnodes, int *nedges)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Graphdims_get")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Graphdims_get",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Graphdims_get)(void *,int *nnodes, int *nedges) = address;
    mpi_return = (*VendorMPI_Graphdims_get)(local_a0[comm].mpi_const,nnodes,nedges);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Graphdims_get)(int,int *nnodes, int *nedges) = address;
    mpi_return = (*VendorMPI_Graphdims_get)(local_a0[comm].mpi_const,nnodes,nedges);
  }
  return mpi_return;
}
