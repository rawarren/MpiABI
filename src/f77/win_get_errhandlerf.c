
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_get_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_GET_ERRHANDLER() __attribute__ ((weak, alias("iscf_win_get_errhandler")));
void mpi_win_get_errhandler() __attribute__ ((weak, alias("iscf_win_get_errhandler")));
void mpi_win_get_errhandler_() __attribute__ ((weak, alias("iscf_win_get_errhandler")));
void mpi_win_get_errhandler__() __attribute__ ((weak, alias("iscf_win_get_errhandler")));
#endif

void iscf_win_get_errhandler(int *win, int *errhandler, int *ierr)
{
    *ierr = MPI_Win_get_errhandler (*win, errhandler);
}
