
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Dims_create
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_DIMS_CREATE() __attribute__ ((weak, alias("iscf_dims_create")));
void mpi_dims_create() __attribute__ ((weak, alias("iscf_dims_create")));
void mpi_dims_create_() __attribute__ ((weak, alias("iscf_dims_create")));
void mpi_dims_create__() __attribute__ ((weak, alias("iscf_dims_create")));
#endif

void iscf_dims_create(int *nnodes, int *ndims, int *dims, int *ierr)
{
    *ierr = MPI_Dims_create (*nnodes, *ndims, dims);
}
