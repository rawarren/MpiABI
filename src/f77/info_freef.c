
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_free
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INFO_FREE() __attribute__ ((weak, alias("iscf_info_free")));
void mpi_info_free() __attribute__ ((weak, alias("iscf_info_free")));
void mpi_info_free_() __attribute__ ((weak, alias("iscf_info_free")));
void mpi_info_free__() __attribute__ ((weak, alias("iscf_info_free")));
#endif

void iscf_info_free(int *info, int *ierr)
{
    *ierr = MPI_Info_free (info);
}
