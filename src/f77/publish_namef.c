
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Publish_name
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_PUBLISH_NAME() __attribute__ ((weak, alias("iscf_publish_name")));
void mpi_publish_name() __attribute__ ((weak, alias("iscf_publish_name")));
void mpi_publish_name_() __attribute__ ((weak, alias("iscf_publish_name")));
void mpi_publish_name__() __attribute__ ((weak, alias("iscf_publish_name")));
#endif

void iscf_publish_name(char *service_name, int *info,  char *port_name, int *ierr)
{
    *ierr = MPI_Publish_name (service_name, *info, port_name);
}
