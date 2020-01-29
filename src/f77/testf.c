
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Test
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TEST() __attribute__ ((weak, alias("iscf_test")));
void mpi_test() __attribute__ ((weak, alias("iscf_test")));
void mpi_test_() __attribute__ ((weak, alias("iscf_test")));
void mpi_test__() __attribute__ ((weak, alias("iscf_test")));
#endif

void iscf_test(int *request, int *flag, int *status, int *ierr)
{
    *ierr = MPI_Test (request, flag, (MPI_Status *)status);
}
