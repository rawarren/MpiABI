
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Wait
 */

#include <_mpi.h>

int
MPI_Wait (MPI_Request *request, MPI_Status *status)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Wait")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Wait",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
      int (*VendorMPI_Test)(void **, int *status) = address;
      if (status == MPI_STATUS_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Test)(&local_a0[*request].mpi_const,local_a1[ISC_STATUS_IGNORE].mpi_const);
	if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
	  free_index(active_requests,*request);
	  *request = MPI_REQUEST_NULL;
	}
      } else {
	mpi_return = (*VendorMPI_Test)(&local_a0[*request].mpi_const,status->reserved);
	native_status_to_isc(1,status->reserved,(int *)status);
	if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
	  free_index(active_requests,*request);
	  *request = MPI_REQUEST_NULL;
	}
      }
    } else { api_use_ints *local_a0=active_requests->api_declared;
      int (*VendorMPI_Test)(int *, int *status) = address;
      if (status == MPI_STATUS_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Test)(&local_a0[*request].mpi_const,local_a1[ISC_STATUS_IGNORE].mpi_const);
	if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
	  free_index(active_requests,*request);
	  *request = MPI_REQUEST_NULL;
	}
      } else {
	mpi_return = (*VendorMPI_Test)(&local_a0[*request].mpi_const,status->reserved);
	native_status_to_isc(1,status->reserved,(int *)status);
	if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
	  free_index(active_requests,*request);
	  *request = MPI_REQUEST_NULL;
	}
      }
    }
    return mpi_return;
}
