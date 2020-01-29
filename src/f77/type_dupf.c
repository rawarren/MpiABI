
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_dup
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_DUP() __attribute__ ((weak, alias("iscf_type_dup")));
void mpi_type_dup() __attribute__ ((weak, alias("iscf_type_dup")));
void mpi_type_dup_() __attribute__ ((weak, alias("iscf_type_dup")));
void mpi_type_dup__() __attribute__ ((weak, alias("iscf_type_dup")));
#endif

void iscf_type_dup(int *type, int *newtype, int *ierr)
{
    *ierr = MPI_Type_dup (*type, newtype);
}
