
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get_address
 */

#include <_mpi.h>

int
MPI_Get_address (void *location, MPI_Aint *addr)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Get_address")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Get_address",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Get_address) (void *location, MPI_Aint *addr) = address;
  mpi_return = (*VendorMPI_Get_address)(location,addr);
  return mpi_return;
}
