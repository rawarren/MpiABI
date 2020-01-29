
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_free_keyval
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_FREE_KEYVAL() __attribute__ ((weak, alias("iscf_win_free_keyval")));
void mpi_win_free_keyval() __attribute__ ((weak, alias("iscf_win_free_keyval")));
void mpi_win_free_keyval_() __attribute__ ((weak, alias("iscf_win_free_keyval")));
void mpi_win_free_keyval__() __attribute__ ((weak, alias("iscf_win_free_keyval")));
#endif

void iscf_win_free_keyval(int *win_keyval, int *ierr)
{
    *ierr = MPI_Win_free_keyval (win_keyval);
}
