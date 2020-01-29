
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Send_init
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_SEND_INIT() __attribute__ ((weak, alias("iscf_send_init")));
void mpi_send_init() __attribute__ ((weak, alias("iscf_send_init")));
void mpi_send_init_() __attribute__ ((weak, alias("iscf_send_init")));
void mpi_send_init__() __attribute__ ((weak, alias("iscf_send_init")));
#endif

void iscf_send_init(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *request, int *ierr)
{
  *ierr = MPI_Send_init (FBOTTOM(buf), *count, *datatype, *dest, *tag, *comm, request);
}
