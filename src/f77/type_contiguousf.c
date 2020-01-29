
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_contiguous
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CONTIGUOUS() __attribute__ ((weak, alias("iscf_type_contiguous")));
void mpi_type_contiguous() __attribute__ ((weak, alias("iscf_type_contiguous")));
void mpi_type_contiguous_() __attribute__ ((weak, alias("iscf_type_contiguous")));
void mpi_type_contiguous__() __attribute__ ((weak, alias("iscf_type_contiguous")));
#endif

void iscf_type_contiguous(int *count, int *oldtype, int *newtype, int *ierr)
{
    *ierr = MPI_Type_contiguous (*count, *oldtype, newtype);
}
