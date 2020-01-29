
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_free
 */

#include <_mpi.h>

int
MPI_Win_free (MPI_Win *win)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_free")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_free",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
      int (*VendorMPI_Win_free)(void **) = address;
      mpi_return = (*VendorMPI_Win_free)(&local_a0[*win].mpi_const);
      free_index(active_wins,*win);
      *win = MPI_WIN_NULL;
    } else { api_use_ints *local_a0=active_wins->api_declared;
      int (*VendorMPI_Win_free)(int *) = address;
      mpi_return = (*VendorMPI_Win_free)(&local_a0[*win].mpi_const);
      free_index(active_wins,*win);
      *win = MPI_WIN_NULL;
    }
    return mpi_return;
}
