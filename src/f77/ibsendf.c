
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Ibsend
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_IBSEND() __attribute__ ((weak, alias("iscf_ibsend")));
void mpi_ibsend() __attribute__ ((weak, alias("iscf_ibsend")));
void mpi_ibsend_() __attribute__ ((weak, alias("iscf_ibsend")));
void mpi_ibsend__() __attribute__ ((weak, alias("iscf_ibsend")));
#endif

void iscf_ibsend(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *request, int *ierr)
{
  *ierr = MPI_Ibsend (FBOTTOM(buf), *count, *datatype, *dest, *tag, *comm, request);
}
