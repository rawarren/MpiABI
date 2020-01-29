
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Wtick
 */

#include <_mpi.h>

#ifdef __GNUC__
double MPI_WTICK() __attribute__ ((weak, alias("iscf_wtick")));
double mpi_wtick() __attribute__ ((weak, alias("iscf_wtick")));
double mpi_wtick_() __attribute__ ((weak, alias("iscf_wtick")));
double mpi_wtick__() __attribute__ ((weak, alias("iscf_wtick")));
#endif

double iscf_wtick(void)
{
    return MPI_Wtick ();
}
