
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Gatherv
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GATHERV() __attribute__ ((weak, alias("iscf_gatherv")));
void mpi_gatherv() __attribute__ ((weak, alias("iscf_gatherv")));
void mpi_gatherv_() __attribute__ ((weak, alias("iscf_gatherv")));
void mpi_gatherv__() __attribute__ ((weak, alias("iscf_gatherv")));
#endif

void iscf_gatherv(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf, int recvcounts[], int displs[], int *recvtype, int *root, int *comm, int *ierr)
{
  *ierr = MPI_Gatherv (FINPLACE(sendbuf), *sendcount, *sendtype, FINPLACE(recvbuf), recvcounts, displs, *recvtype, *root, *comm);
}
