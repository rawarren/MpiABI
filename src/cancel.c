
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cancel
 */

#include <_mpi.h>

int
MPI_Cancel (MPI_Request *request)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Cancel")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Cancel",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
    int (*VendorMPI_Cancel)(void **) = address;
    mpi_return = (*VendorMPI_Cancel)(&local_a0[*request].mpi_const);
    if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
      free_index(active_requests,*request);
      *request = MPI_REQUEST_NULL;
    }

  } else { api_use_ints *local_a0=active_requests->api_declared;
    int (*VendorMPI_Cancel)(int *) = address;
    mpi_return = (*VendorMPI_Cancel)(&local_a0[*request].mpi_const);
    if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
      free_index(active_requests,*request);
      *request = MPI_REQUEST_NULL;
    }
  }
  return mpi_return;
}
