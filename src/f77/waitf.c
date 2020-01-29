
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Wait
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WAIT() __attribute__ ((weak, alias("iscf_wait")));
void mpi_wait() __attribute__ ((weak, alias("iscf_wait")));
void mpi_wait_() __attribute__ ((weak, alias("iscf_wait")));
void mpi_wait__() __attribute__ ((weak, alias("iscf_wait")));
#endif

void iscf_wait(int *request, int *status, int *ierr)
{
    *ierr = MPI_Wait (request, (MPI_Status *)status);
}
