
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_create_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WIN_CREATE_ERRHANDLER() __attribute__ ((weak, alias("iscf_win_create_errhandler")));
void mpi_win_create_errhandler() __attribute__ ((weak, alias("iscf_win_create_errhandler")));
void mpi_win_create_errhandler_() __attribute__ ((weak, alias("iscf_win_create_errhandler")));
void mpi_win_create_errhandler__() __attribute__ ((weak, alias("iscf_win_create_errhandler")));
#endif

void iscf_win_create_errhandler(int *function, int *errhandler, int *ierr)
{
  *ierr = MPI_Win_create_errhandler ((MPI_Win_errhandler_function *)function, (MPI_Errhandler *)errhandler);
}
