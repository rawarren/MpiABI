
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Sendrecv_replace
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_SENDRECV_REPLACE() __attribute__ ((weak, alias("iscf_sendrecv_replace")));
void mpi_sendrecv_replace() __attribute__ ((weak, alias("iscf_sendrecv_replace")));
void mpi_sendrecv_replace_() __attribute__ ((weak, alias("iscf_sendrecv_replace")));
void mpi_sendrecv_replace__() __attribute__ ((weak, alias("iscf_sendrecv_replace")));
#endif

void iscf_sendrecv_replace(void *buf, int *count, int *datatype, int *dest, int *sendtag, int *source, int *recvtag, int *comm, int *status, int *ierr)
{
  *ierr = MPI_Sendrecv_replace (FBOTTOM(buf), *count, *datatype, *dest, *sendtag, *source, *recvtag, *comm, (MPI_Status *)status);
}
