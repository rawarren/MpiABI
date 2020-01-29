
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Errhandler_set
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ERRHANDLER_SET() __attribute__ ((weak, alias("iscf_errhandler_set")));
void mpi_errhandler_set() __attribute__ ((weak, alias("iscf_errhandler_set")));
void mpi_errhandler_set_() __attribute__ ((weak, alias("iscf_errhandler_set")));
void mpi_errhandler_set__() __attribute__ ((weak, alias("iscf_errhandler_set")));
#endif

void iscf_errhandler_set(int *comm, int *errhandler, int *ierr)
{
    *ierr = MPI_Errhandler_set (*comm, *errhandler);
}
