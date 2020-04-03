
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_sync
 */

#include <_mpi.h>

int
MPI_Win_sync (MPI_Win win)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_sync")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_sync",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
      int (*VendorMPI_Win_sync)(void *) = address;
      mpi_return = (*VendorMPI_Win_sync)(local_a0[win].mpi_const);
    } else { api_use_ints *local_a0=active_wins->api_declared;
      int (*VendorMPI_Win_sync)(int) = address;
      mpi_return = (*VendorMPI_Win_sync)(local_a0[win].mpi_const);
    }
    return mpi_return;
}
