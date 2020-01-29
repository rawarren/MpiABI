
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Free_mem
 */

#include <_mpi.h>

int
MPI_Free_mem (void *base)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Free_mem")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Free_mem",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Free_mem) (void *base) = address;
  mpi_return = (*VendorMPI_Free_mem)(base);
  return mpi_return;
}
