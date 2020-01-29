
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Op_free
 */

#include <_mpi.h>

int
MPI_Op_free (MPI_Op *op)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Op_free")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Op_free",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_ops->use_ptrs) { api_use_ptrs *local_a0=active_ops->api_declared;
    int (*VendorMPI_Op_free)(void **) = address;
    mpi_return = (*VendorMPI_Op_free)(&local_a0[*op].mpi_const);
    if (local_a0[*op].mpi_const == MPI_OP_NULL) {
      free_index(active_ops,*op);
      *op = MPI_OP_NULL;
    }
  } else { api_use_ints *local_a0=active_ops->api_declared;
    int (*VendorMPI_Op_free)(int *) = address;
    mpi_return = (*VendorMPI_Op_free)(&local_a0[*op].mpi_const);
    if (local_a0[*op].mpi_const == MPI_OP_NULL) {
      free_index(active_ops,*op);
      *op = MPI_OP_NULL;
    }
  }
  return mpi_return;
}
