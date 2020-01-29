
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_delete_attr
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_DELETE_ATTR() __attribute__ ((weak, alias("iscf_win_delete_attr")));
void mpi_win_delete_attr() __attribute__ ((weak, alias("iscf_win_delete_attr")));
void mpi_win_delete_attr_() __attribute__ ((weak, alias("iscf_win_delete_attr")));
void mpi_win_delete_attr__() __attribute__ ((weak, alias("iscf_win_delete_attr")));
#endif

void iscf_win_delete_attr(int *win, int *win_keyval, int *ierr)
{
    *ierr = MPI_Win_delete_attr (*win, *win_keyval);
}
