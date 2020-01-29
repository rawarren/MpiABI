
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Issend
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ISSEND() __attribute__ ((weak, alias("iscf_issend")));
void mpi_issend() __attribute__ ((weak, alias("iscf_issend")));
void mpi_issend_() __attribute__ ((weak, alias("iscf_issend")));
void mpi_issend__() __attribute__ ((weak, alias("iscf_issend")));
#endif

void iscf_issend(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *request, int *ierr)
{
  *ierr = MPI_Issend (FBOTTOM(buf), *count, *datatype, *dest, *tag, *comm, request);
}
