
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_set_atomicity
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_SET_ATOMICITY() __attribute__ ((weak, alias("iscf_file_set_atomicity")));
void mpi_file_set_atomicity() __attribute__ ((weak, alias("iscf_file_set_atomicity")));
void mpi_file_set_atomicity_() __attribute__ ((weak, alias("iscf_file_set_atomicity")));
void mpi_file_set_atomicity__() __attribute__ ((weak, alias("iscf_file_set_atomicity")));
#endif

void iscf_file_set_atomicity(int *fh, int *flag, int *ierr)
{
    *ierr = MPI_File_set_atomicity (*fh, *flag);
}
