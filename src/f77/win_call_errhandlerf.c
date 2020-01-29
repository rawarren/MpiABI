
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_call_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_CALL_ERRHANDLER() __attribute__ ((weak, alias("iscf_win_call_errhandler")));
void mpi_win_call_errhandler() __attribute__ ((weak, alias("iscf_win_call_errhandler")));
void mpi_win_call_errhandler_() __attribute__ ((weak, alias("iscf_win_call_errhandler")));
void mpi_win_call_errhandler__() __attribute__ ((weak, alias("iscf_win_call_errhandler")));
#endif

void iscf_win_call_errhandler(int *win, int *errorcode, int *ierr)
{
    *ierr = MPI_Win_call_errhandler (*win, *errorcode);
}
