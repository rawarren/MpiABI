
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_get_name
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_GET_NAME() __attribute__ ((weak, alias("iscf_win_get_name")));
void mpi_win_get_name() __attribute__ ((weak, alias("iscf_win_get_name")));
void mpi_win_get_name_() __attribute__ ((weak, alias("iscf_win_get_name")));
void mpi_win_get_name__() __attribute__ ((weak, alias("iscf_win_get_name")));
#endif

void iscf_win_get_name(int *win, char *win_name, int *resultlen, int *ierr)
{
    *ierr = MPI_Win_get_name (*win, win_name, resultlen);
}
