
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_complete
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_COMPLETE() __attribute__ ((weak, alias("iscf_win_complete")));
void mpi_win_complete() __attribute__ ((weak, alias("iscf_win_complete")));
void mpi_win_complete_() __attribute__ ((weak, alias("iscf_win_complete")));
void mpi_win_complete__() __attribute__ ((weak, alias("iscf_win_complete")));
#endif

void iscf_win_complete(int *win, int *ierr)
{
    *ierr = MPI_Win_complete (*win);
}
