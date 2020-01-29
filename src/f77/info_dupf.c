
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_dup
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INFO_DUP() __attribute__ ((weak, alias("iscf_info_dup")));
void mpi_info_dup() __attribute__ ((weak, alias("iscf_info_dup")));
void mpi_info_dup_() __attribute__ ((weak, alias("iscf_info_dup")));
void mpi_info_dup__() __attribute__ ((weak, alias("iscf_info_dup")));
#endif

void iscf_info_dup(int *info, int *newinfo, int *ierr)
{
  *ierr = MPI_Info_dup ((MPI_Info)(*info), (MPI_Info *)(newinfo));
}
