
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Register_datarep
 */

#include <_mpi.h>

int
MPI_Register_datarep (char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Register_datarep")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Register_datarep",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Register_datarep) (char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) = address;
  mpi_return = (*VendorMPI_Register_datarep)(datarep,read_conversion_fn,write_conversion_fn,dtype_file_extent_fn,extra_state);
  return mpi_return;
}
