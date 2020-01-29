
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_seek
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_SEEK() __attribute__ ((weak, alias("iscf_file_seek")));
void mpi_file_seek() __attribute__ ((weak, alias("iscf_file_seek")));
void mpi_file_seek_() __attribute__ ((weak, alias("iscf_file_seek")));
void mpi_file_seek__() __attribute__ ((weak, alias("iscf_file_seek")));
#endif

void iscf_file_seek(int *fh, int *offset, int *whence, int *ierr)
{
    *ierr = MPI_File_seek (*fh, *offset, *whence);
}
