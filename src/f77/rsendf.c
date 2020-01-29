
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Rsend
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_RSEND() __attribute__ ((weak, alias("iscf_rsend")));
void mpi_rsend() __attribute__ ((weak, alias("iscf_rsend")));
void mpi_rsend_() __attribute__ ((weak, alias("iscf_rsend")));
void mpi_rsend__() __attribute__ ((weak, alias("iscf_rsend")));
#endif

void iscf_rsend(void *ibuf, int *count, int *datatype, int *dest, int *tag, int *comm, int *ierr)
{
  *ierr = MPI_Rsend (FBOTTOM(ibuf), *count, *datatype, *dest, *tag, *comm);
}
