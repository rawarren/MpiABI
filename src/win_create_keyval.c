
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
    api_use_ints *local_a0 = active_miscs->api_declared;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_create_keyval")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_create_keyval",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    *win_keyval = new_index(active_miscs);
    
    int (*VendorMPI_Win_create_keyval) (MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state) = address;
    mpi_return = (*VendorMPI_Win_create_keyval)(NULLWINCOPYFN(win_copy_attr_fn),NULLWINDELFN(win_delete_attr_fn),&local_a0[*win_keyval].mpi_const,extra_state);
    if (win_copy_attr_fn != MPI_NULL_COPY_FN) {
      save_user_copy_callback(win_copy_attr_fn,*win_keyval,WIN_CALLBACK);
    }
    if (win_delete_attr_fn != MPI_NULL_DELETE_FN) {
      save_user_delete_callback(win_delete_attr_fn,*win_keyval,WIN_CALLBACK);
    }

    return mpi_return;
}
