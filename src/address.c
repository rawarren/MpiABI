
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Address
 */

#include <_mpi.h>

int
MPI_Address (void *location, MPI_Aint *addr)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Address")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Address",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Address) (void *location, MPI_Aint *addr) = address;
  mpi_return = (*VendorMPI_Address)(location,addr);
  return mpi_return;
}
