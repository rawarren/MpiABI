
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Testall
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TESTALL() __attribute__ ((weak, alias("iscf_testall")));
void mpi_testall() __attribute__ ((weak, alias("iscf_testall")));
void mpi_testall_() __attribute__ ((weak, alias("iscf_testall")));
void mpi_testall__() __attribute__ ((weak, alias("iscf_testall")));
#endif

void iscf_testall(int *count, int array_of_requests[], int *flag, int array_of_statuses[], int *ierr)
{
  *ierr = MPI_Testall (*count, array_of_requests, flag, (MPI_Status *)array_of_statuses);
}
