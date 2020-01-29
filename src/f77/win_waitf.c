
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_wait
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_WAIT() __attribute__ ((weak, alias("iscf_win_wait")));
void mpi_win_wait() __attribute__ ((weak, alias("iscf_win_wait")));
void mpi_win_wait_() __attribute__ ((weak, alias("iscf_win_wait")));
void mpi_win_wait__() __attribute__ ((weak, alias("iscf_win_wait")));
#endif

void iscf_win_wait(int *win, int *ierr)
{
    *ierr = MPI_Win_wait (*win);
}
