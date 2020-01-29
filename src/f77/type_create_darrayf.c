
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_darray
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_DARRAY() __attribute__ ((weak, alias("iscf_type_create_darray")));
void mpi_type_create_darray() __attribute__ ((weak, alias("iscf_type_create_darray")));
void mpi_type_create_darray_() __attribute__ ((weak, alias("iscf_type_create_darray")));
void mpi_type_create_darray__() __attribute__ ((weak, alias("iscf_type_create_darray")));
#endif

void iscf_type_create_darray(int *size, int *rank, int *ndims, int gsize_array[], int distrib_array[], int darg_array[], int psize_array[], int *order, int *oldtype, int *newtype, int *ierr)
{
    *ierr = MPI_Type_create_darray (*size, *rank, *ndims, gsize_array, distrib_array, darg_array, psize_array, *order, *oldtype, newtype);
}
