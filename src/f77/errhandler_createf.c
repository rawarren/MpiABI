
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Errhandler_create
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ERRHANDLER_CREATE() __attribute__ ((weak, alias("iscf_errhandler_create")));
void mpi_errhandler_create() __attribute__ ((weak, alias("iscf_errhandler_create")));
void mpi_errhandler_create_() __attribute__ ((weak, alias("iscf_errhandler_create")));
void mpi_errhandler_create__() __attribute__ ((weak, alias("iscf_errhandler_create")));
#endif

void iscf_errhandler_create(void *function, int *errhandler, int *ierr)
{
  *ierr = MPI_Errhandler_create ((MPI_Handler_function *)function, errhandler);
}
