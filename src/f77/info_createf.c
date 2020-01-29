
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_create
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INFO_CREATE() __attribute__ ((weak, alias("iscf_info_create")));
void mpi_info_create() __attribute__ ((weak, alias("iscf_info_create")));
void mpi_info_create_() __attribute__ ((weak, alias("iscf_info_create")));
void mpi_info_create__() __attribute__ ((weak, alias("iscf_info_create")));
#endif

void iscf_info_create(int *info, int *ierr)
{
    *ierr = MPI_Info_create (info);
}
