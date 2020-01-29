
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Initialized
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INITIALIZED() __attribute__ ((weak, alias("iscf_initialized")));
void mpi_initialized() __attribute__ ((weak, alias("iscf_initialized")));
void mpi_initialized_() __attribute__ ((weak, alias("iscf_initialized")));
void mpi_initialized__() __attribute__ ((weak, alias("iscf_initialized")));
#endif

void iscf_initialized(int *flag, int *ierr)
{
    *ierr = MPI_Initialized (flag);
}
