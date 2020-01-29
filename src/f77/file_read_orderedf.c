
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_read_ordered
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_READ_ORDERED() __attribute__ ((weak, alias("iscf_file_read_ordered")));
void mpi_file_read_ordered() __attribute__ ((weak, alias("iscf_file_read_ordered")));
void mpi_file_read_ordered_() __attribute__ ((weak, alias("iscf_file_read_ordered")));
void mpi_file_read_ordered__() __attribute__ ((weak, alias("iscf_file_read_ordered")));
#endif

void iscf_file_read_ordered(int *fh, void *buf, int *count, int *datatype, int *status, int *ierr)
{
    *ierr = MPI_File_read_ordered (*fh, buf, *count, *datatype, (MPI_Status *)status);
}
