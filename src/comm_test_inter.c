
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_test_inter
 */

#include <_mpi.h>

int
MPI_Comm_test_inter (MPI_Comm comm, int *flag)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_test_inter")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_test_inter",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_test_inter)(void *, int *flag) = address;
    mpi_return = (*VendorMPI_Comm_test_inter)(local_a0[comm].mpi_const,flag);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Comm_test_inter)(int, int *flag) = address;
    mpi_return = (*VendorMPI_Comm_test_inter)(local_a0[comm].mpi_const,flag);
  }
  return mpi_return;
}
