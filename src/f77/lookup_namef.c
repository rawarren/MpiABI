
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Lookup_name
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_LOOKUP_NAME() __attribute__ ((weak, alias("iscf_lookup_name")));
void mpi_lookup_name() __attribute__ ((weak, alias("iscf_lookup_name")));
void mpi_lookup_name_() __attribute__ ((weak, alias("iscf_lookup_name")));
void mpi_lookup_name__() __attribute__ ((weak, alias("iscf_lookup_name")));
#endif

void iscf_lookup_name(char *service_name, int *info,  char *port_name, int *ierr)
{
    *ierr = MPI_Lookup_name (service_name, *info, port_name);
}
