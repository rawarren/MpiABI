
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Bsend
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_BSEND() __attribute__ ((weak, alias("iscf_bsend")));
void mpi_bsend() __attribute__ ((weak, alias("iscf_bsend")));
void mpi_bsend_() __attribute__ ((weak, alias("iscf_bsend")));
void mpi_bsend__() __attribute__ ((weak, alias("iscf_bsend")));
#endif

void iscf_bsend(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *ierr)
{
  *ierr = MPI_Bsend (FBOTTOM(buf), *count, *datatype, *dest, *tag, *comm);
}
