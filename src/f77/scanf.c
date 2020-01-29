
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Scan
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_SCAN() __attribute__ ((weak, alias("iscf_scan")));
void mpi_scan() __attribute__ ((weak, alias("iscf_scan")));
void mpi_scan_() __attribute__ ((weak, alias("iscf_scan")));
void mpi_scan__() __attribute__ ((weak, alias("iscf_scan")));
#endif

void iscf_scan(void *sendbuf, void *recvbuf, int *count, int *datatype, int *op, int *comm, int *ierr)
{
  *ierr = MPI_Scan (FINPLACE(sendbuf), FINPLACE(recvbuf), *count, *datatype, *op, *comm);
}
