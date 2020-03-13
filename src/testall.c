
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Testall
 */

#include <_mpi.h>
#include <stdlib.h>


int
MPI_Testall (int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[])
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Testall")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Testall",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
      int i;
      int (*VendorMPI_Testall)(int count,void **,int *flag, int *) = address;
      void *temp[64],**rtemp=0,**rfill;

      if (count > 64) 
	rfill = rtemp = (void *)calloc(count,sizeof(void *));
      else rfill = temp;

      for(i=0; i<count; i++) 
	rfill[i] = local_a0[ array_of_requests[i] ].mpi_const;

      if (array_of_statuses == MPI_STATUSES_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Testall)(count,rfill,flag,local_a1[ISC_STATUS_IGNORE].mpi_const);
      } else {
	  int *natstat = (int *) calloc(count,true_mpi_status_size);
	  mpi_return = (*VendorMPI_Testall)(count,rfill,flag,natstat);
	  i = native_status_to_isc(count,natstat,(int *)array_of_statuses);
	  free(natstat);
      }

      for(i=0; i<count; i++) {
	if (rfill[i] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	  free_index(active_requests,array_of_requests[i]);
	  array_of_requests[i] = MPI_REQUEST_NULL;
	}
      }

      if (rtemp) free(rtemp);

    } else { api_use_ints *local_a0=active_requests->api_declared;
      int i;
      int (*VendorMPI_Testall)(int count,int *,int *flag, int *) = address;
      int temp[64],*rtemp=0,*rfill;

      if (count > 64) 
	rfill = rtemp = (void *)calloc(count,sizeof(int));
      else rfill = temp;

      for(i=0; i<count; i++) 
	rfill[i] = local_a0[ array_of_requests[i] ].mpi_const;

      if (array_of_statuses == MPI_STATUSES_IGNORE) {
	api_use_ptrs *local_a1=active_addrs->api_declared;
	mpi_return = (*VendorMPI_Testall)(count,rfill,flag,local_a1[ISC_STATUS_IGNORE].mpi_const);
      } else {
	  int *natstat = (int *) calloc(count,true_mpi_status_size);
	  mpi_return = (*VendorMPI_Testall)(count,rfill,flag,natstat);
	  i = native_status_to_isc(count,natstat,(int *)array_of_statuses);
	  free(natstat);
      }
      for(i=0; i<count; i++) {
	if (rfill[i] == local_a0[MPI_REQUEST_NULL].mpi_const) {
	  free_index(active_requests,array_of_requests[i]);
	  array_of_requests[i] = MPI_REQUEST_NULL;
	}
      }
      if (rtemp) free(rtemp);
    }
    return mpi_return;
}
