
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_iread
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_IREAD() __attribute__ ((weak, alias("iscf_file_iread")));
void mpi_file_iread() __attribute__ ((weak, alias("iscf_file_iread")));
void mpi_file_iread_() __attribute__ ((weak, alias("iscf_file_iread")));
void mpi_file_iread__() __attribute__ ((weak, alias("iscf_file_iread")));
#endif

void iscf_file_iread(int *fh, void *buf, int *count, int *datatype, int *request, int *ierr)
{
    *ierr = MPI_File_iread (*fh, buf, *count, *datatype, request);
}
