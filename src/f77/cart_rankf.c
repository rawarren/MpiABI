
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_rank
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_CART_RANK() __attribute__ ((weak, alias("iscf_cart_rank")));
void mpi_cart_rank() __attribute__ ((weak, alias("iscf_cart_rank")));
void mpi_cart_rank_() __attribute__ ((weak, alias("iscf_cart_rank")));
void mpi_cart_rank__() __attribute__ ((weak, alias("iscf_cart_rank")));
#endif

void iscf_cart_rank(int *comm, int coords[], int *rank, int *ierr)
{
    *ierr = MPI_Cart_rank (*comm, coords, rank);
}
