
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Dist_graph_neighbors
 */

#include <_mpi.h>

int
MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int *sources, int *sourceweights, int maxoutdegree, int *destinations, int *destweights)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Dist_graph_neighbors")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Dist_graph_neighbors",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
      int (*VendorMPI_Dist_graph_neighbors)(void *,int,int *,int *,int,int *,int *) = address;
      mpi_return = (*VendorMPI_Dist_graph_neighbors)(local_a0[comm].mpi_const,maxindegree,sources,UNWEIGHTED(sourceweights),maxoutdegree,destinations,UNWEIGHTED(destweights));
  } else { api_use_ints *local_a0= active_comms->api_declared;
      int (*VendorMPI_Dist_graph_neighbors)(int,int,int *,int *,int,int *,int *) = address;  
      mpi_return = (*VendorMPI_Dist_graph_neighbors)(local_a0[comm].mpi_const,maxindegree,sources,UNWEIGHTED(sourceweights),maxoutdegree,destinations,UNWEIGHTED(destweights));
  }
  return mpi_return;
}
