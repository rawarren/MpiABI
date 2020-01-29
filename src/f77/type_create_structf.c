
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_struct
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_STRUCT() __attribute__ ((weak, alias("iscf_type_create_struct")));
void mpi_type_create_struct() __attribute__ ((weak, alias("iscf_type_create_struct")));
void mpi_type_create_struct_() __attribute__ ((weak, alias("iscf_type_create_struct")));
void mpi_type_create_struct__() __attribute__ ((weak, alias("iscf_type_create_struct")));
#endif

void iscf_type_create_struct(int *count, int array_of_block_lengths[], MPI_Aint array_of_displacements[], int array_of_types[], int *newtype, int *ierr)
{
    *ierr = MPI_Type_create_struct (*count, array_of_block_lengths, array_of_displacements, array_of_types, newtype);
}
