
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graph_create
 */

#include <_mpi.h>

int
MPI_Graph_create (MPI_Comm comm_old, int nnodes, int *index, int *edges, int reorder, MPI_Comm *comm_graph)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Graph_create")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Graph_create",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  *comm_graph = new_index(active_comms);
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    int (*VendorMPI_Graph_create)(void *,int nnodes,int *index,int *edges,int reorder,void **) = address;
    mpi_return = (*VendorMPI_Graph_create)(local_a0[comm_old].mpi_const,nnodes,index,edges,reorder,&local_a1[*comm_graph].mpi_const);
    if (local_a1[*comm_graph].mpi_const == local_a1[ISC_COMM_NULL].mpi_const) {
      free_index(active_comms,*comm_graph);
      *comm_graph = MPI_COMM_NULL;
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    int (*VendorMPI_Graph_create)(int,int nnodes,int *index,int *edges,int reorder,int *) = address;
    mpi_return = (*VendorMPI_Graph_create)(local_a0[comm_old].mpi_const,nnodes,index,edges,reorder,&local_a1[*comm_graph].mpi_const);
    if (local_a1[*comm_graph].mpi_const == local_a1[ISC_COMM_NULL].mpi_const) {
      free_index(active_comms,*comm_graph);
      *comm_graph = MPI_COMM_NULL;
    }
  }
  return mpi_return;
}
