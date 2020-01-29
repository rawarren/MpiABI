
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_size
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_SIZE() __attribute__ ((weak, alias("iscf_type_size")));
void mpi_type_size() __attribute__ ((weak, alias("iscf_type_size")));
void mpi_type_size_() __attribute__ ((weak, alias("iscf_type_size")));
void mpi_type_size__() __attribute__ ((weak, alias("iscf_type_size")));
#endif

void iscf_type_size(int *type, int *size, int *ierr)
{
    *ierr = MPI_Type_size (*type, size);
}
