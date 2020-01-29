
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graph_neighbors
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GRAPH_NEIGHBORS() __attribute__ ((weak, alias("iscf_graph_neighbors")));
void mpi_graph_neighbors() __attribute__ ((weak, alias("iscf_graph_neighbors")));
void mpi_graph_neighbors_() __attribute__ ((weak, alias("iscf_graph_neighbors")));
void mpi_graph_neighbors__() __attribute__ ((weak, alias("iscf_graph_neighbors")));
#endif

void iscf_graph_neighbors(int *comm, int *rank, int *maxneighbors, int *neighbors, int *ierr)
{
    *ierr = MPI_Graph_neighbors (*comm, *rank, *maxneighbors, neighbors);
}
