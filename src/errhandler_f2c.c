
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Errhandler_f2c
 */

#include <_mpi.h>

MPI_Errhandler
MPI_Errhandler_f2c (MPI_Fint errhandler)
{
#if 1
  return (MPI_Errhandler) errhandler;
#else
  static void *address=0;
  MPI_Errhandler mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Errhandler_f2c")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Errhandler_f2c",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  MPI_Errhandler (*VendorMPI_Errhandler_f2c) (MPI_Fint errhandler) = address;
  mpi_return = (*VendorMPI_Errhandler_f2c)(errhandler);
  return mpi_return;
#endif
}
