
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Pcontrol
 */

#include <_mpi.h>

int
MPI_Pcontrol (const int level, ...)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Pcontrol")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Pcontrol",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Pcontrol) (const int level, ...) = address;
  mpi_return = (*VendorMPI_Pcontrol)(level);
  return mpi_return;
}
