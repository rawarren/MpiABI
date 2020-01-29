
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Alltoallw
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ALLTOALLW() __attribute__ ((weak, alias("iscf_alltoallw")));
void mpi_alltoallw() __attribute__ ((weak, alias("iscf_alltoallw")));
void mpi_alltoallw_() __attribute__ ((weak, alias("iscf_alltoallw")));
void mpi_alltoallw__() __attribute__ ((weak, alias("iscf_alltoallw")));
#endif

void iscf_alltoallw(void *sendbuf, int sendcounts[], int sdispls[], int sendtypes[], void *recvbuf, int recvcounts[], int rdispls[], int recvtypes[], int *comm, int *ierr)
{
  *ierr = MPI_Alltoallw (FINPLACE(sendbuf), sendcounts, sdispls, sendtypes, FINPLACE(recvbuf), recvcounts, rdispls, recvtypes, *comm);
}
