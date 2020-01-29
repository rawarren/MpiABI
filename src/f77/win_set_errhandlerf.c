
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_set_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_SET_ERRHANDLER() __attribute__ ((weak, alias("iscf_win_set_errhandler")));
void mpi_win_set_errhandler() __attribute__ ((weak, alias("iscf_win_set_errhandler")));
void mpi_win_set_errhandler_() __attribute__ ((weak, alias("iscf_win_set_errhandler")));
void mpi_win_set_errhandler__() __attribute__ ((weak, alias("iscf_win_set_errhandler")));
#endif

void iscf_win_set_errhandler(int *win, int *errhandler, int *ierr)
{
    *ierr = MPI_Win_set_errhandler (*win, *errhandler);
}
