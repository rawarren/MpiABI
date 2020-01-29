
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Probe
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_PROBE() __attribute__ ((weak, alias("iscf_probe")));
void mpi_probe() __attribute__ ((weak, alias("iscf_probe")));
void mpi_probe_() __attribute__ ((weak, alias("iscf_probe")));
void mpi_probe__() __attribute__ ((weak, alias("iscf_probe")));
#endif

void iscf_probe(int *source, int *tag, int *comm, int *status, int *ierr)
{
    *ierr = MPI_Probe (*source, *tag, *comm, (MPI_Status *)status);
}
