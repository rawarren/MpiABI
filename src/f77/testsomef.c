
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Testsome
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TESTSOME() __attribute__ ((weak, alias("iscf_testsome")));
void mpi_testsome() __attribute__ ((weak, alias("iscf_testsome")));
void mpi_testsome_() __attribute__ ((weak, alias("iscf_testsome")));
void mpi_testsome__() __attribute__ ((weak, alias("iscf_testsome")));
#endif

void iscf_testsome(int *incount, int array_of_requests[], int *outcount, int array_of_indices[], int array_of_statuses[], int *ierr)
{
  *ierr = MPI_Testsome (*incount, array_of_requests, outcount, array_of_indices, (MPI_Status *)array_of_statuses);
}
