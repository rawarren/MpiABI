
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_atomicity
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_ATOMICITY() __attribute__ ((weak, alias("iscf_file_get_atomicity")));
void mpi_file_get_atomicity() __attribute__ ((weak, alias("iscf_file_get_atomicity")));
void mpi_file_get_atomicity_() __attribute__ ((weak, alias("iscf_file_get_atomicity")));
void mpi_file_get_atomicity__() __attribute__ ((weak, alias("iscf_file_get_atomicity")));
#endif

void iscf_file_get_atomicity(int *fh, int *flag, int *ierr)
{
    *ierr = MPI_File_get_atomicity (*fh, flag);
}
