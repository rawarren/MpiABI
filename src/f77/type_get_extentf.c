
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_extent
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_GET_EXTENT() __attribute__ ((weak, alias("iscf_type_get_extent")));
void mpi_type_get_extent() __attribute__ ((weak, alias("iscf_type_get_extent")));
void mpi_type_get_extent_() __attribute__ ((weak, alias("iscf_type_get_extent")));
void mpi_type_get_extent__() __attribute__ ((weak, alias("iscf_type_get_extent")));
#endif

void iscf_type_get_extent(int *type, int *lb, int *extent, int *ierr)
{
    MPI_Aint true_extent = 0;
    MPI_Aint true_lb = 0;
    *ierr = MPI_Type_get_extent (*type, &true_lb, &true_extent);
    *extent = (int)true_extent & ISC_INT32MASK;
    *lb = (int)true_lb & ISC_INT32MASK;
}
