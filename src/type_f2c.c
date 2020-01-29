
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_f2c
 */

#include <_mpi.h>

MPI_Datatype
MPI_Type_f2c (MPI_Fint datatype)
{
#if 1
  return (MPI_Datatype) datatype;
#else
  static void *address=0;
  MPI_Datatype mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_f2c")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_f2c",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  MPI_Datatype (*VendorMPI_Type_f2c) (MPI_Fint datatype) = address;
  mpi_return = (*VendorMPI_Type_f2c)(datatype);
  return mpi_return;
#endif
}
