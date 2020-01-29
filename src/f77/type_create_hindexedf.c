
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_hindexed
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_HINDEXED() __attribute__ ((weak, alias("iscf_type_create_hindexed")));
void mpi_type_create_hindexed() __attribute__ ((weak, alias("iscf_type_create_hindexed")));
void mpi_type_create_hindexed_() __attribute__ ((weak, alias("iscf_type_create_hindexed")));
void mpi_type_create_hindexed__() __attribute__ ((weak, alias("iscf_type_create_hindexed")));
#endif

void iscf_type_create_hindexed(int *count, int array_of_blocklengths[], MPI_Aint array_of_displacements[], int *oldtype, int *newtype, int *ierr)
{
    *ierr = MPI_Type_create_hindexed (*count, array_of_blocklengths, array_of_displacements, *oldtype, newtype);
}
