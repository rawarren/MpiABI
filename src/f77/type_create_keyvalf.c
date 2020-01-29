
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_keyval
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_CREATE_KEYVAL() __attribute__ ((weak, alias("iscf_type_create_keyval")));
void mpi_type_create_keyval() __attribute__ ((weak, alias("iscf_type_create_keyval")));
void mpi_type_create_keyval_() __attribute__ ((weak, alias("iscf_type_create_keyval")));
void mpi_type_create_keyval__() __attribute__ ((weak, alias("iscf_type_create_keyval")));
#endif

void iscf_type_create_keyval(int *type_copy_attr_fn, int *type_delete_attr_fn, int *type_keyval,  void *extra_state, int *ierr)
{
  *ierr = MPI_Type_create_keyval ((MPI_Type_copy_attr_function *)type_copy_attr_fn, 
				  (MPI_Type_delete_attr_function *)type_delete_attr_fn, type_keyval, extra_state);
}
