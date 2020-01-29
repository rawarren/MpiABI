
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_position_shared
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_POSITION_SHARED() __attribute__ ((weak, alias("iscf_file_get_position_shared")));
void mpi_file_get_position_shared() __attribute__ ((weak, alias("iscf_file_get_position_shared")));
void mpi_file_get_position_shared_() __attribute__ ((weak, alias("iscf_file_get_position_shared")));
void mpi_file_get_position_shared__() __attribute__ ((weak, alias("iscf_file_get_position_shared")));
#endif

void iscf_file_get_position_shared(int *fh, int *offset, int *ierr)
{
    MPI_Offset c_offset;
    *ierr = MPI_File_get_position_shared (*fh, &c_offset);
    *offset = c_offset & 0x0FFFFFFFF; /* Return 32 bits (sorry!) */
}
