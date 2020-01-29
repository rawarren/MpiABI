
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_write_ordered_end
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_WRITE_ORDERED_END() __attribute__ ((weak, alias("iscf_file_write_ordered_end")));
void mpi_file_write_ordered_end() __attribute__ ((weak, alias("iscf_file_write_ordered_end")));
void mpi_file_write_ordered_end_() __attribute__ ((weak, alias("iscf_file_write_ordered_end")));
void mpi_file_write_ordered_end__() __attribute__ ((weak, alias("iscf_file_write_ordered_end")));
#endif

void iscf_file_write_ordered_end(int *fh, void *buf, int *status, int *ierr)
{
    *ierr = MPI_File_write_ordered_end (*fh, buf, (MPI_Status *)status);
}
