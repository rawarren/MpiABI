
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_seek_shared
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_SEEK_SHARED() __attribute__ ((weak, alias("iscf_file_seek_shared")));
void mpi_file_seek_shared() __attribute__ ((weak, alias("iscf_file_seek_shared")));
void mpi_file_seek_shared_() __attribute__ ((weak, alias("iscf_file_seek_shared")));
void mpi_file_seek_shared__() __attribute__ ((weak, alias("iscf_file_seek_shared")));
#endif

void iscf_file_seek_shared(int *fh, int *offset, int *whence, int *ierr)
{
    *ierr = MPI_File_seek_shared (*fh, *offset, *whence);
}
