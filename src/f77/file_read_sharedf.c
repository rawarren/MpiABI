
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_read_shared
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_READ_SHARED() __attribute__ ((weak, alias("iscf_file_read_shared")));
void mpi_file_read_shared() __attribute__ ((weak, alias("iscf_file_read_shared")));
void mpi_file_read_shared_() __attribute__ ((weak, alias("iscf_file_read_shared")));
void mpi_file_read_shared__() __attribute__ ((weak, alias("iscf_file_read_shared")));
#endif

void iscf_file_read_shared(int *fh, void *buf, int *count, int *datatype, int *status, int *ierr)
{
    *ierr = MPI_File_read_shared (*fh, buf, *count, *datatype, (MPI_Status *)status);
}
