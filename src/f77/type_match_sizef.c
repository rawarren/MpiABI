
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_match_size
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_MATCH_SIZE() __attribute__ ((weak, alias("iscf_type_match_size")));
void mpi_type_match_size() __attribute__ ((weak, alias("iscf_type_match_size")));
void mpi_type_match_size_() __attribute__ ((weak, alias("iscf_type_match_size")));
void mpi_type_match_size__() __attribute__ ((weak, alias("iscf_type_match_size")));
#endif

void iscf_type_match_size(int *typeclass, int *size, int *type, int *ierr)
{
    *ierr = MPI_Type_match_size (*typeclass, *size, type);
}
