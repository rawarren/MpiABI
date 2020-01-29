
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_shift
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_CART_SHIFT() __attribute__ ((weak, alias("iscf_cart_shift")));
void mpi_cart_shift() __attribute__ ((weak, alias("iscf_cart_shift")));
void mpi_cart_shift_() __attribute__ ((weak, alias("iscf_cart_shift")));
void mpi_cart_shift__() __attribute__ ((weak, alias("iscf_cart_shift")));
#endif

void iscf_cart_shift(int *comm, int *direction, int *disp, int *rank_source, int *rank_dest, int *ierr)
{
    *ierr = MPI_Cart_shift (*comm, *direction, *disp, rank_source, rank_dest);
}
