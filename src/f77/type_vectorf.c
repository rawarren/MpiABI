
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_vector
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_VECTOR() __attribute__ ((weak, alias("iscf_type_vector")));
void mpi_type_vector() __attribute__ ((weak, alias("iscf_type_vector")));
void mpi_type_vector_() __attribute__ ((weak, alias("iscf_type_vector")));
void mpi_type_vector__() __attribute__ ((weak, alias("iscf_type_vector")));
#endif

void iscf_type_vector(int *count, int *blocklength, int *stride, int *oldtype, int *newtype, int *ierr)
{
    *ierr = MPI_Type_vector (*count, *blocklength, *stride, *oldtype, newtype);
}
