
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_create_keyval
 */

#include <_mpi.h>

int
MPI_Win_create_keyval (MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_create_keyval")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_create_keyval",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    int (*VendorMPI_Win_create_keyval) (MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state) = address;
    mpi_return = (*VendorMPI_Win_create_keyval)(win_copy_attr_fn,win_delete_attr_fn,win_keyval,extra_state);
    return mpi_return;
}
