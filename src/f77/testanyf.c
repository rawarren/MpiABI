
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Testany
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TESTANY() __attribute__ ((weak, alias("iscf_testany")));
void mpi_testany() __attribute__ ((weak, alias("iscf_testany")));
void mpi_testany_() __attribute__ ((weak, alias("iscf_testany")));
void mpi_testany__() __attribute__ ((weak, alias("iscf_testany")));
#endif

void iscf_testany(int *count, int array_of_requests[], int *index, int *flag, int *status, int *ierr)
{
    *ierr = MPI_Testany (*count, array_of_requests, index, flag, (MPI_Status *)status);
}
