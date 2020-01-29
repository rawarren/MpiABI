
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Wtime
 */

#include <_mpi.h>

#ifdef __GNUC__
double MPI_WTIME() __attribute__ ((weak, alias("iscf_wtime")));
double mpi_wtime() __attribute__ ((weak, alias("iscf_wtime")));
double mpi_wtime_() __attribute__ ((weak, alias("iscf_wtime")));
double mpi_wtime__() __attribute__ ((weak, alias("iscf_wtime")));
#endif

double iscf_wtime(int *ierr)
{
  return MPI_Wtime ();
}
