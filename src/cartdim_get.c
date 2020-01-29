
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cartdim_get
 */

#include <_mpi.h>

int
MPI_Cartdim_get (MPI_Comm comm, int *ndims)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Cartdim_get")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Cartdim_get",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Cartdim_get)(void *, int *ndims) = address;
    mpi_return = (*VendorMPI_Cartdim_get)(local_a0[comm].mpi_const,ndims);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Cartdim_get)(int, int *ndims) = address;
    mpi_return = (*VendorMPI_Cartdim_get)(local_a0[comm].mpi_const,ndims);
  }
  return mpi_return;
}
