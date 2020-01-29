
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_compare
 */

#include <_mpi.h>

int
MPI_Comm_compare (MPI_Comm comm1, MPI_Comm comm2, int *result)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_compare")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_compare",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    int (*VendorMPI_Comm_compare)(void *,void *, int *result) = address;
    mpi_return = (*VendorMPI_Comm_compare)(local_a0[comm1].mpi_const,local_a1[comm2].mpi_const,result);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    int (*VendorMPI_Comm_compare)(int,int, int *result) = address;
    mpi_return = (*VendorMPI_Comm_compare)(local_a0[comm1].mpi_const,local_a1[comm2].mpi_const,result);
  }
  return mpi_return;
}
