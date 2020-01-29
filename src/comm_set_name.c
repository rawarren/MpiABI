
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_set_name
 */

#include <_mpi.h>

int
MPI_Comm_set_name (MPI_Comm comm, char *comm_name)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_set_name")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_set_name",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_set_name)(void *, char *comm_name) = address;
    mpi_return = (*VendorMPI_Comm_set_name)(local_a0[comm].mpi_const,comm_name);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_set_name)(int, char *comm_name) = address;
    mpi_return = (*VendorMPI_Comm_set_name)(local_a0[comm].mpi_const,comm_name);
  }
  return mpi_return;
}
