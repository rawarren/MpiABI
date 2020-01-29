
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_sync
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_SYNC() __attribute__ ((weak, alias("iscf_file_sync")));
void mpi_file_sync() __attribute__ ((weak, alias("iscf_file_sync")));
void mpi_file_sync_() __attribute__ ((weak, alias("iscf_file_sync")));
void mpi_file_sync__() __attribute__ ((weak, alias("iscf_file_sync")));
#endif

void iscf_file_sync(int *fh, int *ierr)
{
    *ierr = MPI_File_sync (*fh);
}
