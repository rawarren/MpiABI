
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Waitsome
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_WAITSOME() __attribute__ ((weak, alias("iscf_waitsome")));
void mpi_waitsome() __attribute__ ((weak, alias("iscf_waitsome")));
void mpi_waitsome_() __attribute__ ((weak, alias("iscf_waitsome")));
void mpi_waitsome__() __attribute__ ((weak, alias("iscf_waitsome")));
#endif

void iscf_waitsome(int *incount, int array_of_requests[], int *outcount, int array_of_indices[], int array_of_statuses[], int *ierr)
{
  *ierr = MPI_Waitsome (*incount, array_of_requests, outcount, array_of_indices, (MPI_Status *)array_of_statuses);
}
