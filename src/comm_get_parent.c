
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_get_parent
 */

#include <_mpi.h>

int
MPI_Comm_get_parent (MPI_Comm *parent)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_get_parent")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_get_parent",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *parent = new_index(active_comms);
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_get_parent)(void **) = address;
    mpi_return = (*VendorMPI_Comm_get_parent)(&local_a0[*parent].mpi_const);
    if (local_a0[*parent].mpi_const == local_a0[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*parent);
      *parent = MPI_COMM_NULL;
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_get_parent)(int *) = address;
    mpi_return = (*VendorMPI_Comm_get_parent)(&local_a0[*parent].mpi_const);
    if (local_a0[*parent].mpi_const == local_a0[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*parent);
      *parent = MPI_COMM_NULL;
    }
  }
  return mpi_return;
}
