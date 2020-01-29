
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get_processor_name
 */

#include <_mpi.h>

int
MPI_Get_processor_name (char *name, int *resultlen)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Get_processor_name")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Get_processor_name",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Get_processor_name) (char *name, int *resultlen) = address;
  mpi_return = (*VendorMPI_Get_processor_name)(name,resultlen);
  return mpi_return;
}
