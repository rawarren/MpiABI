
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_create_keyval
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_CREATE_KEYVAL() __attribute__ ((weak, alias("iscf_win_create_keyval")));
void mpi_win_create_keyval() __attribute__ ((weak, alias("iscf_win_create_keyval")));
void mpi_win_create_keyval_() __attribute__ ((weak, alias("iscf_win_create_keyval")));
void mpi_win_create_keyval__() __attribute__ ((weak, alias("iscf_win_create_keyval")));
#endif

void iscf_win_create_keyval(int *win_copy_attr_fn, int *win_delete_attr_fn, int *win_keyval,  void *extra_state, int *ierr)
{
  *ierr = MPI_Win_create_keyval ((MPI_Win_copy_attr_function *)win_copy_attr_fn,
				 (MPI_Win_delete_attr_function *) win_delete_attr_fn, win_keyval, extra_state);
}
