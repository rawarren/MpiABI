
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_get
 */

#include <_mpi.h>

int
MPI_Cart_get (MPI_Comm comm, int maxdims, int dims[], int periods[], int *coords)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Cart_get")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Cart_get",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Cart_get)(void *,int maxdims,int dims[],int periods[], int *coords) = address;
    mpi_return = (*VendorMPI_Cart_get)(local_a0[comm].mpi_const,maxdims,dims,periods,coords);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Cart_get)(int,int maxdims,int dims[],int periods[], int *coords) = address;
    mpi_return = (*VendorMPI_Cart_get)(local_a0[comm].mpi_const,maxdims,dims,periods,coords);
  }
  return mpi_return;
}
