
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get_version
 */

#include <_mpi.h>

int
MPI_Get_version (int *version, int *subversion)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Get_version")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Get_version",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Get_version) (int *version, int *subversion) = address;
  mpi_return = (*VendorMPI_Get_version)(version,subversion);
  return mpi_return;
}

int
MPI_Get_library_version (char *version, int *length)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Get_library_version")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Get_library_version",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Get_library_version) (char *version, int *length) = address;
  mpi_return = (*VendorMPI_Get_library_version)(version,length);
  return mpi_return;
}
