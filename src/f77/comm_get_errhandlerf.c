
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_get_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_GET_ERRHANDLER() __attribute__ ((weak, alias("iscf_comm_get_errhandler")));
void mpi_comm_get_errhandler() __attribute__ ((weak, alias("iscf_comm_get_errhandler")));
void mpi_comm_get_errhandler_() __attribute__ ((weak, alias("iscf_comm_get_errhandler")));
void mpi_comm_get_errhandler__() __attribute__ ((weak, alias("iscf_comm_get_errhandler")));
#endif

void iscf_comm_get_errhandler(int *comm, int *erhandler, int *ierr)
{
  *ierr = MPI_Comm_get_errhandler ((MPI_Comm)*comm, (MPI_Errhandler *)erhandler);
}
