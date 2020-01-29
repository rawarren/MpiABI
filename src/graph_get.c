
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graph_get
 */

#include <_mpi.h>

int
MPI_Graph_get (MPI_Comm comm, int maxindex, int maxedges, int *index, int *edges)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Graph_get")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Graph_get",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Graph_get)(void *,int maxindex,int maxedges,int *index, int *edges) = address;
    mpi_return = (*VendorMPI_Graph_get)(local_a0[comm].mpi_const,maxindex,maxedges,index,edges);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Graph_get)(int,int maxindex,int maxedges,int *index, int *edges) = address;
    mpi_return = (*VendorMPI_Graph_get)(local_a0[comm].mpi_const,maxindex,maxedges,index,edges);
  }
  return mpi_return;
}
