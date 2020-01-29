
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_position
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_POSITION() __attribute__ ((weak, alias("iscf_file_get_position")));
void mpi_file_get_position() __attribute__ ((weak, alias("iscf_file_get_position")));
void mpi_file_get_position_() __attribute__ ((weak, alias("iscf_file_get_position")));
void mpi_file_get_position__() __attribute__ ((weak, alias("iscf_file_get_position")));
#endif

void iscf_file_get_position(int *fh, MPI_Aint *offset, int *ierr)
{
    MPI_Offset pos;
    *ierr = MPI_File_get_position (*fh, &pos);
    *offset = pos & 0xFFFFFFFF;
}
