
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_rank
 */

#include <_mpi.h>

int
MPI_Comm_rank (MPI_Comm comm, int *rank)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_rank")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_rank",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_rank)(void *, int *rank) = address;
    mpi_return = (*VendorMPI_Comm_rank)(local_a0[comm].mpi_const,rank);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_rank)(int, int *rank) = address;
    mpi_return = (*VendorMPI_Comm_rank)(local_a0[comm].mpi_const,rank);
  }
  return mpi_return;
}
