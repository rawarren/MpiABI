
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get_version
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GET_VERSION() __attribute__ ((weak, alias("iscf_get_version")));
void mpi_get_version() __attribute__ ((weak, alias("iscf_get_version")));
void mpi_get_version_() __attribute__ ((weak, alias("iscf_get_version")));
void mpi_get_version__() __attribute__ ((weak, alias("iscf_get_version")));
#endif

void iscf_get_version(int *version, int *subversion, int *ierr)
{
    *ierr = MPI_Get_version (version, subversion);
}
