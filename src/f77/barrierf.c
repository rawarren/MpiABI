
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Barrier
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_BARRIER() __attribute__ ((weak, alias("iscf_barrier")));
void mpi_barrier() __attribute__ ((weak, alias("iscf_barrier")));
void mpi_barrier_() __attribute__ ((weak, alias("iscf_barrier")));
void mpi_barrier__() __attribute__ ((weak, alias("iscf_barrier")));
#endif

void iscf_barrier(int *comm, int *ierr)
{
    *ierr = MPI_Barrier (*comm);
}
