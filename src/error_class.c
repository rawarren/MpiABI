
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Error_class
 */

#include <_mpi.h>

int
MPI_Error_class (int errorcode, int *errorclass)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Error_class")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Error_class",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Error_class) (int errorcode, int *errorclass) = address;
  mpi_return = (*VendorMPI_Error_class)(errorcode,errorclass);
  return mpi_return;
}
