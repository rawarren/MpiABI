
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_free
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_FREE() __attribute__ ((weak, alias("iscf_win_free")));
void mpi_win_free() __attribute__ ((weak, alias("iscf_win_free")));
void mpi_win_free_() __attribute__ ((weak, alias("iscf_win_free")));
void mpi_win_free__() __attribute__ ((weak, alias("iscf_win_free")));
#endif

void iscf_win_free(int *win, int *ierr)
{
    *ierr = MPI_Win_free (win);
}
