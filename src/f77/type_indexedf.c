
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_indexed
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_INDEXED() __attribute__ ((weak, alias("iscf_type_indexed")));
void mpi_type_indexed() __attribute__ ((weak, alias("iscf_type_indexed")));
void mpi_type_indexed_() __attribute__ ((weak, alias("iscf_type_indexed")));
void mpi_type_indexed__() __attribute__ ((weak, alias("iscf_type_indexed")));
#endif

void iscf_type_indexed(int *count, int array_of_blocklengths[], int array_of_displacements[], int *oldtype, int *newtype, int *ierr)
{
    *ierr = MPI_Type_indexed (*count, array_of_blocklengths, array_of_displacements, *oldtype, newtype);
}
