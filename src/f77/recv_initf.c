
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Recv_init
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_RECV_INIT() __attribute__ ((weak, alias("iscf_recv_init")));
void mpi_recv_init() __attribute__ ((weak, alias("iscf_recv_init")));
void mpi_recv_init_() __attribute__ ((weak, alias("iscf_recv_init")));
void mpi_recv_init__() __attribute__ ((weak, alias("iscf_recv_init")));
#endif

void iscf_recv_init(void *buf, int *count, int *datatype, int *source, int *tag, int *comm, int *request, int *ierr)
{
  *ierr = MPI_Recv_init (FBOTTOM(buf), *count, *datatype, *source, *tag, *comm, request);
}
