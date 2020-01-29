
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Isend
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ISEND() __attribute__ ((weak, alias("iscf_isend")));
void mpi_isend() __attribute__ ((weak, alias("iscf_isend")));
void mpi_isend_() __attribute__ ((weak, alias("iscf_isend")));
void mpi_isend__() __attribute__ ((weak, alias("iscf_isend")));
#endif

void iscf_isend(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *request, int *ierr)
{
  *ierr = MPI_Isend (FBOTTOM(buf), *count, *datatype, *dest, *tag, *comm, request);
}
