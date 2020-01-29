
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Dims_create
 */

#include <_mpi.h>

int
MPI_Dims_create (int nnodes, int ndims, int *dims)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Dims_create")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Dims_create",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Dims_create) (int nnodes, int ndims, int *dims) = address;
  mpi_return = (*VendorMPI_Dims_create)(nnodes,ndims,dims);
  return mpi_return;
}
