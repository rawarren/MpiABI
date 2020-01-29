
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Ssend
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_SSEND() __attribute__ ((weak, alias("iscf_ssend")));
void mpi_ssend() __attribute__ ((weak, alias("iscf_ssend")));
void mpi_ssend_() __attribute__ ((weak, alias("iscf_ssend")));
void mpi_ssend__() __attribute__ ((weak, alias("iscf_ssend")));
#endif

void iscf_ssend(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *ierr)
{
  *ierr = MPI_Ssend (FBOTTOM(buf), *count, *datatype, *dest, *tag, *comm);
}
