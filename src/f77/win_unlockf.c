
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_unlock
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_UNLOCK() __attribute__ ((weak, alias("iscf_win_unlock")));
void mpi_win_unlock() __attribute__ ((weak, alias("iscf_win_unlock")));
void mpi_win_unlock_() __attribute__ ((weak, alias("iscf_win_unlock")));
void mpi_win_unlock__() __attribute__ ((weak, alias("iscf_win_unlock")));
#endif

void iscf_win_unlock(int *rank, int *win, int *ierr)
{
    *ierr = MPI_Win_unlock (*rank, *win);
}
