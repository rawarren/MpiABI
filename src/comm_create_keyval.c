
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_create_keyval
 */

#include <_mpi.h>

int
MPI_Comm_create_keyval (MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state)
{
  static void *address=0;
  int mpi_return;

  api_use_ints *local_a0 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_create_keyval")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_create_keyval",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int native_keyval = 0;

  int (*VendorMPI_Comm_create_keyval) (MPI_Comm_copy_attr_function *, MPI_Comm_delete_attr_function *, int *, void *) = address;
  mpi_return = (*VendorMPI_Comm_create_keyval)(NULLCOPYFN(comm_copy_attr_fn),NULLDELFN(comm_delete_attr_fn),&native_keyval,extra_state);
  if (mpi_return == 0) {
    *comm_keyval = new_index(active_miscs);
    local_a0[*comm_keyval].mpi_const = native_keyval;
    if (comm_copy_attr_fn != MPI_NULL_COPY_FN) {
      save_user_copy_callback(comm_copy_attr_fn,*comm_keyval,COMM_CALLBACK);
    }
    if (comm_delete_attr_fn != MPI_NULL_DELETE_FN) {
      save_user_delete_callback(comm_delete_attr_fn,*comm_keyval,COMM_CALLBACK);
    }
  }
  return mpi_return;
}
