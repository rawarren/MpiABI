
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_keyval
 */

#include <_mpi.h>

int
MPI_Type_create_keyval (MPI_Type_copy_attr_function *type_copy_attr_fn, MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state)
{
  static void *address=0;
  int native_keyval=0;
  int mpi_return;
  api_use_ints *local_a0 = NULL;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_create_keyval")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_create_keyval",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  
  int (*VendorMPI_Type_create_keyval) (MPI_Type_copy_attr_function *, MPI_Type_delete_attr_function *, int *, void *) = address;
  mpi_return = (*VendorMPI_Type_create_keyval)(NULLTYPCOPYFN(type_copy_attr_fn),NULLTYPDELFN(type_delete_attr_fn),&native_keyval,extra_state);
  if (mpi_return == 0) {
    *type_keyval = new_index(active_miscs);
    local_a0 = active_miscs->api_declared; /* CAUTION: This reference needs to be here because 'new_index' may reallocate storage!! */
    local_a0[*type_keyval].mpi_const = native_keyval;
    if (type_copy_attr_fn != MPI_NULL_COPY_FN) {
      save_user_copy_callback(type_copy_attr_fn,*type_keyval,DATATYPE_CALLBACK);
    }
    if (type_delete_attr_fn != MPI_NULL_DELETE_FN) {
      save_user_delete_callback(type_delete_attr_fn,*type_keyval,DATATYPE_CALLBACK);
    }
  }
  return mpi_return;
}
