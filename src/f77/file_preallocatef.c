
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_preallocate
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_PREALLOCATE() __attribute__ ((weak, alias("iscf_file_preallocate")));
void mpi_file_preallocate() __attribute__ ((weak, alias("iscf_file_preallocate")));
void mpi_file_preallocate_() __attribute__ ((weak, alias("iscf_file_preallocate")));
void mpi_file_preallocate__() __attribute__ ((weak, alias("iscf_file_preallocate")));
#endif

void iscf_file_preallocate(int *fh, int *size, int *ierr)
{
    *ierr = MPI_File_preallocate (*fh, *size);
}
