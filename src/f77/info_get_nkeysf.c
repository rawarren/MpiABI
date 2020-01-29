
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_get_nkeys
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INFO_GET_NKEYS() __attribute__ ((weak, alias("iscf_info_get_nkeys")));
void mpi_info_get_nkeys() __attribute__ ((weak, alias("iscf_info_get_nkeys")));
void mpi_info_get_nkeys_() __attribute__ ((weak, alias("iscf_info_get_nkeys")));
void mpi_info_get_nkeys__() __attribute__ ((weak, alias("iscf_info_get_nkeys")));
#endif

void iscf_info_get_nkeys(int *info, int *nkeys, int *ierr)
{
  *ierr = MPI_Info_get_nkeys ((MPI_Info)(*info), nkeys);
}
