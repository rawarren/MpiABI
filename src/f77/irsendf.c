
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Irsend
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_IRSEND() __attribute__ ((weak, alias("iscf_irsend")));
void mpi_irsend() __attribute__ ((weak, alias("iscf_irsend")));
void mpi_irsend_() __attribute__ ((weak, alias("iscf_irsend")));
void mpi_irsend__() __attribute__ ((weak, alias("iscf_irsend")));
#endif

void iscf_irsend(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *request, int *ierr)
{
  *ierr = MPI_Irsend (FBOTTOM(buf), *count, *datatype, *dest, *tag, *comm, request);
}
