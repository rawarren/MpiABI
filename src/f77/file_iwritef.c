
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_iwrite
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_IWRITE() __attribute__ ((weak, alias("iscf_file_iwrite")));
void mpi_file_iwrite() __attribute__ ((weak, alias("iscf_file_iwrite")));
void mpi_file_iwrite_() __attribute__ ((weak, alias("iscf_file_iwrite")));
void mpi_file_iwrite__() __attribute__ ((weak, alias("iscf_file_iwrite")));
#endif

void iscf_file_iwrite(int *fh, void *buf, int *count, int *datatype, int *request, int *ierr)
{
    *ierr = MPI_File_iwrite (*fh, buf, *count, *datatype, request);
}
