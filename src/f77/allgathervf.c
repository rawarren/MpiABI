
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Allgatherv
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ALLGATHERV() __attribute__ ((weak, alias("iscf_allgatherv")));
void mpi_allgatherv() __attribute__ ((weak, alias("iscf_allgatherv")));
void mpi_allgatherv_() __attribute__ ((weak, alias("iscf_allgatherv")));
void mpi_allgatherv__() __attribute__ ((weak, alias("iscf_allgatherv")));
#endif

void iscf_allgatherv(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf, int recvcounts[], int displs[], int *recvtype, int *comm, int *ierr)
{
  *ierr = MPI_Allgatherv (FINPLACE(sendbuf), *sendcount, *sendtype, FINPLACE(recvbuf), recvcounts, displs, *recvtype, *comm);
}
