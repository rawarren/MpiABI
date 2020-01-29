
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_delete
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_DELETE() __attribute__ ((weak, alias("iscf_file_delete")));
void mpi_file_delete() __attribute__ ((weak, alias("iscf_file_delete")));
void mpi_file_delete_() __attribute__ ((weak, alias("iscf_file_delete")));
void mpi_file_delete__() __attribute__ ((weak, alias("iscf_file_delete")));
#endif

void iscf_file_delete(char *filename, int *info, int *ierr)
{
    *ierr = MPI_File_delete (filename, *info);
}
