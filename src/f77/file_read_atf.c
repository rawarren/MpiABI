
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_read_at
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_READ_AT() __attribute__ ((weak, alias("iscf_file_read_at")));
void mpi_file_read_at() __attribute__ ((weak, alias("iscf_file_read_at")));
void mpi_file_read_at_() __attribute__ ((weak, alias("iscf_file_read_at")));
void mpi_file_read_at__() __attribute__ ((weak, alias("iscf_file_read_at")));
#endif

void iscf_file_read_at(int *fh, int *offset, void *buf, int *count, int *datatype, int *status, int *ierr)
{
    *ierr = MPI_File_read_at (*fh, *offset, buf, *count, *datatype, (MPI_Status *)status);
}
