
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_name
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_GET_NAME() __attribute__ ((weak, alias("iscf_type_get_name")));
void mpi_type_get_name() __attribute__ ((weak, alias("iscf_type_get_name")));
void mpi_type_get_name_() __attribute__ ((weak, alias("iscf_type_get_name")));
void mpi_type_get_name__() __attribute__ ((weak, alias("iscf_type_get_name")));
#endif

void iscf_type_get_name(int *type, char *type_name, int *resultlen, int *ierr)
{
    *ierr = MPI_Type_get_name (*type, type_name, resultlen);
}
