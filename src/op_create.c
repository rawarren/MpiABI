
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Op_create
 */

#include <_mpi.h>

int
MPI_Op_create (MPI_User_function *function, int commute, MPI_Op *op)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Op_create")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Op_create",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *op = new_index(active_ops);
  if (active_ops->use_ptrs) { api_use_ptrs *local_a0=active_ops->api_declared;
    int (*VendorMPI_Op_create)(MPI_User_function *function,int commute,void **) = address;
    mpi_return = (*VendorMPI_Op_create)(function,commute,&local_a0[*op].mpi_const);
  } else { api_use_ints *local_a0=active_ops->api_declared;
    int (*VendorMPI_Op_create)(MPI_User_function *function,int commute,int *) = address;
    mpi_return = (*VendorMPI_Op_create)(function,commute,&local_a0[*op].mpi_const);
  }
  return mpi_return;
}
