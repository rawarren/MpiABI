
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_indexed_block
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_INDEXED_BLOCK() __attribute__ ((weak, alias("iscf_type_create_indexed_block")));
void mpi_type_create_indexed_block() __attribute__ ((weak, alias("iscf_type_create_indexed_block")));
void mpi_type_create_indexed_block_() __attribute__ ((weak, alias("iscf_type_create_indexed_block")));
void mpi_type_create_indexed_block__() __attribute__ ((weak, alias("iscf_type_create_indexed_block")));
#endif

void iscf_type_create_indexed_block(int *count, int *blocklength, int array_of_displacements[], int *oldtype, int *newtype, int *ierr)
{
    *ierr = MPI_Type_create_indexed_block (*count, *blocklength, array_of_displacements, *oldtype, newtype);
}
