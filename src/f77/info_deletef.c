
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_delete
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INFO_DELETE() __attribute__ ((weak, alias("iscf_info_delete")));
void mpi_info_delete() __attribute__ ((weak, alias("iscf_info_delete")));
void mpi_info_delete_() __attribute__ ((weak, alias("iscf_info_delete")));
void mpi_info_delete__() __attribute__ ((weak, alias("iscf_info_delete")));
#endif

void iscf_info_delete(int *info,  char *key, int *ierr)
{
    *ierr = MPI_Info_delete (*info, key);
}
