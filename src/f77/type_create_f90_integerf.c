
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_f90_integer
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_F90_INTEGER() __attribute__ ((weak, alias("iscf_type_create_f90_integer")));
void mpi_type_create_f90_integer() __attribute__ ((weak, alias("iscf_type_create_f90_integer")));
void mpi_type_create_f90_integer_() __attribute__ ((weak, alias("iscf_type_create_f90_integer")));
void mpi_type_create_f90_integer__() __attribute__ ((weak, alias("iscf_type_create_f90_integer")));
#endif

void iscf_type_create_f90_integer(int *r, int *newtype, int *ierr)
{
    *ierr = MPI_Type_create_f90_integer (*r, newtype);
}
