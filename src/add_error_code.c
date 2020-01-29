
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Add_error_code
 */

#include <_mpi.h>

int
MPI_Add_error_code (int errorclass, int *errorcode)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Add_error_code")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Add_error_code",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Add_error_code) (int errorclass, int *errorcode) = address;
  mpi_return = (*VendorMPI_Add_error_code)(errorclass,errorcode);
  return mpi_return;
}
