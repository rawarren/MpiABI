
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_map
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_CART_MAP() __attribute__ ((weak, alias("iscf_cart_map")));
void mpi_cart_map() __attribute__ ((weak, alias("iscf_cart_map")));
void mpi_cart_map_() __attribute__ ((weak, alias("iscf_cart_map")));
void mpi_cart_map__() __attribute__ ((weak, alias("iscf_cart_map")));
#endif

void iscf_cart_map(int *comm, int *ndims, int dims[], int periods[], int *newrank, int *ierr)
{
    *ierr = MPI_Cart_map (*comm, *ndims, dims, periods, newrank);
}
