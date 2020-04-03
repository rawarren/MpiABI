
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get_elements
 */

#include <_mpi.h>

int
MPI_Get_elements (MPI_Status *status, MPI_Datatype datatype, int *count)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Get_elements")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Get_elements",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  /* The Vendor copy of MPI_Status is cached inside of our structure...*/
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Get_elements)(int *status,void *, int *count) = address;
    mpi_return = (*VendorMPI_Get_elements)(status->reserved,local_a0[datatype].mpi_const,count);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Get_elements)(int *status,int, int *count) = address;
    mpi_return = (*VendorMPI_Get_elements)(status->reserved,local_a0[datatype].mpi_const,count);
  }
  if (mpi_return == 0) {
      native_status_to_isc_no_error(1,status->reserved, (int *)status);
  } else native_status_to_isc(1,status->reserved,(int *)status);

  return mpi_return;
}

int
MPI_Get_elements_x (MPI_Status *status, MPI_Datatype datatype, MPI_Count *count)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Get_elements_x")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Get_elements_x",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  /* The Vendor copy of MPI_Status is cached inside of our structure...*/
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Get_elements_x)(int *status,void *, MPI_Count *count) = address;
    mpi_return = (*VendorMPI_Get_elements_x)(status->reserved,local_a0[datatype].mpi_const,count);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Get_elements_x)(int *status,int, MPI_Count *count) = address;
    mpi_return = (*VendorMPI_Get_elements_x)(status->reserved,local_a0[datatype].mpi_const,count);
  }
  if (mpi_return == 0) {
      native_status_to_isc_no_error(1,status->reserved, (int *)status);
  } else native_status_to_isc(1,status->reserved,(int *)status);

  return mpi_return;
}
