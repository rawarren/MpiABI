
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Iprobe
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_IPROBE() __attribute__ ((weak, alias("iscf_iprobe")));
void mpi_iprobe() __attribute__ ((weak, alias("iscf_iprobe")));
void mpi_iprobe_() __attribute__ ((weak, alias("iscf_iprobe")));
void mpi_iprobe__() __attribute__ ((weak, alias("iscf_iprobe")));
#endif

void iscf_iprobe(int *source, int *tag, int *comm, int *flag, int *status, int *ierr)
{
    *ierr = MPI_Iprobe (*source, *tag, *comm, flag, (MPI_Status *)status);
}
