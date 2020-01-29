
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_free
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_FREE() __attribute__ ((weak, alias("iscf_type_free")));
void mpi_type_free() __attribute__ ((weak, alias("iscf_type_free")));
void mpi_type_free_() __attribute__ ((weak, alias("iscf_type_free")));
void mpi_type_free__() __attribute__ ((weak, alias("iscf_type_free")));
#endif

void iscf_type_free(int *type, int *ierr)
{
    *ierr = MPI_Type_free (type);
}
