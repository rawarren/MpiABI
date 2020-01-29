
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Add_error_string
 */

#include <_mpi.h>

int
MPI_Add_error_string (int errorcode, char *string)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Add_error_string")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Add_error_string",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Add_error_string) (int errorcode, char *string) = address;
  mpi_return = (*VendorMPI_Add_error_string)(errorcode,string);
  return mpi_return;
}
