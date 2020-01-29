
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Test_cancelled
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TEST_CANCELLED() __attribute__ ((weak, alias("iscf_test_cancelled")));
void mpi_test_cancelled() __attribute__ ((weak, alias("iscf_test_cancelled")));
void mpi_test_cancelled_() __attribute__ ((weak, alias("iscf_test_cancelled")));
void mpi_test_cancelled__() __attribute__ ((weak, alias("iscf_test_cancelled")));
#endif

void iscf_test_cancelled(int *status, int *flag, int *ierr)
{
    *ierr = MPI_Test_cancelled ((MPI_Status *)status, flag);
}
