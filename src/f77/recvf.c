
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Recv
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_RECV() __attribute__ ((weak, alias("iscf_recv")));
void mpi_recv() __attribute__ ((weak, alias("iscf_recv")));
void mpi_recv_() __attribute__ ((weak, alias("iscf_recv")));
void mpi_recv__() __attribute__ ((weak, alias("iscf_recv")));
#endif

void iscf_recv(void *buf, int *count, int *datatype, int *source, int *tag, int *comm, int *status, int *ierr)
{
  *ierr = MPI_Recv (FBOTTOM(buf), *count, *datatype, *source, *tag, *comm, (MPI_Status *)status);
}
