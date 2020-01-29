
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_resized
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_RESIZED() __attribute__ ((weak, alias("iscf_type_create_resized")));
void mpi_type_create_resized() __attribute__ ((weak, alias("iscf_type_create_resized")));
void mpi_type_create_resized_() __attribute__ ((weak, alias("iscf_type_create_resized")));
void mpi_type_create_resized__() __attribute__ ((weak, alias("iscf_type_create_resized")));
#endif

void iscf_type_create_resized(int *oldtype, MPI_Aint *lb, MPI_Aint *extent, int *newtype, int *ierr)
{
    *ierr = MPI_Type_create_resized (*oldtype, *lb, *extent, newtype);
}
