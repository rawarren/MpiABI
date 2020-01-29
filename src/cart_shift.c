
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_shift
 */

#include <_mpi.h>

int
MPI_Cart_shift (MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Cart_shift")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Cart_shift",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Cart_shift)(void *,int direction,int disp,int *rank_source, int *rank_dest) = address;
    mpi_return = (*VendorMPI_Cart_shift)(local_a0[comm].mpi_const,direction,disp,rank_source,rank_dest);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Cart_shift)(int,int direction,int disp,int *rank_source, int *rank_dest) = address;
    mpi_return = (*VendorMPI_Cart_shift)(local_a0[comm].mpi_const,direction,disp,rank_source,rank_dest);
  }
  return mpi_return;
}
