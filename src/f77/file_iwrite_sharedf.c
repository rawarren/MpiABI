
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_iwrite_shared
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_IWRITE_SHARED() __attribute__ ((weak, alias("iscf_file_iwrite_shared")));
void mpi_file_iwrite_shared() __attribute__ ((weak, alias("iscf_file_iwrite_shared")));
void mpi_file_iwrite_shared_() __attribute__ ((weak, alias("iscf_file_iwrite_shared")));
void mpi_file_iwrite_shared__() __attribute__ ((weak, alias("iscf_file_iwrite_shared")));
#endif

void iscf_file_iwrite_shared(int *fh, void *buf, int *count, int *datatype, int *request, int *ierr)
{
    *ierr = MPI_File_iwrite_shared (*fh, buf, *count, *datatype, request);
}
