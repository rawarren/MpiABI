
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_size
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_SIZE() __attribute__ ((weak, alias("iscf_file_get_size")));
void mpi_file_get_size() __attribute__ ((weak, alias("iscf_file_get_size")));
void mpi_file_get_size_() __attribute__ ((weak, alias("iscf_file_get_size")));
void mpi_file_get_size__() __attribute__ ((weak, alias("iscf_file_get_size")));
#endif

void iscf_file_get_size(int *fh, int *size, int *ierr)
{
    MPI_Offset real_size;
    *ierr = MPI_File_get_size (*fh, &real_size);
    *size = real_size & ISC_INT32MASK;
}
