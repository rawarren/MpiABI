
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Reduce_scatter
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_REDUCE_SCATTER() __attribute__ ((weak, alias("iscf_reduce_scatter")));
void mpi_reduce_scatter() __attribute__ ((weak, alias("iscf_reduce_scatter")));
void mpi_reduce_scatter_() __attribute__ ((weak, alias("iscf_reduce_scatter")));
void mpi_reduce_scatter__() __attribute__ ((weak, alias("iscf_reduce_scatter")));
#endif

void iscf_reduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[], int *datatype, int *op, int *comm, int *ierr)
{
  *ierr = MPI_Reduce_scatter (FINPLACE(sendbuf), FINPLACE(recvbuf), recvcounts, *datatype, *op, *comm);
}
