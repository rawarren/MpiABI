
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Pcontrol
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_PCONTROL() __attribute__ ((weak, alias("iscf_pcontrol")));
void mpi_pcontrol() __attribute__ ((weak, alias("iscf_pcontrol")));
void mpi_pcontrol_() __attribute__ ((weak, alias("iscf_pcontrol")));
void mpi_pcontrol__() __attribute__ ((weak, alias("iscf_pcontrol")));
#endif

void iscf_pcontrol(int *level, int *ierr)
{
    *ierr = MPI_Pcontrol (*level);
}
