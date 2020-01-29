
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_disconnect
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_DISCONNECT() __attribute__ ((weak, alias("iscf_comm_disconnect")));
void mpi_comm_disconnect() __attribute__ ((weak, alias("iscf_comm_disconnect")));
void mpi_comm_disconnect_() __attribute__ ((weak, alias("iscf_comm_disconnect")));
void mpi_comm_disconnect__() __attribute__ ((weak, alias("iscf_comm_disconnect")));
#endif

void iscf_comm_disconnect(int *comm, int *ierr)
{
    *ierr = MPI_Comm_disconnect (comm);
}
