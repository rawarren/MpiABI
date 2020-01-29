
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_delete_attr
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_DELETE_ATTR() __attribute__ ((weak, alias("iscf_type_delete_attr")));
void mpi_type_delete_attr() __attribute__ ((weak, alias("iscf_type_delete_attr")));
void mpi_type_delete_attr_() __attribute__ ((weak, alias("iscf_type_delete_attr")));
void mpi_type_delete_attr__() __attribute__ ((weak, alias("iscf_type_delete_attr")));
#endif

void iscf_type_delete_attr(int *type, int *type_keyval, int *ierr)
{
    *ierr = MPI_Type_delete_attr (*type, *type_keyval);
}
