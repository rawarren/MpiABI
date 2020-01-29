
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Error_string
 */

#include <_mpi.h>

int
MPI_Error_string (int errorcode, char *string, int *resultlen)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Error_string")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Error_string",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Error_string) (int errorcode, char *string, int *resultlen) = address;
  mpi_return = (*VendorMPI_Error_string)(errorcode,string,resultlen);
  return mpi_return;
}
