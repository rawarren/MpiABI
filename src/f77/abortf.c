
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Abort
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ABORT() __attribute__ ((weak, alias("iscf_abort")));
void mpi_abort() __attribute__ ((weak, alias("iscf_abort")));
void mpi_abort_() __attribute__ ((weak, alias("iscf_abort")));
void mpi_abort__() __attribute__ ((weak, alias("iscf_abort")));
#endif

void iscf_abort(int *comm, int *errorcode, int *ierr)
{
    *ierr = MPI_Abort (*comm, *errorcode);
}
