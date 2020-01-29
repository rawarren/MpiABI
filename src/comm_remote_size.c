
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_remote_size
 */

#include <_mpi.h>

int
MPI_Comm_remote_size (MPI_Comm comm, int *size)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_remote_size")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_remote_size",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_remote_size)(void *, int *size) = address;
    mpi_return = (*VendorMPI_Comm_remote_size)(local_a0[comm].mpi_const,size);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_remote_size)(int, int *size) = address;
    mpi_return = (*VendorMPI_Comm_remote_size)(local_a0[comm].mpi_const,size);
  }
  return mpi_return;
}
