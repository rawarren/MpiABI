
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Gather
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GATHER() __attribute__ ((weak, alias("iscf_gather")));
void mpi_gather() __attribute__ ((weak, alias("iscf_gather")));
void mpi_gather_() __attribute__ ((weak, alias("iscf_gather")));
void mpi_gather__() __attribute__ ((weak, alias("iscf_gather")));
#endif

void iscf_gather(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf, int *recvcount, int *recvtype, int *root, int *comm, int *ierr)
{
  *ierr = MPI_Gather (FINPLACE(sendbuf), *sendcount, *sendtype, FINPLACE(recvbuf), *recvcount, *recvtype, *root, *comm);
}
