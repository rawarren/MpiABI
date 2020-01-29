
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_coords
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_CART_COORDS() __attribute__ ((weak, alias("iscf_cart_coords")));
void mpi_cart_coords() __attribute__ ((weak, alias("iscf_cart_coords")));
void mpi_cart_coords_() __attribute__ ((weak, alias("iscf_cart_coords")));
void mpi_cart_coords__() __attribute__ ((weak, alias("iscf_cart_coords")));
#endif

void iscf_cart_coords(int *comm, int *rank, int *maxdims, int *coords, int *ierr)
{
    *ierr = MPI_Cart_coords (*comm, *rank, *maxdims, coords);
}
