
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_hvector
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_HVECTOR() __attribute__ ((weak, alias("iscf_type_create_hvector")));
void mpi_type_create_hvector() __attribute__ ((weak, alias("iscf_type_create_hvector")));
void mpi_type_create_hvector_() __attribute__ ((weak, alias("iscf_type_create_hvector")));
void mpi_type_create_hvector__() __attribute__ ((weak, alias("iscf_type_create_hvector")));
#endif

void iscf_type_create_hvector(int *count, int *blocklength, MPI_Aint *stride, int *oldtype, int *newtype, int *ierr)
{
    *ierr = MPI_Type_create_hvector (*count, *blocklength, *stride, *oldtype, newtype);
}
