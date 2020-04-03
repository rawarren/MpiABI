
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_attach
 */

#include <_mpi.h>

int
MPI_Win_attach (MPI_Win win, void *base, MPI_Aint size)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_attach")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_attach",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
	int (*VendorMPI_Win_attach)(void *, void *, MPI_Aint) = address;
	mpi_return = (*VendorMPI_Win_attach)(local_a0[win].mpi_const, base, size);
    } else { api_use_ints *local_a0=active_wins->api_declared;
	int (*VendorMPI_Win_attach)(int, void *, MPI_Aint) = address;
	mpi_return = (*VendorMPI_Win_attach)(local_a0[win].mpi_const, base, size);
    }
    return mpi_return;
}
