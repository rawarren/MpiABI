
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get_count
 */

#include <_mpi.h>

int
MPI_Get_count (MPI_Status *status, MPI_Datatype datatype, int *count)
{
  static void *address=0;
  api_use_ints *local_a1 = active_miscs->api_declared;
  int native_count;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Get_count")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Get_count",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  /* The Vendor copy of MPI_Status is cached inside of our structure...*/
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Get_count)(int *status,void *, int *count) = address;
    mpi_return = (*VendorMPI_Get_count)(status->reserved,local_a0[datatype].mpi_const,&native_count);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Get_count)(int *status,int, int *count) = address;
    mpi_return = (*VendorMPI_Get_count)(status->reserved,local_a0[datatype].mpi_const,&native_count);
  }
  if (native_count == local_a1[ISC_UNDEFINED_].mpi_const)
    *count = MPI_UNDEFINED;
  else *count = native_count;
  return mpi_return;
}
