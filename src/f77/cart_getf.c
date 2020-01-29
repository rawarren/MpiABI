
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_get
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_CART_GET() __attribute__ ((weak, alias("iscf_cart_get")));
void mpi_cart_get() __attribute__ ((weak, alias("iscf_cart_get")));
void mpi_cart_get_() __attribute__ ((weak, alias("iscf_cart_get")));
void mpi_cart_get__() __attribute__ ((weak, alias("iscf_cart_get")));
#endif

void iscf_cart_get(int *comm, int *maxdims, int dims[], int periods[], int *coords, int *ierr)
{
    *ierr = MPI_Cart_get (*comm, *maxdims, dims, periods, coords);
}
