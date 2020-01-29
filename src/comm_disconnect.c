
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_disconnect
 */

#include <_mpi.h>

int
MPI_Comm_disconnect (MPI_Comm *comm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_disconnect")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_disconnect",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_disconnect)(void **) = address;
    mpi_return = (*VendorMPI_Comm_disconnect)(&local_a0[*comm].mpi_const);
    if (local_a0[*comm].mpi_const == local_a0[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*comm);
      *comm = MPI_COMM_NULL;
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_disconnect)(int *) = address;
    mpi_return = (*VendorMPI_Comm_disconnect)(&local_a0[*comm].mpi_const);
    if (local_a0[*comm].mpi_const == local_a0[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*comm);
      *comm = MPI_COMM_NULL;
    }
  }
  return mpi_return;
}
