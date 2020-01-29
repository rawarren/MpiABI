
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_set_name
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_SET_NAME() __attribute__ ((weak, alias("iscf_type_set_name")));
void mpi_type_set_name() __attribute__ ((weak, alias("iscf_type_set_name")));
void mpi_type_set_name_() __attribute__ ((weak, alias("iscf_type_set_name")));
void mpi_type_set_name__() __attribute__ ((weak, alias("iscf_type_set_name")));
#endif

void iscf_type_set_name(int *type,  char *type_name, int *ierr)
{
    *ierr = MPI_Type_set_name (*type, type_name);
}
