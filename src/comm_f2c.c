
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_f2c
 */

#include <_mpi.h>

MPI_Comm
MPI_Comm_f2c (MPI_Fint comm)
{
#if 1
  return (MPI_Comm) comm;
#else
  static void *address=0;
  MPI_Comm mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_f2c")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_f2c",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  MPI_Comm (*VendorMPI_Comm_f2c) (MPI_Fint comm) = address;
  mpi_return = (*VendorMPI_Comm_f2c)(comm);
  return mpi_return;
#endif
}
