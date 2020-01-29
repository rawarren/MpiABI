
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_set_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_SET_ERRHANDLER() __attribute__ ((weak, alias("iscf_file_set_errhandler")));
void mpi_file_set_errhandler() __attribute__ ((weak, alias("iscf_file_set_errhandler")));
void mpi_file_set_errhandler_() __attribute__ ((weak, alias("iscf_file_set_errhandler")));
void mpi_file_set_errhandler__() __attribute__ ((weak, alias("iscf_file_set_errhandler")));
#endif

void iscf_file_set_errhandler(int *file, int *errhandler, int *ierr)
{
    *ierr = MPI_File_set_errhandler (*file, *errhandler);
}
