
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Exscan
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_EXSCAN() __attribute__ ((weak, alias("iscf_exscan")));
void mpi_exscan() __attribute__ ((weak, alias("iscf_exscan")));
void mpi_exscan_() __attribute__ ((weak, alias("iscf_exscan")));
void mpi_exscan__() __attribute__ ((weak, alias("iscf_exscan")));
#endif

void iscf_exscan(void *sendbuf, void *recvbuf, int *count, int *datatype, int *op, int *comm, int *ierr)
{
    *ierr = MPI_Exscan (sendbuf, recvbuf, *count, *datatype, *op, *comm);
}
