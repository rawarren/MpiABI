
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Send
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_SEND() __attribute__ ((weak, alias("iscf_send")));
void mpi_send() __attribute__ ((weak, alias("iscf_send")));
void mpi_send_() __attribute__ ((weak, alias("iscf_send")));
void mpi_send__() __attribute__ ((weak, alias("iscf_send")));
#endif

void iscf_send(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *ierr)
{
  *ierr = MPI_Send (FBOTTOM(buf), *count, *datatype, *dest, *tag, *comm);
}
