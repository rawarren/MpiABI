
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Attr_put
 */

#include <_mpi.h>

int
MPI_Attr_put (MPI_Comm comm, int keyval, void *attribute_val)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a1 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Attr_put")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Attr_put",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  /* See related: MPI_Comm_create_attr */
  maybe_update_callbacks(comm, keyval, COMM_CALLBACK);

  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Attr_put)(void *,int keyval, void *attribute_val) = address;
    mpi_return = (*VendorMPI_Attr_put)(local_a0[comm].mpi_const,local_a1[keyval].mpi_const,attribute_val);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Attr_put)(int,int keyval, void *attribute_val) = address;
    mpi_return = (*VendorMPI_Attr_put)(local_a0[comm].mpi_const,local_a1[keyval].mpi_const,attribute_val);
  }
  return mpi_return;
}
