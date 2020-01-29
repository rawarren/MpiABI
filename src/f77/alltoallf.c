
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Alltoall
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ALLTOALL() __attribute__ ((weak, alias("iscf_alltoall")));
void mpi_alltoall() __attribute__ ((weak, alias("iscf_alltoall")));
void mpi_alltoall_() __attribute__ ((weak, alias("iscf_alltoall")));
void mpi_alltoall__() __attribute__ ((weak, alias("iscf_alltoall")));
#endif

void iscf_alltoall(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf, int *recvcount, int *recvtype, int *comm, int *ierr)
{
  *ierr = MPI_Alltoall (FINPLACE(sendbuf), *sendcount, *sendtype, FINPLACE(recvbuf), *recvcount, *recvtype, *comm);
}
