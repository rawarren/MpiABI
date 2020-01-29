
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_get_valuelen
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INFO_GET_VALUELEN() __attribute__ ((weak, alias("iscf_info_get_valuelen")));
void mpi_info_get_valuelen() __attribute__ ((weak, alias("iscf_info_get_valuelen")));
void mpi_info_get_valuelen_() __attribute__ ((weak, alias("iscf_info_get_valuelen")));
void mpi_info_get_valuelen__() __attribute__ ((weak, alias("iscf_info_get_valuelen")));
#endif

void iscf_info_get_valuelen(int *info, char *key, int *valuelen, int *flag, int *ierr)
{
    *ierr = MPI_Info_get_valuelen (*info, key, valuelen, flag);
}
