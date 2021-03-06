
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_set_attr
 */

#include <_mpi.h>

int
MPI_Comm_set_attr (MPI_Comm comm, int comm_keyval, void *attribute_val)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a1 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_set_attr")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_set_attr",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  /* See related: MPI_Comm_create_attr */
  maybe_update_callbacks(comm,comm_keyval,COMM_CALLBACK);

  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_set_attr)(void *,int comm_keyval, void *attribute_val) = address;
    mpi_return = (*VendorMPI_Comm_set_attr)(local_a0[comm].mpi_const,local_a1[comm_keyval].mpi_const,attribute_val);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_set_attr)(int,int comm_keyval, void *attribute_val) = address;
    mpi_return = (*VendorMPI_Comm_set_attr)(local_a0[comm].mpi_const,local_a1[comm_keyval].mpi_const,attribute_val);
  }
  return mpi_return;
}
