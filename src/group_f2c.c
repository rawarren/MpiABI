
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_f2c
 */

#include <_mpi.h>

MPI_Group
MPI_Group_f2c (MPI_Fint group)
{
#if 1
  return (MPI_Group) group;
#else
  static void *address=0;
  MPI_Group mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Group_f2c")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Group_f2c",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  MPI_Group (*VendorMPI_Group_f2c) (MPI_Fint group) = address;
  mpi_return = (*VendorMPI_Group_f2c)(group);
  return mpi_return;
#endif
}
