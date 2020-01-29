
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_call_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_CALL_ERRHANDLER() __attribute__ ((weak, alias("iscf_comm_call_errhandler")));
void mpi_comm_call_errhandler() __attribute__ ((weak, alias("iscf_comm_call_errhandler")));
void mpi_comm_call_errhandler_() __attribute__ ((weak, alias("iscf_comm_call_errhandler")));
void mpi_comm_call_errhandler__() __attribute__ ((weak, alias("iscf_comm_call_errhandler")));
#endif

void iscf_comm_call_errhandler(int *comm, int *errorcode, int *ierr)
{
    *ierr = MPI_Comm_call_errhandler (*comm, *errorcode);
}
