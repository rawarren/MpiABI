
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Testany
 */

#include <_mpi.h>
#include <stdlib.h>

int
MPI_Testany (int count, MPI_Request array_of_requests[], int *index, int *flag, MPI_Status *status)
{
    static void *address=0;
    int mpi_return;
    api_use_ints *local_a2=active_miscs->api_declared;
    int native_undefined = local_a2[ISC_UNDEFINED_].mpi_const;

    if (!address) {
        if ((address = dlsym(MPI_libhandle,"MPI_Testany")) == NULL) {
            printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Testany",SYM_MISSING_TRAILER);
            return -1;
        }
    }

    if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
        int i;
        int (*VendorMPI_Testany)(int count,void **,int *index,int *, int *) = address;
        void *temp[64],**rtemp=0,**rfill;

        if (count > 64) 
            rfill = rtemp = (void *)calloc(count,sizeof(void *));
        else rfill = temp;

        for(i=0; i<count; i++) {
            rfill[i] = local_a0[ array_of_requests[i] ].mpi_const;
        }
        if (status == MPI_STATUS_IGNORE) {
            api_use_ptrs *local_a1=active_addrs->api_declared;
            mpi_return = (*VendorMPI_Testany)(count,rfill,index,flag,local_a1[ISC_STATUS_IGNORE].mpi_const);

            if (*flag) {
                if (count && rfill[*index] == local_a0[MPI_REQUEST_NULL].mpi_const) {
                    free_index(active_requests,array_of_requests[*index]);
                    array_of_requests[*index] = MPI_REQUEST_NULL;
                }
            }
            else if (*index == native_undefined)
                *index = ISC_UNDEFINED;
        } else {
            mpi_return = (*VendorMPI_Testany)(count,rfill,index,flag,status->reserved);
            if (*flag) {
                i = native_status_to_isc(1,status->reserved,(int *)status);
                if (rfill[*index] == local_a0[MPI_REQUEST_NULL].mpi_const) {
                    free_index(active_requests,array_of_requests[*index]);
                    array_of_requests[*index] = MPI_REQUEST_NULL;
                }
            }
            else if (*index == native_undefined)
                *index = ISC_UNDEFINED;
        }
        if (rtemp) free(rtemp);
    } /* End if (use_ptrs) */
    else { api_use_ints *local_a0=active_requests->api_declared;
      int i;
      int (*VendorMPI_Testany)(int count,int *,int *index,int *flag, int *) = address;
      int temp[64],*rtemp=0,*rfill;

      if (count > 64) 
          rfill = rtemp = (void *)calloc(count,sizeof(int));
      else rfill = temp;

      for(i=0; i<count; i++) {
          rfill[i] = local_a0[ array_of_requests[i] ].mpi_const;
      }
      if (status == MPI_STATUS_IGNORE) {
          api_use_ptrs *local_a1=active_addrs->api_declared;
          mpi_return = (*VendorMPI_Testany)(count,rfill,index,flag, local_a1[ISC_STATUS_IGNORE].mpi_const);
          if (*flag) {
			  if (*index == native_undefined) 
				  *index = ISC_UNDEFINED;
              else if (rfill[*index] == local_a0[MPI_REQUEST_NULL].mpi_const) {
                  free_index(active_requests,array_of_requests[*index]);
                  array_of_requests[*index] = MPI_REQUEST_NULL;
              }
          }
		  else *index = ISC_UNDEFINED;
      } /* if MPI_STATUS_IGNORE */
      else {
          mpi_return = (*VendorMPI_Testany)(count,rfill,index,flag,status->reserved);
          if (*flag) {
              i = native_status_to_isc(1,status->reserved,(int *)status);
			  if (*index == native_undefined)
				  *index = ISC_UNDEFINED;
			  else if (rfill[*index] == local_a0[MPI_REQUEST_NULL].mpi_const) {
                  free_index(active_requests,array_of_requests[*index]);
                  array_of_requests[*index] = MPI_REQUEST_NULL;
              }
          }
		  else *index = ISC_UNDEFINED;
      }
      if (rtemp) free(rtemp);
    } /* End if (use_ints) */
    return mpi_return;
}
