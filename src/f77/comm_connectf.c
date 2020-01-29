
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_connect
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_CONNECT() __attribute__ ((weak, alias("iscf_comm_connect")));
void mpi_comm_connect() __attribute__ ((weak, alias("iscf_comm_connect")));
void mpi_comm_connect_() __attribute__ ((weak, alias("iscf_comm_connect")));
void mpi_comm_connect__() __attribute__ ((weak, alias("iscf_comm_connect")));
#endif

void iscf_comm_connect(char *port_name, int *info, int *root, int *comm, int *newcomm, int *ierr)
{
    *ierr = MPI_Comm_connect (port_name, *info, *root, *comm, newcomm);
}
