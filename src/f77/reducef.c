
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Reduce
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_REDUCE() __attribute__ ((weak, alias("iscf_reduce")));
void mpi_reduce() __attribute__ ((weak, alias("iscf_reduce")));
void mpi_reduce_() __attribute__ ((weak, alias("iscf_reduce")));
void mpi_reduce__() __attribute__ ((weak, alias("iscf_reduce")));
#endif

void iscf_reduce(void *sendbuf, void *recvbuf, int *count, int *datatype, int *op, int *root, int *comm, int *ierr)
{
  *ierr = MPI_Reduce (FINPLACE(sendbuf), FINPLACE(recvbuf), *count, *datatype, *op, *root, *comm);
}
