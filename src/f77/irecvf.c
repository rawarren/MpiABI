
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Irecv
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_IRECV() __attribute__ ((weak, alias("iscf_irecv")));
void mpi_irecv() __attribute__ ((weak, alias("iscf_irecv")));
void mpi_irecv_() __attribute__ ((weak, alias("iscf_irecv")));
void mpi_irecv__() __attribute__ ((weak, alias("iscf_irecv")));
#endif

void iscf_irecv(void *buf, int *count, int *datatype, int *source, int *tag, int *comm, int *request, int *ierr)
{
  *ierr = MPI_Irecv (FBOTTOM(buf), *count, *datatype, *source, *tag, *comm, request);
}
