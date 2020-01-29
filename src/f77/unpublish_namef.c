
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Unpublish_name
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_UNPUBLISH_NAME() __attribute__ ((weak, alias("iscf_unpublish_name")));
void mpi_unpublish_name() __attribute__ ((weak, alias("iscf_unpublish_name")));
void mpi_unpublish_name_() __attribute__ ((weak, alias("iscf_unpublish_name")));
void mpi_unpublish_name__() __attribute__ ((weak, alias("iscf_unpublish_name")));
#endif

void iscf_unpublish_name(char *service_name, int *info,  char *port_name, int *ierr)
{
    *ierr = MPI_Unpublish_name (service_name, *info, port_name);
}
