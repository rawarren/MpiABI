
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_f90_real
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_F90_REAL() __attribute__ ((weak, alias("iscf_type_create_f90_real")));
void mpi_type_create_f90_real() __attribute__ ((weak, alias("iscf_type_create_f90_real")));
void mpi_type_create_f90_real_() __attribute__ ((weak, alias("iscf_type_create_f90_real")));
void mpi_type_create_f90_real__() __attribute__ ((weak, alias("iscf_type_create_f90_real")));
#endif

void iscf_type_create_f90_real(int *p, int *r, int *newtype, int *ierr)
{
    *ierr = MPI_Type_create_f90_real (*p, *r, newtype);
}
