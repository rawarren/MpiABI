
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Error_class
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ERROR_CLASS() __attribute__ ((weak, alias("iscf_error_class")));
void mpi_error_class() __attribute__ ((weak, alias("iscf_error_class")));
void mpi_error_class_() __attribute__ ((weak, alias("iscf_error_class")));
void mpi_error_class__() __attribute__ ((weak, alias("iscf_error_class")));
#endif

void iscf_error_class(int *errorcode, int *errorclass, int *ierr)
{
    *ierr = MPI_Error_class (*errorcode, errorclass);
}
