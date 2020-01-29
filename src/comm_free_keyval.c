
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_free_keyval
 */

#include <_mpi.h>

int
MPI_Comm_free_keyval (int *comm_keyval)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a0 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_free_keyval")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_free_keyval",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Comm_free_keyval) (int *comm_keyval) = address;
  int native_keyval = local_a0[*comm_keyval].mpi_const;
  mpi_return = (*VendorMPI_Comm_free_keyval)(&native_keyval);
  if ((mpi_return == 0) && (native_keyval == local_a0[ISC_KEYVAL_INVALID_].mpi_const)) {
    if (attr_reference_exists(-1, *comm_keyval,COMM_CALLBACK) == 0) {
      /* remove_object_keyval_callbacks(-1, *comm_keyval,COMM_CALLBACK); */
	free_index(active_miscs,*comm_keyval);
    }
    *comm_keyval = MPI_KEYVAL_INVALID;
  }
  return mpi_return;
}
