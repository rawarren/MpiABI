
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Startall
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_STARTALL() __attribute__ ((weak, alias("iscf_startall")));
void mpi_startall() __attribute__ ((weak, alias("iscf_startall")));
void mpi_startall_() __attribute__ ((weak, alias("iscf_startall")));
void mpi_startall__() __attribute__ ((weak, alias("iscf_startall")));
#endif

void iscf_startall(int *count, int *array_of_requests, int *ierr)
{
    *ierr = MPI_Startall (*count, array_of_requests);
}
