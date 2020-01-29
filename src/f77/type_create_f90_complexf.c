
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_f90_complex
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_F90_COMPLEX() __attribute__ ((weak, alias("iscf_type_create_f90_complex")));
void mpi_type_create_f90_complex() __attribute__ ((weak, alias("iscf_type_create_f90_complex")));
void mpi_type_create_f90_complex_() __attribute__ ((weak, alias("iscf_type_create_f90_complex")));
void mpi_type_create_f90_complex__() __attribute__ ((weak, alias("iscf_type_create_f90_complex")));
#endif

void iscf_type_create_f90_complex(int *p, int *r, int *newtype, int *ierr)
{
    *ierr = MPI_Type_create_f90_complex (*p, *r, newtype);
}
