
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Finalized
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FINALIZED() __attribute__ ((weak, alias("iscf_finalized")));
void mpi_finalized() __attribute__ ((weak, alias("iscf_finalized")));
void mpi_finalized_() __attribute__ ((weak, alias("iscf_finalized")));
void mpi_finalized__() __attribute__ ((weak, alias("iscf_finalized")));
#endif

void iscf_finalized(int *flag, int *ierr)
{
    *ierr = MPI_Finalized (flag);
}
