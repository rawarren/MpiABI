
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Keyval_create
 */

#include <_mpi.h>

int
MPI_Keyval_create (MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void *extra_state)
{
  static void *address=0;
  int native_keyval=0;
  int mpi_const = 0;
  int mpi_return;

  api_use_ints *local_a0 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Keyval_create")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Keyval_create",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Keyval_create) (void *copy_fn, void *delete_fn, int *keyval, void *extra_state) = address;
  mpi_return = (*VendorMPI_Keyval_create)(NULLCOPYFN(copy_fn),NULLDELFN(delete_fn),&native_keyval,extra_state);

  if (mpi_return == 0) {
    *keyval = new_index(active_miscs);
    local_a0[*keyval].mpi_const = native_keyval;
    if (copy_fn != MPI_NULL_COPY_FN) {
      save_user_copy_callback(copy_fn,*keyval,COMM_CALLBACK);
    }
    if (delete_fn != MPI_NULL_DELETE_FN) {
      save_user_delete_callback(delete_fn,*keyval,COMM_CALLBACK);
    }
  }
  return mpi_return;
}
