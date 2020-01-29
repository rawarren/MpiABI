
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_get
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INFO_GET() __attribute__ ((weak, alias("iscf_info_get")));
void mpi_info_get() __attribute__ ((weak, alias("iscf_info_get")));
void mpi_info_get_() __attribute__ ((weak, alias("iscf_info_get")));
void mpi_info_get__() __attribute__ ((weak, alias("iscf_info_get")));
#endif

void iscf_info_get(int *info, char *key, int *valuelen, char *value, int *flag, int *ierr)
{
    *ierr = MPI_Info_get (*info, key, *valuelen, value, flag);
}
