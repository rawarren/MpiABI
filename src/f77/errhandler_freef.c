
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Errhandler_free
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ERRHANDLER_FREE() __attribute__ ((weak, alias("iscf_errhandler_free")));
void mpi_errhandler_free() __attribute__ ((weak, alias("iscf_errhandler_free")));
void mpi_errhandler_free_() __attribute__ ((weak, alias("iscf_errhandler_free")));
void mpi_errhandler_free__() __attribute__ ((weak, alias("iscf_errhandler_free")));
#endif

void iscf_errhandler_free(int *errhandler, int *ierr)
{
    *ierr = MPI_Errhandler_free (errhandler);
}
