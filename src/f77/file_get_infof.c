
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_info
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_INFO() __attribute__ ((weak, alias("iscf_file_get_info")));
void mpi_file_get_info() __attribute__ ((weak, alias("iscf_file_get_info")));
void mpi_file_get_info_() __attribute__ ((weak, alias("iscf_file_get_info")));
void mpi_file_get_info__() __attribute__ ((weak, alias("iscf_file_get_info")));
#endif

void iscf_file_get_info(int *fh, int *info_used, int *ierr)
{
    *ierr = MPI_File_get_info (*fh, info_used);
}
