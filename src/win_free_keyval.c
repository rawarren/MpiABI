
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
    int mpi_return;
    api_use_ints *local_a0 = active_miscs->api_declared;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_free_keyval")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_free_keyval",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    int (*VendorMPI_Win_free_keyval) (int *win_keyval) = address;
    int native_keyval = local_a0[*win_keyval].mpi_const;
    mpi_return = (*VendorMPI_Win_free_keyval)(&native_keyval);
    if ((mpi_return == 0) && (native_keyval == local_a0[ISC_KEYVAL_INVALID_].mpi_const)) {
	if (attr_reference_exists(-1, *win_keyval,WIN_CALLBACK) == 0) {
	    free_index(active_miscs, *win_keyval);
	}
	*win_keyval = MPI_KEYVAL_INVALID;
    }
    return mpi_return;
}
