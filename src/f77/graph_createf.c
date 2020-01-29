
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graph_create
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GRAPH_CREATE() __attribute__ ((weak, alias("iscf_graph_create")));
void mpi_graph_create() __attribute__ ((weak, alias("iscf_graph_create")));
void mpi_graph_create_() __attribute__ ((weak, alias("iscf_graph_create")));
void mpi_graph_create__() __attribute__ ((weak, alias("iscf_graph_create")));
#endif

void iscf_graph_create(int *comm_old, int *nnodes, int *index, int *edges, int *reorder, int *comm_graph, int *ierr)
{
    *ierr = MPI_Graph_create (*comm_old, *nnodes, index, edges, *reorder, comm_graph);
}
