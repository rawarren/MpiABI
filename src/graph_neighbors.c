
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graph_neighbors
 */

#include <_mpi.h>

int
MPI_Graph_neighbors (MPI_Comm comm, int rank, int maxneighbors, int *neighbors)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Graph_neighbors")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Graph_neighbors",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Graph_neighbors)(void *,int rank,int maxneighbors, int *neighbors) = address;
    mpi_return = (*VendorMPI_Graph_neighbors)(local_a0[comm].mpi_const,rank,maxneighbors,neighbors);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Graph_neighbors)(int,int rank,int maxneighbors, int *neighbors) = address;
    mpi_return = (*VendorMPI_Graph_neighbors)(local_a0[comm].mpi_const,rank,maxneighbors,neighbors);
  }
  return mpi_return;
}
