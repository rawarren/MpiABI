
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_test
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_TEST() __attribute__ ((weak, alias("iscf_win_test")));
void mpi_win_test() __attribute__ ((weak, alias("iscf_win_test")));
void mpi_win_test_() __attribute__ ((weak, alias("iscf_win_test")));
void mpi_win_test__() __attribute__ ((weak, alias("iscf_win_test")));
#endif

void iscf_win_test(int *win, int *flag, int *ierr)
{
    *ierr = MPI_Win_test (*win, flag);
}
