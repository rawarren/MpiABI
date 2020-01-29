
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Rsend_init
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_RSEND_INIT() __attribute__ ((weak, alias("iscf_rsend_init")));
void mpi_rsend_init() __attribute__ ((weak, alias("iscf_rsend_init")));
void mpi_rsend_init_() __attribute__ ((weak, alias("iscf_rsend_init")));
void mpi_rsend_init__() __attribute__ ((weak, alias("iscf_rsend_init")));
#endif

void iscf_rsend_init(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *request, int *ierr)
{
  *ierr = MPI_Rsend_init (FBOTTOM(buf), *count, *datatype, *dest, *tag, *comm, request);
}
