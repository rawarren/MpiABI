
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Topo_test
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TOPO_TEST() __attribute__ ((weak, alias("iscf_topo_test")));
void mpi_topo_test() __attribute__ ((weak, alias("iscf_topo_test")));
void mpi_topo_test_() __attribute__ ((weak, alias("iscf_topo_test")));
void mpi_topo_test__() __attribute__ ((weak, alias("iscf_topo_test")));
#endif

void iscf_topo_test(int *comm, int *status, int *ierr)
{
    *ierr = MPI_Topo_test (*comm, status);
}
