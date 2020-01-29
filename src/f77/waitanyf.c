
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Waitany
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WAITANY() __attribute__ ((weak, alias("iscf_waitany")));
void mpi_waitany() __attribute__ ((weak, alias("iscf_waitany")));
void mpi_waitany_() __attribute__ ((weak, alias("iscf_waitany")));
void mpi_waitany__() __attribute__ ((weak, alias("iscf_waitany")));
#endif

void iscf_waitany(int *count, int *array_of_requests, int *index, int *status, int *ierr)
{
    *ierr = MPI_Waitany (*count, array_of_requests, index, (MPI_Status *)status);
}
