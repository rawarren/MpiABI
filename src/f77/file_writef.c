
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_write
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_WRITE() __attribute__ ((weak, alias("iscf_file_write")));
void mpi_file_write() __attribute__ ((weak, alias("iscf_file_write")));
void mpi_file_write_() __attribute__ ((weak, alias("iscf_file_write")));
void mpi_file_write__() __attribute__ ((weak, alias("iscf_file_write")));
#endif

void iscf_file_write(int *fh, void *buf, int *count, int *datatype, int *status, int *ierr)
{
    *ierr = MPI_File_write (*fh, buf, *count, *datatype, (MPI_Status *)status);
}
