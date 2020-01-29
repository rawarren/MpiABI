
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_extent
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_EXTENT() __attribute__ ((weak, alias("iscf_type_extent")));
void mpi_type_extent() __attribute__ ((weak, alias("iscf_type_extent")));
void mpi_type_extent_() __attribute__ ((weak, alias("iscf_type_extent")));
void mpi_type_extent__() __attribute__ ((weak, alias("iscf_type_extent")));
#endif

void iscf_type_extent(int *type, int *extent, int *ierr)
{
    MPI_Aint true_extent;
    *ierr = MPI_Type_extent (*type, &true_extent);
    *extent = (int)true_extent & 0x0ffffffff;
}
