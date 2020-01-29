
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cartdim_get
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_CARTDIM_GET() __attribute__ ((weak, alias("iscf_cartdim_get")));
void mpi_cartdim_get() __attribute__ ((weak, alias("iscf_cartdim_get")));
void mpi_cartdim_get_() __attribute__ ((weak, alias("iscf_cartdim_get")));
void mpi_cartdim_get__() __attribute__ ((weak, alias("iscf_cartdim_get")));
#endif

void iscf_cartdim_get(int *comm, int *ndims, int *ierr)
{
    *ierr = MPI_Cartdim_get (*comm, ndims);
}
