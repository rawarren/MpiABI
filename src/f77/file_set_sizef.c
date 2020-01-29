
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_set_size
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_SET_SIZE() __attribute__ ((weak, alias("iscf_file_set_size")));
void mpi_file_set_size() __attribute__ ((weak, alias("iscf_file_set_size")));
void mpi_file_set_size_() __attribute__ ((weak, alias("iscf_file_set_size")));
void mpi_file_set_size__() __attribute__ ((weak, alias("iscf_file_set_size")));
#endif

void iscf_file_set_size(int *fh, int *size, int *ierr)
{
    *ierr = MPI_File_set_size (*fh, *size);
}
