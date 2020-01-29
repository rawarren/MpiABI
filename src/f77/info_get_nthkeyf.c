
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_get_nthkey
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INFO_GET_NTHKEY() __attribute__ ((weak, alias("iscf_info_get_nthkey")));
void mpi_info_get_nthkey() __attribute__ ((weak, alias("iscf_info_get_nthkey")));
void mpi_info_get_nthkey_() __attribute__ ((weak, alias("iscf_info_get_nthkey")));
void mpi_info_get_nthkey__() __attribute__ ((weak, alias("iscf_info_get_nthkey")));
#endif

void iscf_info_get_nthkey(int *info, int *n,  char *key, int *ierr)
{
    *ierr = MPI_Info_get_nthkey (*info, *n, key);
}
