
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Query_thread
 */

#include <_mpi.h>

int
MPI_Query_thread (int *provided)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Query_thread")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Query_thread",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Query_thread) (int *provided) = address;
  mpi_return = (*VendorMPI_Query_thread)(provided);
  return mpi_return;
}
