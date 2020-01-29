
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_read_all_begin
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_READ_ALL_BEGIN() __attribute__ ((weak, alias("iscf_file_read_all_begin")));
void mpi_file_read_all_begin() __attribute__ ((weak, alias("iscf_file_read_all_begin")));
void mpi_file_read_all_begin_() __attribute__ ((weak, alias("iscf_file_read_all_begin")));
void mpi_file_read_all_begin__() __attribute__ ((weak, alias("iscf_file_read_all_begin")));
#endif

void iscf_file_read_all_begin(int *fh, void *buf, int *count, int *datatype, int *ierr)
{
    *ierr = MPI_File_read_all_begin (*fh, buf, *count, *datatype);
}
