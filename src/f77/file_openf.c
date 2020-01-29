
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_open
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_OPEN() __attribute__ ((weak, alias("iscf_file_open")));
void mpi_file_open() __attribute__ ((weak, alias("iscf_file_open")));
void mpi_file_open_() __attribute__ ((weak, alias("iscf_file_open")));
void mpi_file_open__() __attribute__ ((weak, alias("iscf_file_open")));
#endif

void iscf_file_open(int *comm, char *filename, int *amode, int *info, int *fh, int *ierr)
{
    *ierr = MPI_File_open (*comm, filename, *amode, *info, fh);
}
