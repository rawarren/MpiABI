
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Op_commutative
 */

#include <_mpi.h>

int
MPI_Op_commutative (MPI_Op op, int *commute)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Op_commutative")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Op_commutative",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (active_ops->use_ptrs) { api_use_ptrs *local_a0=active_ops->api_declared;
      int (*VendorMPI_Op_commutative) (void *, int *) = address;
      mpi_return = (*VendorMPI_Op_commutative)(local_a0[op].mpi_const, commute);
  } else { api_use_ints *local_a0=active_ops->api_declared;
      int (*VendorMPI_Op_commutative) (int, int *) = address;
      mpi_return = (*VendorMPI_Op_commutative)(local_a0[op].mpi_const, commute);
  }
  return mpi_return;
}
