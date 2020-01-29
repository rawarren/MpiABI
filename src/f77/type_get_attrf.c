
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_attr
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_GET_ATTR() __attribute__ ((weak, alias("iscf_type_get_attr")));
void mpi_type_get_attr() __attribute__ ((weak, alias("iscf_type_get_attr")));
void mpi_type_get_attr_() __attribute__ ((weak, alias("iscf_type_get_attr")));
void mpi_type_get_attr__() __attribute__ ((weak, alias("iscf_type_get_attr")));
#endif

void iscf_type_get_attr(int *type, int *type_keyval, void *attribute_val, int *flag, int *ierr)
{
    *ierr = MPI_Type_get_attr (*type, *type_keyval, attribute_val, flag);
}
