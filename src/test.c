
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Test
 */

#include <_mpi.h>

int
MPI_Test (MPI_Request *request, int *flag, MPI_Status *status)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Test")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Test",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
      int (*VendorMPI_Test)(void **,int *flag, int *status) = address;
      if (status == MPI_STATUS_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Test)(&local_a0[*request].mpi_const,flag,local_a1[ISC_STATUS_IGNORE].mpi_const);
	if (*flag) {
	  if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
	    free_index(active_requests,*request);
	    *request = ISC_REQUEST_NULL;
	  }
	}
      } else {
	int natstat[MAX_MPI_STATUS_SIZE] = {0,};
	isc_status_to_native(1,(int *)status,natstat);
	mpi_return = (*VendorMPI_Test)(&local_a0[*request].mpi_const,flag,natstat);
	if (*flag) {
	  native_status_to_isc(1,natstat,(int *)status);
	  if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
	    free_index(active_requests,*request);
	    *request = ISC_REQUEST_NULL;
	  }
	}
      }
    } else { api_use_ints *local_a0=active_requests->api_declared;
      int (*VendorMPI_Test)(int *,int *flag, int *status) = address;
      if (status == MPI_STATUS_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Test)(&local_a0[*request].mpi_const,flag,local_a1[ISC_STATUS_IGNORE].mpi_const);
	if (*flag) {
	  if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
	    free_index(active_requests,*request);
	    *request = ISC_REQUEST_NULL;
	  }
	}
      } else {
	int natstat[MAX_MPI_STATUS_SIZE] = {0,};
	isc_status_to_native(1,(int *)status,natstat);
	mpi_return = (*VendorMPI_Test)(&local_a0[*request].mpi_const,flag,natstat);
	if (*flag) {
	  native_status_to_isc(1,natstat,(int *)status);
	  if (local_a0[*request].mpi_const == local_a0[MPI_REQUEST_NULL].mpi_const) {
	    free_index(active_requests,*request);
	    *request = ISC_REQUEST_NULL;
	  }
	}
      }
    }
    return mpi_return;
}
