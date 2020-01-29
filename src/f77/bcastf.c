
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Bcast
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_BCAST() __attribute__ ((weak, alias("iscf_bcast")));
void mpi_bcast() __attribute__ ((weak, alias("iscf_bcast")));
void mpi_bcast_() __attribute__ ((weak, alias("iscf_bcast")));
void mpi_bcast__() __attribute__ ((weak, alias("iscf_bcast")));
#endif

void iscf_bcast(void *buffer, int *count, int *datatype, int *root, int *comm, int *ierr)
{
  *ierr = MPI_Bcast (FINPLACE(buffer), *count, *datatype, *root, *comm);
}
