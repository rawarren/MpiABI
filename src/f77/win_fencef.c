
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_fence
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_FENCE() __attribute__ ((weak, alias("iscf_win_fence")));
void mpi_win_fence() __attribute__ ((weak, alias("iscf_win_fence")));
void mpi_win_fence_() __attribute__ ((weak, alias("iscf_win_fence")));
void mpi_win_fence__() __attribute__ ((weak, alias("iscf_win_fence")));
#endif

void iscf_win_fence(int *assert, int *win, int *ierr)
{
    *ierr = MPI_Win_fence (*assert, *win);
}
