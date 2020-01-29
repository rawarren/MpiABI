
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Intercomm_merge
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INTERCOMM_MERGE() __attribute__ ((weak, alias("iscf_intercomm_merge")));
void mpi_intercomm_merge() __attribute__ ((weak, alias("iscf_intercomm_merge")));
void mpi_intercomm_merge_() __attribute__ ((weak, alias("iscf_intercomm_merge")));
void mpi_intercomm_merge__() __attribute__ ((weak, alias("iscf_intercomm_merge")));
#endif

void iscf_intercomm_merge(int *intercomm, int *high, int *newintercomm, int *ierr)
{
    *ierr = MPI_Intercomm_merge (*intercomm, *high, newintercomm);
}
