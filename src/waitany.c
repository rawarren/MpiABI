
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Waitany
 */

#include <_mpi.h>
#include <stdlib.h>

int
MPI_Waitany (int count, MPI_Request *array_of_requests, int *index, MPI_Status *status)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Waitany")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Waitany",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
      api_use_ints *local_a2=active_miscs->api_declared;
      int i;
      int (*VendorMPI_Waitany)(int count,void **,int *index, int *natstat) = address;
      void *temp[64],**rtemp=0,**rfill;

      if (count > 64) 
	rfill = rtemp = (void *)calloc(count,sizeof(void *));
      else rfill = temp;

      for(i=0; i<count; i++) {
	rfill[i] = local_a0[ array_of_requests[i] ].mpi_const;
      }
      if (status == MPI_STATUS_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Waitany)(count,rfill,index,local_a1[ISC_STATUS_IGNORE].mpi_const);
	if (*index == local_a2[ISC_UNDEFINED_].mpi_const)
	    *index = ISC_UNDEFINED;
	else if (rfill[*index] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	  free_index(active_requests,array_of_requests[*index]);
	  array_of_requests[*index] = MPI_REQUEST_NULL;
	}
      } else {
	int natstat[MAX_MPI_STATUS_SIZE] = {0,};
	mpi_return = (*VendorMPI_Waitany)(count,rfill,index,natstat);
	native_status_to_isc(1,natstat,(int *)status);
	if (*index == local_a2[ISC_UNDEFINED_].mpi_const)
	    *index = ISC_UNDEFINED;
	else if (rfill[*index] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	  free_index(active_requests,array_of_requests[*index]);
	  array_of_requests[*index] = MPI_REQUEST_NULL;
	}
      }
      if (rtemp) free(rtemp);
    } else { api_use_ints *local_a0=active_requests->api_declared;
      api_use_ints *local_a2=active_miscs->api_declared;
      int i;
      int (*VendorMPI_Waitany)(int count,int *,int *index, int *natstat) = address;
      int temp[64],*rtemp=0,*rfill;

      if (count > 64) 
	rfill = rtemp = (void *)calloc(count,sizeof(int));
      else rfill = temp;

      for(i=0; i<count; i++) 
	rfill[i] = local_a0[ array_of_requests[i] ].mpi_const;

      if (status == MPI_STATUS_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Waitany)(count,rfill,index,local_a1[ISC_STATUS_IGNORE].mpi_const);
	if (*index == local_a2[ISC_UNDEFINED_].mpi_const)
	    *index = ISC_UNDEFINED;
	else if (rfill[*index] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	  free_index(active_requests,array_of_requests[*index]);
	  array_of_requests[*index] = MPI_REQUEST_NULL;
	}
      } else {
	int natstat[MAX_MPI_STATUS_SIZE] = {0,};
	mpi_return = (*VendorMPI_Waitany)(count,rfill,index,natstat);
	native_status_to_isc(1,natstat,(int *)status);
	if (*index == local_a2[ISC_UNDEFINED_].mpi_const)
	    *index = ISC_UNDEFINED;
	else if (rfill[*index] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	  free_index(active_requests,array_of_requests[*index]);
	  array_of_requests[*index] = MPI_REQUEST_NULL;
	}
      }
      if (rtemp) free(rtemp);
    }
    return mpi_return;
}
