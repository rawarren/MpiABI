
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graph_map
 */

#include <_mpi.h>

int
MPI_Graph_map (MPI_Comm comm, int nnodes, int *index, int *edges, int *newrank)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Graph_map")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Graph_map",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Graph_map)(void *,int nnodes,int *index,int *edges, int *newrank) = address;
    mpi_return = (*VendorMPI_Graph_map)(local_a0[comm].mpi_const,nnodes,index,edges,newrank);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Graph_map)(int,int nnodes,int *index,int *edges, int *newrank) = address;
    mpi_return = (*VendorMPI_Graph_map)(local_a0[comm].mpi_const,nnodes,index,edges,newrank);
  }
  return mpi_return;
}
