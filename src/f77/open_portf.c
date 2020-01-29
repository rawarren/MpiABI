
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Open_port
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_OPEN_PORT() __attribute__ ((weak, alias("iscf_open_port")));
void mpi_open_port() __attribute__ ((weak, alias("iscf_open_port")));
void mpi_open_port_() __attribute__ ((weak, alias("iscf_open_port")));
void mpi_open_port__() __attribute__ ((weak, alias("iscf_open_port")));
#endif

void iscf_open_port(int *info,  char *port_name, int *ierr)
{
    *ierr = MPI_Open_port (*info, port_name);
}
