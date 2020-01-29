
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_set_attr
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_SET_ATTR() __attribute__ ((weak, alias("iscf_win_set_attr")));
void mpi_win_set_attr() __attribute__ ((weak, alias("iscf_win_set_attr")));
void mpi_win_set_attr_() __attribute__ ((weak, alias("iscf_win_set_attr")));
void mpi_win_set_attr__() __attribute__ ((weak, alias("iscf_win_set_attr")));
#endif

void iscf_win_set_attr(int *win, int *win_keyval,  void *attribute_val, int *ierr)
{
    *ierr = MPI_Win_set_attr (*win, *win_keyval, attribute_val);
}
