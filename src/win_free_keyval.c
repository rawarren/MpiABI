
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_free_keyval
 */

#include <_mpi.h>

int
MPI_Win_free_keyval (int *win_keyval)
{
    static void *address=0;
    int native_keyval;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_free_keyval")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_free_keyval",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    int (*VendorMPI_Win_free_keyval) (int *win_keyval) = address;
    mpi_return = (*VendorMPI_Win_free_keyval)(win_keyval);
    if (mpi_return == 0) {
	*win_keyval = MPI_KEYVAL_INVALID;
    }
    return mpi_return;
}
