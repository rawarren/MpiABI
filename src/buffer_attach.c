
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Buffer_attach
 */

#include <_mpi.h>

int
MPI_Buffer_attach (void *buffer, int size)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Buffer_attach")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Buffer_attach",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Buffer_attach) (void *buffer, int size) = address;
  mpi_return = (*VendorMPI_Buffer_attach)(buffer,size);
  return mpi_return;
}
