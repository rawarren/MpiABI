
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_start
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_START() __attribute__ ((weak, alias("iscf_win_start")));
void mpi_win_start() __attribute__ ((weak, alias("iscf_win_start")));
void mpi_win_start_() __attribute__ ((weak, alias("iscf_win_start")));
void mpi_win_start__() __attribute__ ((weak, alias("iscf_win_start")));
#endif

void iscf_win_start(int *group, int *assert, int *win, int *ierr)
{
    *ierr = MPI_Win_start (*group, *assert, *win);
}
