
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_lock
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_LOCK() __attribute__ ((weak, alias("iscf_win_lock")));
void mpi_win_lock() __attribute__ ((weak, alias("iscf_win_lock")));
void mpi_win_lock_() __attribute__ ((weak, alias("iscf_win_lock")));
void mpi_win_lock__() __attribute__ ((weak, alias("iscf_win_lock")));
#endif

void iscf_win_lock(int *lock_type, int *rank, int *assert, int *win, int *ierr)
{
    *ierr = MPI_Win_lock (*lock_type, *rank, *assert, *win);
}
