
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Dist_graph_neighbors_count
 */

#include <_mpi.h>

int
MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree, int *weighted)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Dist_graph_neighbors_count")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Dist_graph_neighbors_count",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
      int (*VendorMPI_Dist_graph_neighbors_count)(void *,int *, int *, int *) = address;
      mpi_return = (*VendorMPI_Dist_graph_neighbors_count)(local_a0[comm].mpi_const,indegree,outdegree,UNWEIGHTED(weighted));
  } else { api_use_ints *local_a0= active_comms->api_declared;
      int (*VendorMPI_Dist_graph_neighbors_count)(int, int *, int *, int *) = address;
      mpi_return = (*VendorMPI_Dist_graph_neighbors_count)(local_a0[comm].mpi_const,indegree,outdegree,UNWEIGHTED(weighted));
  }
  return mpi_return;
}
