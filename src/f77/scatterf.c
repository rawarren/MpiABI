
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Scatter
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_SCATTER() __attribute__ ((weak, alias("iscf_scatter")));
void mpi_scatter() __attribute__ ((weak, alias("iscf_scatter")));
void mpi_scatter_() __attribute__ ((weak, alias("iscf_scatter")));
void mpi_scatter__() __attribute__ ((weak, alias("iscf_scatter")));
#endif

void iscf_scatter(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf, int *recvcount, int *recvtype, int *root, int *comm, int *ierr)
{
  *ierr = MPI_Scatter (FINPLACE(sendbuf), *sendcount, *sendtype, FINPLACE(recvbuf), *recvcount, *recvtype, *root, *comm);
}
