
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Ssend_init
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_SSEND_INIT() __attribute__ ((weak, alias("iscf_ssend_init")));
void mpi_ssend_init() __attribute__ ((weak, alias("iscf_ssend_init")));
void mpi_ssend_init_() __attribute__ ((weak, alias("iscf_ssend_init")));
void mpi_ssend_init__() __attribute__ ((weak, alias("iscf_ssend_init")));
#endif

void iscf_ssend_init(void *buf, int *count, int *datatype, int *dest, int *tag, int *comm, int *request, int *ierr)
{
    *ierr = MPI_Ssend_init (buf, *count, *datatype, *dest, *tag, *comm, request);
}
