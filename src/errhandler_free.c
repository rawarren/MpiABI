
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Errhandler_free
 */

#include <_mpi.h>

int maybe_free_errhandler_intercept(MPI_Errhandler eh);


int
MPI_Errhandler_free (MPI_Errhandler *errhandler)
{
  static void *address=0;
  int mpi_return = 0;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Errhandler_free")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Errhandler_free",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_errhandlers->use_ptrs) { api_use_ptrs *local_a0=active_errhandlers->api_declared;
      int (*VendorMPI_Errhandler_free)(void **) = address;
      void * vendor_value = local_a0[*errhandler].mpi_const;
      mpi_return = (*VendorMPI_Errhandler_free)(&vendor_value);
      *errhandler = get_index(active_errhandlers,(void *)&vendor_value);
      /* Don't try to free a predefined error handler... */
      if (*errhandler >= active_errhandlers->permlimit) {
	  maybe_free_errhandler_intercept(*errhandler);
	  free_index(active_errhandlers,*errhandler);
      }
#if 0
    int (*VendorMPI_Errhandler_free)(void **) = address;
    mpi_return = (*VendorMPI_Errhandler_free)(&local_a0[*errhandler].mpi_const);
    /* Don't try to free a predefined error handler... */
    if (*errhandler >= active_errhandlers->permlimit) {
	maybe_free_errhandler_intercept(*errhandler);
	if ((*errhandler >= active_errhandlers->permlimit) && (local_a0[*errhandler].mpi_const == local_a0[MPI_ERRHANDLER_NULL].mpi_const)) {
	    free_index(active_errhandlers,*errhandler);
	}
    }
    *errhandler = MPI_ERRHANDLER_NULL;
#endif
  } else { api_use_ints *local_a0=active_errhandlers->api_declared;
      int (*VendorMPI_Errhandler_free)(int *) = address;
      int vendor_value = local_a0[*errhandler].mpi_const;
      mpi_return = (*VendorMPI_Errhandler_free)(&vendor_value);
      *errhandler = get_index(active_errhandlers,(void *)&vendor_value);
      /* Don't try to free a predefined error handler... */
      if (*errhandler >= active_errhandlers->permlimit) {
	  maybe_free_errhandler_intercept(*errhandler);
	  free_index(active_errhandlers,*errhandler);
      }
  }
  return mpi_return;
}
