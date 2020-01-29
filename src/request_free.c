
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Request_free
 */

#include <_mpi.h>

int
MPI_Request_free (MPI_Request *request)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Request_free")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Request_free",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
    int (*VendorMPI_Request_free)(void **) = address;
    mpi_return = (*VendorMPI_Request_free)(&local_a0[*request].mpi_const);
    if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
      free_index(active_requests,*request);
      *request = MPI_REQUEST_NULL;
    }
  } else { api_use_ints *local_a0=active_requests->api_declared;
    int (*VendorMPI_Request_free)(int *) = address;
    mpi_return = (*VendorMPI_Request_free)(&local_a0[*request].mpi_const);
    if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
      free_index(active_requests,*request);
      *request = MPI_REQUEST_NULL;
    }
  }
  return mpi_return;
}
