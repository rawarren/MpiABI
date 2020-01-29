
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Allreduce
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ALLREDUCE() __attribute__ ((weak, alias("iscf_allreduce")));
void mpi_allreduce() __attribute__ ((weak, alias("iscf_allreduce")));
void mpi_allreduce_() __attribute__ ((weak, alias("iscf_allreduce")));
void mpi_allreduce__() __attribute__ ((weak, alias("iscf_allreduce")));
#endif

void iscf_allreduce(void *sendbuf, void *recvbuf, int *count, int *datatype, int *op, int *comm, int *ierr)
{
  *ierr = MPI_Allreduce (FINPLACE(sendbuf), FINPLACE(recvbuf), *count, *datatype, *op, *comm);
}
