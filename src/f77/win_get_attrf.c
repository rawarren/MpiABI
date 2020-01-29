
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_get_attr
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_GET_ATTR() __attribute__ ((weak, alias("iscf_win_get_attr")));
void mpi_win_get_attr() __attribute__ ((weak, alias("iscf_win_get_attr")));
void mpi_win_get_attr_() __attribute__ ((weak, alias("iscf_win_get_attr")));
void mpi_win_get_attr__() __attribute__ ((weak, alias("iscf_win_get_attr")));
#endif

void iscf_win_get_attr(int *win, int *win_keyval, void *attribute_val, int *flag, int *ierr)
{
    *ierr = MPI_Win_get_attr (*win, *win_keyval, attribute_val, flag);
}
