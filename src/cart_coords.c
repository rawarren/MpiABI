
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_coords
 */

#include <_mpi.h>

int
MPI_Cart_coords (MPI_Comm comm, int rank, int maxdims, int *coords)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Cart_coords")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Cart_coords",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Cart_coords)(void *,int rank,int maxdims, int *coords) = address;
    mpi_return = (*VendorMPI_Cart_coords)(local_a0[comm].mpi_const,rank,maxdims,coords);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Cart_coords)(int,int rank,int maxdims, int *coords) = address;
    mpi_return = (*VendorMPI_Cart_coords)(local_a0[comm].mpi_const,rank,maxdims,coords);
  }
  return mpi_return;
}
