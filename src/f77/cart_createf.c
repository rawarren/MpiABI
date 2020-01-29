
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_create
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_CART_CREATE() __attribute__ ((weak, alias("iscf_cart_create")));
void mpi_cart_create() __attribute__ ((weak, alias("iscf_cart_create")));
void mpi_cart_create_() __attribute__ ((weak, alias("iscf_cart_create")));
void mpi_cart_create__() __attribute__ ((weak, alias("iscf_cart_create")));
#endif

void iscf_cart_create(int *old_comm, int *ndims, int dims[], int periods[], int *reorder, int *comm_cart, int *ierr)
{
    *ierr = MPI_Cart_create (*old_comm, *ndims, dims, periods, *reorder, comm_cart);
}
