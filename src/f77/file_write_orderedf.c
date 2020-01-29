
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_write_ordered
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_WRITE_ORDERED() __attribute__ ((weak, alias("iscf_file_write_ordered")));
void mpi_file_write_ordered() __attribute__ ((weak, alias("iscf_file_write_ordered")));
void mpi_file_write_ordered_() __attribute__ ((weak, alias("iscf_file_write_ordered")));
void mpi_file_write_ordered__() __attribute__ ((weak, alias("iscf_file_write_ordered")));
#endif

void iscf_file_write_ordered(int *fh, void *buf, int *count, int *datatype, int *status, int *ierr)
{
    *ierr = MPI_File_write_ordered (*fh, buf, *count, *datatype, (MPI_Status *)status);
}
