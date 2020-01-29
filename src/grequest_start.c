
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Grequest_start
 */

#include <_mpi.h>

int
MPI_Grequest_start (MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Grequest_start")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Grequest_start",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *request = new_index(active_requests);
  if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
    int (*VendorMPI_Grequest_start)(MPI_Grequest_query_function *query_fn,MPI_Grequest_free_function *free_fn,MPI_Grequest_cancel_function *cancel_fn,void *extra_state,void **) = address;
    mpi_return = (*VendorMPI_Grequest_start)(query_fn,free_fn,cancel_fn,extra_state,&local_a0[*request].mpi_const);
  } else { api_use_ints *local_a0=active_requests->api_declared;
    int (*VendorMPI_Grequest_start)(MPI_Grequest_query_function *query_fn,MPI_Grequest_free_function *free_fn,MPI_Grequest_cancel_function *cancel_fn,void *extra_state,int *) = address;
    mpi_return = (*VendorMPI_Grequest_start)(query_fn,free_fn,cancel_fn,extra_state,&local_a0[*request].mpi_const);
  }
  return mpi_return;
}
