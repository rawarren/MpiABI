
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graphdims_get
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GRAPHDIMS_GET() __attribute__ ((weak, alias("iscf_graphdims_get")));
void mpi_graphdims_get() __attribute__ ((weak, alias("iscf_graphdims_get")));
void mpi_graphdims_get_() __attribute__ ((weak, alias("iscf_graphdims_get")));
void mpi_graphdims_get__() __attribute__ ((weak, alias("iscf_graphdims_get")));
#endif

void iscf_graphdims_get(int *comm, int *nnodes, int *nedges, int *ierr)
{
    *ierr = MPI_Graphdims_get (*comm, nnodes, nedges);
}
