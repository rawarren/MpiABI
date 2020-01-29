
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_ERRHANDLER() __attribute__ ((weak, alias("iscf_file_get_errhandler")));
void mpi_file_get_errhandler() __attribute__ ((weak, alias("iscf_file_get_errhandler")));
void mpi_file_get_errhandler_() __attribute__ ((weak, alias("iscf_file_get_errhandler")));
void mpi_file_get_errhandler__() __attribute__ ((weak, alias("iscf_file_get_errhandler")));
#endif

void iscf_file_get_errhandler(int *file, int *errhandler, int *ierr)
{
    *ierr = MPI_File_get_errhandler (*file, errhandler);
}
