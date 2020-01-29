
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_delete_attr
 */

#include <_mpi.h>

int
MPI_Comm_delete_attr (MPI_Comm comm, int comm_keyval)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a1 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_delete_attr")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_delete_attr",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_delete_attr)(void *, int comm_keyval) = address;
    mpi_return = (*VendorMPI_Comm_delete_attr)(local_a0[comm].mpi_const,local_a1[comm_keyval].mpi_const);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_delete_attr)(int, int comm_keyval) = address;
    mpi_return = (*VendorMPI_Comm_delete_attr)(local_a0[comm].mpi_const,local_a1[comm_keyval].mpi_const);
  }

  if ((mpi_return == 0) && (attr_reference_exists(comm,comm_keyval,COMM_CALLBACK) == 0)) {
    remove_object_keyval_callbacks(comm,comm_keyval,COMM_CALLBACK);
    free_index(active_miscs,comm_keyval);
  }

  return mpi_return;
}
