
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Testsome
 */

#include <_mpi.h>
#include <stdlib.h>

int
MPI_Testsome (int count, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status *array_of_statuses)
{
    static void *address=0;
    int mpi_return;
    int active_count=0;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Testsome")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Testsome",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
      int i;
      int (*VendorMPI_Testsome)(int count,void **,int *,int *, int *natstat) = address;
      void *temp[64],**rtemp=0,**rfill;

      /* Create a contiguous arrary of native request objects
       * We'll avoid malloc/free if we're dealing with fewer than 64 requests
       */
      if (count > 64) 
	rfill = rtemp = (void *)calloc(count,sizeof(void *));
      else rfill = temp;

      for(i=0; i<count; i++) 
	if ((rfill[i] = local_a0[ array_of_requests[i] ].mpi_const) != local_a0[MPI_REQUEST_NULL].mpi_const)
	  active_count++;

      /* When dealing with native MPI_Status objects, we handle two conditions:
       *
       * 1) the user doesn't care about status and has passed in MPI_STATUSES_IGNORE
       *    (which is a synonym for MPI_STATUS_IGNORE)
       * 2) They care about seeing status objects, so we need to translate between ISC
       *    and native MPI_Status structures.  The MPI Spec defines only 3 elements
       *    but most implementations have additional entries which make sense for
       *    them...  We don't have a clue about the actual structure, but do know
       *    it's size and also have a handle to a callback function "native_status_to_isc"
       *    which does know both the ISC structure and native MPI structure and is thus
       *    able to copy information between the two.
       *
       * Lastly, upon completion of the underlying wait/test function, we need to
       * update the ISC_Request entries to MPI_REQUEST_NULL for each native request
       * completed.  We also need to free our ISC_Request index!
       */
      if (array_of_statuses == MPI_STATUS_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Testsome)(count,rfill,outcount,array_of_indices,local_a1[ISC_STATUS_IGNORE].mpi_const);
	for(i=0; active_count && i< *outcount; i++) {
	  if (rfill[array_of_indices[i]] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	    free_index(active_requests,array_of_requests[array_of_indices[i]]);
	    array_of_requests[array_of_indices[i]] = MPI_REQUEST_NULL;
	  }
	}

      } else {
	int elems = true_mpi_status_size/sizeof(int);
	int *natstat = (int *) calloc(count,true_mpi_status_size);
	mpi_return = (*VendorMPI_Testsome)(count,rfill,outcount,array_of_indices,natstat);
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
      int (*VendorMPI_Testsome)(int count,int *,int *,int *, int *natstat) = address;
      int temp[64],*rtemp=0,*rfill;

      if (count > 64) 
	rfill = rtemp = (void *)calloc(count,sizeof(int));
      else rfill = temp;

      for(i=0; i<count; i++) 
	if ((rfill[i] = local_a0[ array_of_requests[i] ].mpi_const) != local_a0[MPI_REQUEST_NULL].mpi_const)
	  active_count++;

      if (array_of_statuses == MPI_STATUS_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Testsome)(count,rfill,outcount,array_of_indices,local_a1[ISC_STATUS_IGNORE].mpi_const);
	for(i=0; active_count && i< *outcount; i++) {
	  if (rfill[array_of_indices[i]] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	    free_index(active_requests,array_of_requests[array_of_indices[i]]);
	    array_of_requests[array_of_indices[i]] = MPI_REQUEST_NULL;
	  }
	}

      } else {
	int elems = true_mpi_status_size/sizeof(int);
	int *natstat = (int *) calloc(count,true_mpi_status_size);
	mpi_return = (*VendorMPI_Testsome)(count,rfill,outcount,array_of_indices,natstat);
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
    return mpi_return;
}
