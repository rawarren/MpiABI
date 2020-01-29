
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_iwrite_at
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_IWRITE_AT() __attribute__ ((weak, alias("iscf_file_iwrite_at")));
void mpi_file_iwrite_at() __attribute__ ((weak, alias("iscf_file_iwrite_at")));
void mpi_file_iwrite_at_() __attribute__ ((weak, alias("iscf_file_iwrite_at")));
void mpi_file_iwrite_at__() __attribute__ ((weak, alias("iscf_file_iwrite_at")));
#endif

void iscf_file_iwrite_at(int *fh, int *offset, void *buf, int *count, int *datatype, int *request, int *ierr)
{
    *ierr = MPI_File_iwrite_at (*fh, *offset, buf, *count, *datatype, request);
}
