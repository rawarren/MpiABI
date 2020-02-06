
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Waitsome
 */

#include <_mpi.h>
#include <stdlib.h>

int
MPI_Waitsome (int count, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status *array_of_statuses)
{
    static void *address=0;
    int mpi_return;
    int active_count=0;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Waitsome")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Waitsome",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
      int i;
      int (*VendorMPI_Waitsome)(int count,void **,int *,int *, int *natstat) = address;
      void *temp[64],**rtemp=0,**rfill;

      if (count > 64) 
	  rfill = rtemp = (void *)calloc((size_t)count,sizeof(void *));
      else rfill = temp;

      for(i=0; i<count; i++) 
	if ((rfill[i] = local_a0[ array_of_requests[i] ].mpi_const) != local_a0[MPI_REQUEST_NULL].mpi_const)
	  active_count++;

      if (array_of_statuses == MPI_STATUS_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Waitsome)(count,rfill,outcount,array_of_indices,local_a1[ISC_STATUS_IGNORE].mpi_const);
	for(i=0; active_count && i< *outcount; i++) {
	  if (rfill[array_of_indices[i]] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	    free_index(active_requests,array_of_requests[array_of_indices[i]]);
	    array_of_requests[array_of_indices[i]] = MPI_REQUEST_NULL;
	  }
	}

      } else {
        size_t statsize= (size_t)true_mpi_status_size;
	int elems = true_mpi_status_size/sizeof(int);
	int *natstat = (int *) calloc((size_t)count,statsize);
	mpi_return = (*VendorMPI_Waitsome)(count,rfill,outcount,array_of_indices,natstat);
	for(i=0; active_count && i< *outcount; i++) {
	  native_status_to_isc(1,&natstat[array_of_indices[i]*elems],(int *)&array_of_statuses[array_of_indices[i]]);
	  if (rfill[array_of_indices[i]] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	    free_index(active_requests,array_of_requests[array_of_indices[i]]);
	    array_of_requests[array_of_indices[i]] = MPI_REQUEST_NULL;
	  }
	}
	free(natstat);
      }
      if (rtemp) free(rtemp);

    }
    /*
     * The else clause is exactly as above, but references integer valued native request objects
     ***************************************************************************************/
    else { api_use_ints *local_a0=active_requests->api_declared;
      int i;
      int (*VendorMPI_Waitsome)(int count,int *,int *,int *, int *natstat) = address;
      int temp[64],*rtemp=0,*rfill;

      if (count > 64) 
	rfill = rtemp = (void *)calloc(count,sizeof(int));
      else rfill = temp;

      for(i=0; i<count; i++) 
	if ((rfill[i] = local_a0[ array_of_requests[i] ].mpi_const) != local_a0[MPI_REQUEST_NULL].mpi_const)
	  active_count++;

      if (array_of_statuses == MPI_STATUS_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Waitsome)(count,rfill,outcount,array_of_indices,local_a1[ISC_STATUS_IGNORE].mpi_const);
	for(i=0; active_count && i< *outcount; i++) {
	  if (rfill[array_of_indices[i]] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	    free_index(active_requests,array_of_requests[array_of_indices[i]]);
	    array_of_requests[array_of_indices[i]] = MPI_REQUEST_NULL;
	  }
	}

      } else {
        size_t statsize= (size_t)true_mpi_status_size;
	int elems = true_mpi_status_size/sizeof(int);
	int *natstat = (int *) calloc((size_t)count,statsize);
	mpi_return = (*VendorMPI_Waitsome)(count,rfill,outcount,array_of_indices,natstat);
	for(i=0; active_count && i< *outcount; i++) {
	  native_status_to_isc(1,&natstat[array_of_indices[i]*elems],(int *)&array_of_statuses[array_of_indices[i]]);
	  if (rfill[array_of_indices[i]] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	    free_index(active_requests,array_of_requests[array_of_indices[i]]);
	    array_of_requests[array_of_indices[i]] = MPI_REQUEST_NULL;
	  }
	}
	free(natstat);
      }
      if (rtemp) free(rtemp);

    }
    if (!active_count) 
      *outcount = MPI_UNDEFINED;

    if (mpi_return != MPI_SUCCESS) {
      api_use_ints *local_a1 = active_errcodes->api_declared;
      if ((mpi_return & 0x0ffff) == local_a1[ISC_ERR_IN_STATUS].mpi_const)
	 return ISC_ERR_IN_STATUS;
    }

    return mpi_return;
}
