
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Scatterv
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_SCATTERV() __attribute__ ((weak, alias("iscf_scatterv")));
void mpi_scatterv() __attribute__ ((weak, alias("iscf_scatterv")));
void mpi_scatterv_() __attribute__ ((weak, alias("iscf_scatterv")));
void mpi_scatterv__() __attribute__ ((weak, alias("iscf_scatterv")));
#endif

void iscf_scatterv(void *sendbuf, int sendcounts[], int displs[], int *sendtype, void *recvbuf, int *recvcount, int *recvtype, int *root, int *comm, int *ierr)
{
  *ierr = MPI_Scatterv (FINPLACE(sendbuf), sendcounts, displs, *sendtype, FINPLACE(recvbuf), *recvcount, *recvtype, *root, *comm);
}
