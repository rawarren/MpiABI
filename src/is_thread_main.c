
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Is_thread_main
 */

#include <_mpi.h>

int
MPI_Is_thread_main (int *flag)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Is_thread_main")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Is_thread_main",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Is_thread_main) (int *flag) = address;
  mpi_return = (*VendorMPI_Is_thread_main)(flag);
  return mpi_return;
}
