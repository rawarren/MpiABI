
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Errhandler_create
 */

#include <_mpi.h>

int
MPI_Errhandler_create (MPI_Handler_function *function, MPI_Errhandler *errhandler)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Errhandler_create")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Errhandler_create",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *errhandler = new_index(active_errhandlers);
  if (active_errhandlers->use_ptrs) { api_use_ptrs *local_a0=active_errhandlers->api_declared;
    int (*VendorMPI_Errhandler_create)(MPI_Handler_function *function,void **) = address;
    mpi_return = (*VendorMPI_Errhandler_create)(function,&local_a0[*errhandler].mpi_const);
  } else { api_use_ints *local_a0=active_errhandlers->api_declared;
    int (*VendorMPI_Errhandler_create)(MPI_Handler_function *function,int *) = address;
    mpi_return = (*VendorMPI_Errhandler_create)(function,&local_a0[*errhandler].mpi_const);
  }
  return mpi_return;
}
