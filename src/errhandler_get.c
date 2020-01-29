
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Errhandler_get
 */

#include <_mpi.h>

int
MPI_Errhandler_get (MPI_Comm comm, MPI_Errhandler *errhandler)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Errhandler_get")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Errhandler_get",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *errhandler = new_index(active_errhandlers);
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1=active_errhandlers->api_declared;
    int (*VendorMPI_Errhandler_get)(void *,void **) = address;
    mpi_return = (*VendorMPI_Errhandler_get)(local_a0[comm].mpi_const,&local_a1[*errhandler].mpi_const);
    if (local_a1[*errhandler].mpi_const == local_a1[MPI_ERRHANDLER_NULL].mpi_const) {
      free_index(active_errhandlers,*errhandler);
      *errhandler = MPI_ERRHANDLER_NULL;
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1=active_errhandlers->api_declared;
    int (*VendorMPI_Errhandler_get)(int,int *) = address;
    mpi_return = (*VendorMPI_Errhandler_get)(local_a0[comm].mpi_const,&local_a1[*errhandler].mpi_const);
    if (local_a1[*errhandler].mpi_const == local_a1[MPI_ERRHANDLER_NULL].mpi_const) {
      free_index(active_errhandlers,*errhandler);
      *errhandler = MPI_ERRHANDLER_NULL;
    }
  }
  return mpi_return;
}
