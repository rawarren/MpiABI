
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_set
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INFO_SET() __attribute__ ((weak, alias("iscf_info_set")));
void mpi_info_set() __attribute__ ((weak, alias("iscf_info_set")));
void mpi_info_set_() __attribute__ ((weak, alias("iscf_info_set")));
void mpi_info_set__() __attribute__ ((weak, alias("iscf_info_set")));
#endif

void iscf_info_set(int *info, char *key,  char *value, int *ierr)
{
    *ierr = MPI_Info_set (*info, key, value);
}
