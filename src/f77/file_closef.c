
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_close
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_CLOSE() __attribute__ ((weak, alias("iscf_file_close")));
void mpi_file_close() __attribute__ ((weak, alias("iscf_file_close")));
void mpi_file_close_() __attribute__ ((weak, alias("iscf_file_close")));
void mpi_file_close__() __attribute__ ((weak, alias("iscf_file_close")));
#endif

void iscf_file_close(int *fh, int *ierr)
{
    *ierr = MPI_File_close (fh);
}
