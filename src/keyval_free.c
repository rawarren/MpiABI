
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Keyval_free
 */

#include <_mpi.h>

int
MPI_Keyval_free (int *keyval)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a0 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Keyval_free")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Keyval_free",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int native_keyval = local_a0[*keyval].mpi_const;
  int (*VendorMPI_Keyval_free) (int *keyval) = address;
  mpi_return = (*VendorMPI_Keyval_free)(&native_keyval);
  if ((mpi_return == 0) && (native_keyval == local_a0[ISC_KEYVAL_INVALID_].mpi_const)) {
     if (attr_reference_exists(-1, *keyval,COMM_CALLBACK) == 0) {
        /* CAUTION: When will this index be freed (if not now)?
         * According to MPI-1, 5.7.1 we don't really free attributes
         * if they are in use...
	 * See: MPI_Attr_delete (?)
	 */
        free_index(active_miscs,*keyval);
     }
     *keyval = ISC_KEYVAL_INVALID;
  }
  return mpi_return;
}
