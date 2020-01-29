
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_set_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_SET_ERRHANDLER() __attribute__ ((weak, alias("iscf_comm_set_errhandler")));
void mpi_comm_set_errhandler() __attribute__ ((weak, alias("iscf_comm_set_errhandler")));
void mpi_comm_set_errhandler_() __attribute__ ((weak, alias("iscf_comm_set_errhandler")));
void mpi_comm_set_errhandler__() __attribute__ ((weak, alias("iscf_comm_set_errhandler")));
#endif

void iscf_comm_set_errhandler(int *comm, int *errhandler, int *ierr)
{
    *ierr = MPI_Comm_set_errhandler (*comm, *errhandler);
}
