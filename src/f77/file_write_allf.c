
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_write_all
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_WRITE_ALL() __attribute__ ((weak, alias("iscf_file_write_all")));
void mpi_file_write_all() __attribute__ ((weak, alias("iscf_file_write_all")));
void mpi_file_write_all_() __attribute__ ((weak, alias("iscf_file_write_all")));
void mpi_file_write_all__() __attribute__ ((weak, alias("iscf_file_write_all")));
#endif

void iscf_file_write_all(int *fh, void *buf, int *count, int *datatype, int *status, int *ierr)
{
    *ierr = MPI_File_write_all (*fh, buf, *count, *datatype, (MPI_Status *)status);
}
