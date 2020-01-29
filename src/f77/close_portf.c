
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Close_port
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_CLOSE_PORT() __attribute__ ((weak, alias("iscf_close_port")));
void mpi_close_port() __attribute__ ((weak, alias("iscf_close_port")));
void mpi_close_port_() __attribute__ ((weak, alias("iscf_close_port")));
void mpi_close_port__() __attribute__ ((weak, alias("iscf_close_port")));
#endif

void iscf_close_port(char *port_name, int *ierr)
{
    *ierr = MPI_Close_port (port_name);
}
