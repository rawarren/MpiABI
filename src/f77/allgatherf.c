
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Allgather
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ALLGATHER() __attribute__ ((weak, alias("iscf_allgather")));
void mpi_allgather() __attribute__ ((weak, alias("iscf_allgather")));
void mpi_allgather_() __attribute__ ((weak, alias("iscf_allgather")));
void mpi_allgather__() __attribute__ ((weak, alias("iscf_allgather")));
#endif

void iscf_allgather(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf, int *recvcount, int *recvtype, int *comm, int *ierr)
{
  *ierr = MPI_Allgather (FINPLACE(sendbuf), *sendcount, *sendtype, FINPLACE(recvbuf), *recvcount, *recvtype, *comm);
}
