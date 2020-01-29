
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Add_error_class
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ADD_ERROR_CLASS() __attribute__ ((weak, alias("iscf_add_error_class")));
void mpi_add_error_class() __attribute__ ((weak, alias("iscf_add_error_class")));
void mpi_add_error_class_() __attribute__ ((weak, alias("iscf_add_error_class")));
void mpi_add_error_class__() __attribute__ ((weak, alias("iscf_add_error_class")));
#endif

void iscf_add_error_class(int *errorclass, int *ierr)
{
    *ierr = MPI_Add_error_class (errorclass);
}
