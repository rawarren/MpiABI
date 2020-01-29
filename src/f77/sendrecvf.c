
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Sendrecv
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_SENDRECV() __attribute__ ((weak, alias("iscf_sendrecv")));
void mpi_sendrecv() __attribute__ ((weak, alias("iscf_sendrecv")));
void mpi_sendrecv_() __attribute__ ((weak, alias("iscf_sendrecv")));
void mpi_sendrecv__() __attribute__ ((weak, alias("iscf_sendrecv")));
#endif

void iscf_sendrecv(void *sendbuf, int *sendcount, int *sendtype, int *dest, int *sendtag, void *recvbuf, int *recvcount, int *recvtype, int *source, int *recvtag, int *comm, int *status, int *ierr)
{
  *ierr = MPI_Sendrecv (FBOTTOM(sendbuf), *sendcount, *sendtype, *dest, *sendtag, FBOTTOM(recvbuf), *recvcount, *recvtype, *source, *recvtag, *comm, (MPI_Status *)status);
}
