
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Errhandler_get
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ERRHANDLER_GET() __attribute__ ((weak, alias("iscf_errhandler_get")));
void mpi_errhandler_get() __attribute__ ((weak, alias("iscf_errhandler_get")));
void mpi_errhandler_get_() __attribute__ ((weak, alias("iscf_errhandler_get")));
void mpi_errhandler_get__() __attribute__ ((weak, alias("iscf_errhandler_get")));
#endif

void iscf_errhandler_get(int *comm, int *errhandler, int *ierr)
{
    *ierr = MPI_Errhandler_get (*comm, errhandler);
}
