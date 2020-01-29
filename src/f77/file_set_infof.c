
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_set_info
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_SET_INFO() __attribute__ ((weak, alias("iscf_file_set_info")));
void mpi_file_set_info() __attribute__ ((weak, alias("iscf_file_set_info")));
void mpi_file_set_info_() __attribute__ ((weak, alias("iscf_file_set_info")));
void mpi_file_set_info__() __attribute__ ((weak, alias("iscf_file_set_info")));
#endif

void iscf_file_set_info(int *fh, int *info, int *ierr)
{
    *ierr = MPI_File_set_info (*fh, *info);
}
