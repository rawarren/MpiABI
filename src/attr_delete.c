
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Attr_delete
 */

#include <_mpi.h>

int
MPI_Attr_delete (MPI_Comm comm, int keyval)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a1 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Attr_delete")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Attr_delete",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Attr_delete)(void *, int keyval) = address;
    mpi_return = (*VendorMPI_Attr_delete)(local_a0[comm].mpi_const,local_a1[keyval].mpi_const);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Attr_delete)(int, int keyval) = address;
    mpi_return = (*VendorMPI_Attr_delete)(local_a0[comm].mpi_const,local_a1[keyval].mpi_const);
  }
#if 1
  if ((mpi_return == 0) && (attr_reference_exists(-1, keyval,COMM_CALLBACK) > 0)) {
    remove_object_keyval_callbacks(comm,keyval,COMM_CALLBACK);
    /* free_index(active_miscs,keyval); */
  }
#endif
  return mpi_return;
}
