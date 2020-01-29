
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cancel
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_CANCEL() __attribute__ ((weak, alias("iscf_cancel")));
void mpi_cancel() __attribute__ ((weak, alias("iscf_cancel")));
void mpi_cancel_() __attribute__ ((weak, alias("iscf_cancel")));
void mpi_cancel__() __attribute__ ((weak, alias("iscf_cancel")));
#endif

void iscf_cancel(int *request, int *ierr)
{
    *ierr = MPI_Cancel (request);
}
