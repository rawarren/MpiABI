
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_write_shared
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_WRITE_SHARED() __attribute__ ((weak, alias("iscf_file_write_shared")));
void mpi_file_write_shared() __attribute__ ((weak, alias("iscf_file_write_shared")));
void mpi_file_write_shared_() __attribute__ ((weak, alias("iscf_file_write_shared")));
void mpi_file_write_shared__() __attribute__ ((weak, alias("iscf_file_write_shared")));
#endif

void iscf_file_write_shared(int *fh, void *buf, int *count, int *datatype, int *status, int *ierr)
{
    *ierr = MPI_File_write_shared (*fh, buf, *count, *datatype, (MPI_Status *)status);
}
