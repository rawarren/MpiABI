
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Alltoallv
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ALLTOALLV() __attribute__ ((weak, alias("iscf_alltoallv")));
void mpi_alltoallv() __attribute__ ((weak, alias("iscf_alltoallv")));
void mpi_alltoallv_() __attribute__ ((weak, alias("iscf_alltoallv")));
void mpi_alltoallv__() __attribute__ ((weak, alias("iscf_alltoallv")));
#endif

void iscf_alltoallv(void *sendbuf, int sendcounts[], int sdispls[], int *sendtype, void *recvbuf, int recvcounts[], int rdispls[], int *recvtype, int *comm, int *ierr)
{
  *ierr = MPI_Alltoallv (FINPLACE(sendbuf), sendcounts, sdispls, *sendtype, FINPLACE(recvbuf), recvcounts, rdispls, *recvtype, *comm);
}
