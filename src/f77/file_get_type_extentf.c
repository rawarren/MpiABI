
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_type_extent
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_TYPE_EXTENT() __attribute__ ((weak, alias("iscf_file_get_type_extent")));
void mpi_file_get_type_extent() __attribute__ ((weak, alias("iscf_file_get_type_extent")));
void mpi_file_get_type_extent_() __attribute__ ((weak, alias("iscf_file_get_type_extent")));
void mpi_file_get_type_extent__() __attribute__ ((weak, alias("iscf_file_get_type_extent")));
#endif

void iscf_file_get_type_extent(int *fh, int *datatype, int *extent, int *ierr)
{
    MPI_Aint c_extent;
    *ierr = MPI_File_get_type_extent (*fh, *datatype, &c_extent);
    *extent = (int)(c_extent & ISC_INT32MASK);
}
