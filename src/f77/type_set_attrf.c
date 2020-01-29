
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_set_attr
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_SET_ATTR() __attribute__ ((weak, alias("iscf_type_set_attr")));
void mpi_type_set_attr() __attribute__ ((weak, alias("iscf_type_set_attr")));
void mpi_type_set_attr_() __attribute__ ((weak, alias("iscf_type_set_attr")));
void mpi_type_set_attr__() __attribute__ ((weak, alias("iscf_type_set_attr")));
#endif

void iscf_type_set_attr(int *type, int *type_keyval,  void *attr_val, int *ierr)
{
    *ierr = MPI_Type_set_attr (*type, *type_keyval, attr_val);
}
