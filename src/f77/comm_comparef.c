
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_compare
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_COMPARE() __attribute__ ((weak, alias("iscf_comm_compare")));
void mpi_comm_compare() __attribute__ ((weak, alias("iscf_comm_compare")));
void mpi_comm_compare_() __attribute__ ((weak, alias("iscf_comm_compare")));
void mpi_comm_compare__() __attribute__ ((weak, alias("iscf_comm_compare")));
#endif

void iscf_comm_compare(int *comm1, int *comm2, int *result, int *ierr)
{
    *ierr = MPI_Comm_compare (*comm1, *comm2, result);
}
