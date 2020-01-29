
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Startall
 */

#include <_mpi.h>

int
MPI_Startall (int count, MPI_Request *array_of_requests)
{
  static void *address=0;
  int i, mpi_return=0;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Startall")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Startall",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  /* Hack!! */
  for(i=0; i< count; i++) {
    mpi_return |= MPI_Start(&array_of_requests[i]);
  }
  return mpi_return;
}
