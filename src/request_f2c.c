
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Request_f2c
 */

#include <_mpi.h>

MPI_Request
MPI_Request_f2c (MPI_Fint request)
{
#if 1
  return (MPI_Request) request;
#else
  static void *address=0;
  MPI_Request mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Request_f2c")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Request_f2c",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  MPI_Request (*VendorMPI_Request_f2c) (MPI_Fint request) = address;
  mpi_return = (*VendorMPI_Request_f2c)(request);
  return mpi_return;
#endif
}
