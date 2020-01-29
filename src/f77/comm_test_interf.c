
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_test_inter
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_TEST_INTER() __attribute__ ((weak, alias("iscf_comm_test_inter")));
void mpi_comm_test_inter() __attribute__ ((weak, alias("iscf_comm_test_inter")));
void mpi_comm_test_inter_() __attribute__ ((weak, alias("iscf_comm_test_inter")));
void mpi_comm_test_inter__() __attribute__ ((weak, alias("iscf_comm_test_inter")));
#endif

void iscf_comm_test_inter(int *comm, int *flag, int *ierr)
{
    *ierr = MPI_Comm_test_inter (*comm, flag);
}
