
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_call_errhandler
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_CALL_ERRHANDLER() __attribute__ ((weak, alias("iscf_file_call_errhandler")));
void mpi_file_call_errhandler() __attribute__ ((weak, alias("iscf_file_call_errhandler")));
void mpi_file_call_errhandler_() __attribute__ ((weak, alias("iscf_file_call_errhandler")));
void mpi_file_call_errhandler__() __attribute__ ((weak, alias("iscf_file_call_errhandler")));
#endif

void iscf_file_call_errhandler(int *fh, int *errorcode, int *ierr)
{
    *ierr = MPI_File_call_errhandler (*fh, *errorcode);
}
