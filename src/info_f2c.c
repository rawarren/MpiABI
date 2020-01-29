
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_f2c
 */

#include <_mpi.h>

MPI_Info
MPI_Info_f2c (MPI_Fint info)
{
#if 1
  return (MPI_Info) info;
#else
  static void *address=0;
  MPI_Info mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Info_f2c")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Info_f2c",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  MPI_Info (*VendorMPI_Info_f2c) (MPI_Fint info) = address;
  mpi_return = (*VendorMPI_Info_f2c)(info);
  return mpi_return;
#endif
}
