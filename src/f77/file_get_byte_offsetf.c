
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_byte_offset
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_BYTE_OFFSET() __attribute__ ((weak, alias("iscf_file_get_byte_offset")));
void mpi_file_get_byte_offset() __attribute__ ((weak, alias("iscf_file_get_byte_offset")));
void mpi_file_get_byte_offset_() __attribute__ ((weak, alias("iscf_file_get_byte_offset")));
void mpi_file_get_byte_offset__() __attribute__ ((weak, alias("iscf_file_get_byte_offset")));
#endif

void iscf_file_get_byte_offset(int *fh, int *offset, int *disp, int *ierr)
{
    MPI_Offset int_offset = *offset;
    MPI_Offset real_disp;
    *ierr = MPI_File_get_byte_offset (*fh, *offset, &real_disp);
    *disp = real_disp & ISC_INT32MASK;
}
