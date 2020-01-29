
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Grequest_complete
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GREQUEST_COMPLETE() __attribute__ ((weak, alias("iscf_grequest_complete")));
void mpi_grequest_complete() __attribute__ ((weak, alias("iscf_grequest_complete")));
void mpi_grequest_complete_() __attribute__ ((weak, alias("iscf_grequest_complete")));
void mpi_grequest_complete__() __attribute__ ((weak, alias("iscf_grequest_complete")));
#endif

void iscf_grequest_complete(int *request, int *ierr)
{
    *ierr = MPI_Grequest_complete (*request);
}
