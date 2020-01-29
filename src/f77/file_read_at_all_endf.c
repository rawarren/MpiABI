
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_read_at_all_end
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_READ_AT_ALL_END() __attribute__ ((weak, alias("iscf_file_read_at_all_end")));
void mpi_file_read_at_all_end() __attribute__ ((weak, alias("iscf_file_read_at_all_end")));
void mpi_file_read_at_all_end_() __attribute__ ((weak, alias("iscf_file_read_at_all_end")));
void mpi_file_read_at_all_end__() __attribute__ ((weak, alias("iscf_file_read_at_all_end")));
#endif

void iscf_file_read_at_all_end(int *fh, void *buf, int *status, int *ierr)
{
    *ierr = MPI_File_read_at_all_end (*fh, buf, (MPI_Status *)status);
}
