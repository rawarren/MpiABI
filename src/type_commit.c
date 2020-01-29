
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_commit
 */

#include <_mpi.h>

int
MPI_Type_commit (MPI_Datatype *type)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_commit")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_commit",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_commit)(void **) = address;
    mpi_return = (*VendorMPI_Type_commit)(&local_a0[*type].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_commit)(int *) = address;
    mpi_return = (*VendorMPI_Type_commit)(&local_a0[*type].mpi_const);
  }
  return mpi_return;
}
