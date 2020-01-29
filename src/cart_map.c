
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_map
 */

#include <_mpi.h>

int
MPI_Cart_map (MPI_Comm comm, int ndims, int dims[], int periods[], int *newrank)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Cart_map")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Cart_map",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Cart_map)(void *,int ndims,int dims[],int periods[], int *newrank) = address;
    mpi_return = (*VendorMPI_Cart_map)(local_a0[comm].mpi_const,ndims,dims,periods,newrank);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Cart_map)(int,int ndims,int dims[],int periods[], int *newrank) = address;
    mpi_return = (*VendorMPI_Cart_map)(local_a0[comm].mpi_const,ndims,dims,periods,newrank);
  }
  return mpi_return;
}
