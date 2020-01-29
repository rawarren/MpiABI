
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_create
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_CREATE() __attribute__ ((weak, alias("iscf_win_create")));
void mpi_win_create() __attribute__ ((weak, alias("iscf_win_create")));
void mpi_win_create_() __attribute__ ((weak, alias("iscf_win_create")));
void mpi_win_create__() __attribute__ ((weak, alias("iscf_win_create")));
#endif

void iscf_win_create(void *base, MPI_Aint *size, int *disp_unit, int *info, int *comm, int *win, int *ierr)
{
    *ierr = MPI_Win_create (base, *size, *disp_unit, *info, *comm, win);
}
