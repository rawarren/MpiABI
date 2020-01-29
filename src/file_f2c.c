
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_f2c
 */

#include <_mpi.h>

MPI_File
MPI_File_f2c (MPI_Fint file)
{
#if 1
  return (MPI_File) file;
#else
  static void *address=0;
  MPI_File mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_f2c")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_f2c",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  MPI_File (*VendorMPI_File_f2c) (MPI_Fint file) = address;
  mpi_return = (*VendorMPI_File_f2c)(file);
  return mpi_return;
#endif
}
