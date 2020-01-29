
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_group
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_GROUP() __attribute__ ((weak, alias("iscf_file_get_group")));
void mpi_file_get_group() __attribute__ ((weak, alias("iscf_file_get_group")));
void mpi_file_get_group_() __attribute__ ((weak, alias("iscf_file_get_group")));
void mpi_file_get_group__() __attribute__ ((weak, alias("iscf_file_get_group")));
#endif

void iscf_file_get_group(int *fh, int *group, int *ierr)
{
    *ierr = MPI_File_get_group (*fh, group);
}
