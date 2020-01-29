
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_true_extent
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_GET_TRUE_EXTENT() __attribute__ ((weak, alias("iscf_type_get_true_extent")));
void mpi_type_get_true_extent() __attribute__ ((weak, alias("iscf_type_get_true_extent")));
void mpi_type_get_true_extent_() __attribute__ ((weak, alias("iscf_type_get_true_extent")));
void mpi_type_get_true_extent__() __attribute__ ((weak, alias("iscf_type_get_true_extent")));
#endif

void iscf_type_get_true_extent(int *datatype, int *true_lb, int *true_extent, int *ierr)
{
    MPI_Aint t_lb=0, t_extent=0;
    *ierr = MPI_Type_get_true_extent (*datatype, &t_lb, &t_extent);
    *true_lb = (MPI_Aint)t_lb; *true_extent = (MPI_Aint)t_extent;
}
