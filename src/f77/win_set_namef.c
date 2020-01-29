
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_set_name
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_SET_NAME() __attribute__ ((weak, alias("iscf_win_set_name")));
void mpi_win_set_name() __attribute__ ((weak, alias("iscf_win_set_name")));
void mpi_win_set_name_() __attribute__ ((weak, alias("iscf_win_set_name")));
void mpi_win_set_name__() __attribute__ ((weak, alias("iscf_win_set_name")));
#endif

void iscf_win_set_name(int *win,  char *win_name, int *ierr)
{
    *ierr = MPI_Win_set_name (*win, win_name);
}
