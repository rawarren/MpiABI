
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Waitall
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WAITALL() __attribute__ ((weak, alias("iscf_waitall")));
void mpi_waitall() __attribute__ ((weak, alias("iscf_waitall")));
void mpi_waitall_() __attribute__ ((weak, alias("iscf_waitall")));
void mpi_waitall__() __attribute__ ((weak, alias("iscf_waitall")));
#endif

void iscf_waitall(int *count, int *array_of_requests, int *array_of_statuses, int *ierr)
{
    *ierr = MPI_Waitall (*count, array_of_requests, (MPI_Status *)array_of_statuses);
}
