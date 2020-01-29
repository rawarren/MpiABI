
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_subarray
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_SUBARRAY() __attribute__ ((weak, alias("iscf_type_create_subarray")));
void mpi_type_create_subarray() __attribute__ ((weak, alias("iscf_type_create_subarray")));
void mpi_type_create_subarray_() __attribute__ ((weak, alias("iscf_type_create_subarray")));
void mpi_type_create_subarray__() __attribute__ ((weak, alias("iscf_type_create_subarray")));
#endif

void iscf_type_create_subarray(int *ndims, int size_array[], int subsize_array[], int start_array[], int *order, int *oldtype, int *newtype, int *ierr)
{
    *ierr = MPI_Type_create_subarray (*ndims, size_array, subsize_array, start_array, *order, *oldtype, newtype);
}
