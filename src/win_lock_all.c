
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_lock
 */

#include <_mpi.h>

int
MPI_Win_lock_all (int assert, MPI_Win win)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_lock_all")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_lock_all",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
        int (*VendorMPI_Win_lock_all)(int, void *) = address;
        mpi_return = (*VendorMPI_Win_lock_all)(assert,local_a0[win].mpi_const);
    } else { api_use_ints *local_a0=active_wins->api_declared;
        int (*VendorMPI_Win_lock_all)(int, int) = address;
        mpi_return = (*VendorMPI_Win_lock_all)(assert,local_a0[win].mpi_const);
    }
    return mpi_return;
}
