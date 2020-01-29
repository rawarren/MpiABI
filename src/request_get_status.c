
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Request_get_status
 */

#include <_mpi.h>

int
MPI_Request_get_status (MPI_Request request, int *flag, MPI_Status *status)
{
  static void *address=0;
  int mpi_return;
  int natstat[MAX_MPI_STATUS_SIZE] = {0,};


  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Request_get_status")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Request_get_status",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
    int (*VendorMPI_Request_get_status)(void *,int *flag, int *status) = address;
    mpi_return = (*VendorMPI_Request_get_status)(local_a0[request].mpi_const,flag,natstat);
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,natstat,(int *)status);
    
  } else { api_use_ints *local_a0=active_requests->api_declared;
    int (*VendorMPI_Request_get_status)(int,int *flag, int *status) = address;
    mpi_return = (*VendorMPI_Request_get_status)(local_a0[request].mpi_const,flag,natstat);
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,natstat,(int *)status);
  }
  return mpi_return;
}
