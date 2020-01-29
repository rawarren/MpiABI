
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_sub
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_CART_SUB() __attribute__ ((weak, alias("iscf_cart_sub")));
void mpi_cart_sub() __attribute__ ((weak, alias("iscf_cart_sub")));
void mpi_cart_sub_() __attribute__ ((weak, alias("iscf_cart_sub")));
void mpi_cart_sub__() __attribute__ ((weak, alias("iscf_cart_sub")));
#endif

void iscf_cart_sub(int *comm, int remain_dims[], int *new_comm, int *ierr)
{
    *ierr = MPI_Cart_sub (*comm, remain_dims, new_comm);
}
