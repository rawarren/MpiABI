
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Barrier
 */

#include <_mpi.h>

int
MPI_Barrier (MPI_Comm comm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Barrier")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Barrier",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Barrier)(void *) = address;
    mpi_return = (*VendorMPI_Barrier)(local_a0[comm].mpi_const);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Barrier)(int) = address;
    mpi_return = (*VendorMPI_Barrier)(local_a0[comm].mpi_const);
  }
  return mpi_return;
}
