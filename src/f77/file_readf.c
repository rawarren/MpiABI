
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_read
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_READ() __attribute__ ((weak, alias("iscf_file_read")));
void mpi_file_read() __attribute__ ((weak, alias("iscf_file_read")));
void mpi_file_read_() __attribute__ ((weak, alias("iscf_file_read")));
void mpi_file_read__() __attribute__ ((weak, alias("iscf_file_read")));
#endif

void iscf_file_read(int *fh, void *buf, int *count, int *datatype, int *status, int *ierr)
{
    *ierr = MPI_File_read (*fh, buf, *count, *datatype, (MPI_Status *)status);
}
