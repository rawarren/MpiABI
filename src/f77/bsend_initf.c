
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Bsend_init
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_BSEND_INIT() __attribute__ ((weak, alias("iscf_bsend_init")));
void mpi_bsend_init() __attribute__ ((weak, alias("iscf_bsend_init")));
void mpi_bsend_init_() __attribute__ ((weak, alias("iscf_bsend_init")));
void mpi_bsend_init__() __attribute__ ((weak, alias("iscf_bsend_init")));
#endif

void iscf_bsend_init(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *request, int *ierr)
{
  *ierr = MPI_Bsend_init (FBOTTOM(buf), *count, *datatype, *dest, *tag, *comm, request);
}
