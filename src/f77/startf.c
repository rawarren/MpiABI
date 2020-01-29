
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Start
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_START() __attribute__ ((weak, alias("iscf_start")));
void mpi_start() __attribute__ ((weak, alias("iscf_start")));
void mpi_start_() __attribute__ ((weak, alias("iscf_start")));
void mpi_start__() __attribute__ ((weak, alias("iscf_start")));
#endif

void iscf_start(int *request, int *ierr)
{
    *ierr = MPI_Start (request);
}
