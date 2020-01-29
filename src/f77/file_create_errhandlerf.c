
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_create_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_CREATE_ERRHANDLER() __attribute__ ((weak, alias("iscf_file_create_errhandler")));
void mpi_file_create_errhandler() __attribute__ ((weak, alias("iscf_file_create_errhandler")));
void mpi_file_create_errhandler_() __attribute__ ((weak, alias("iscf_file_create_errhandler")));
void mpi_file_create_errhandler__() __attribute__ ((weak, alias("iscf_file_create_errhandler")));
#endif

void iscf_file_create_errhandler(int *function, int *errhandler, int *ierr)
{
  *ierr = MPI_File_create_errhandler ((MPI_File_errhandler_function *)function, (MPI_Errhandler *)errhandler);
}
