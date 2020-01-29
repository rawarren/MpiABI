
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_hvector
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_HVECTOR() __attribute__ ((weak, alias("iscf_type_hvector")));
void mpi_type_hvector() __attribute__ ((weak, alias("iscf_type_hvector")));
void mpi_type_hvector_() __attribute__ ((weak, alias("iscf_type_hvector")));
void mpi_type_hvector__() __attribute__ ((weak, alias("iscf_type_hvector")));
#endif

void iscf_type_hvector(int *count, int *blocklength, int *stride, int *oldtype, int *newtype, int *ierr)
{
    MPI_Aint true_stride = *stride;
    *ierr = MPI_Type_hvector (*count, *blocklength, true_stride, *oldtype, newtype);
}
