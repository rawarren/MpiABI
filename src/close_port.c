
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Close_port
 */

#include <_mpi.h>

int
MPI_Close_port (char *port_name)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Close_port")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Close_port",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Close_port) (char *port_name) = address;
  mpi_return = (*VendorMPI_Close_port)(port_name);
  return mpi_return;
}
