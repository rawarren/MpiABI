
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_accept
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_ACCEPT() __attribute__ ((weak, alias("iscf_comm_accept")));
void mpi_comm_accept() __attribute__ ((weak, alias("iscf_comm_accept")));
void mpi_comm_accept_() __attribute__ ((weak, alias("iscf_comm_accept")));
void mpi_comm_accept__() __attribute__ ((weak, alias("iscf_comm_accept")));
#endif

void iscf_comm_accept(char *port_name, int *info, int *root, int *comm, int *newcomm, int *ierr)
{
    *ierr = MPI_Comm_accept (port_name, *info, *root, *comm, newcomm);
}
