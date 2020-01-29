
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_post
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_POST() __attribute__ ((weak, alias("iscf_win_post")));
void mpi_win_post() __attribute__ ((weak, alias("iscf_win_post")));
void mpi_win_post_() __attribute__ ((weak, alias("iscf_win_post")));
void mpi_win_post__() __attribute__ ((weak, alias("iscf_win_post")));
#endif

void iscf_win_post(int *group, int *assert, int *win, int *ierr)
{
    *ierr = MPI_Win_post (*group, *assert, *win);
}
