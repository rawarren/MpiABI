
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Grequest_complete
 */

#include <_mpi.h>

int
MPI_Grequest_complete (MPI_Request request)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Grequest_complete")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Grequest_complete",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
    int (*VendorMPI_Grequest_complete)(void *) = address;
    mpi_return = (*VendorMPI_Grequest_complete)(local_a0[request].mpi_const);
  } else { api_use_ints *local_a0=active_requests->api_declared;
    int (*VendorMPI_Grequest_complete)(int) = address;
    mpi_return = (*VendorMPI_Grequest_complete)(local_a0[request].mpi_const);
  }
  return mpi_return;
}
