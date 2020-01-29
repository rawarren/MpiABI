
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Op_f2c
 */

#include <_mpi.h>

MPI_Op
MPI_Op_f2c (MPI_Fint op)
{
#if 1
  return (MPI_Op) op;
#else
  static void *address=0;
  MPI_Op mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Op_f2c")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Op_f2c",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  MPI_Op (*VendorMPI_Op_f2c) (MPI_Fint op) = address;
  mpi_return = (*VendorMPI_Op_f2c)(op);
  return mpi_return;
#endif
}
