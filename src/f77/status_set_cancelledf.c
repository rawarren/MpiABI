
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Status_set_cancelled
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_STATUS_SET_CANCELLED() __attribute__ ((weak, alias("iscf_status_set_cancelled")));
void mpi_status_set_cancelled() __attribute__ ((weak, alias("iscf_status_set_cancelled")));
void mpi_status_set_cancelled_() __attribute__ ((weak, alias("iscf_status_set_cancelled")));
void mpi_status_set_cancelled__() __attribute__ ((weak, alias("iscf_status_set_cancelled")));
#endif

void iscf_status_set_cancelled(int *status, int *flag, int *ierr)
{
    *ierr = MPI_Status_set_cancelled ((MPI_Status *)status, *flag);
}
