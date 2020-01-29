
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_get_group
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_GET_GROUP() __attribute__ ((weak, alias("iscf_win_get_group")));
void mpi_win_get_group() __attribute__ ((weak, alias("iscf_win_get_group")));
void mpi_win_get_group_() __attribute__ ((weak, alias("iscf_win_get_group")));
void mpi_win_get_group__() __attribute__ ((weak, alias("iscf_win_get_group")));
#endif

void iscf_win_get_group(int *win, int *group, int *ierr)
{
    *ierr = MPI_Win_get_group (*win, group);
}
