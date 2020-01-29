
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_amode
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_AMODE() __attribute__ ((weak, alias("iscf_file_get_amode")));
void mpi_file_get_amode() __attribute__ ((weak, alias("iscf_file_get_amode")));
void mpi_file_get_amode_() __attribute__ ((weak, alias("iscf_file_get_amode")));
void mpi_file_get_amode__() __attribute__ ((weak, alias("iscf_file_get_amode")));
#endif

void iscf_file_get_amode(int *fh, int *amode, int *ierr)
{
    *ierr = MPI_File_get_amode (*fh, amode);
}
