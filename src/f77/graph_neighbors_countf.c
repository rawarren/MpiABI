
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graph_neighbors_count
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GRAPH_NEIGHBORS_COUNT() __attribute__ ((weak, alias("iscf_graph_neighbors_count")));
void mpi_graph_neighbors_count() __attribute__ ((weak, alias("iscf_graph_neighbors_count")));
void mpi_graph_neighbors_count_() __attribute__ ((weak, alias("iscf_graph_neighbors_count")));
void mpi_graph_neighbors_count__() __attribute__ ((weak, alias("iscf_graph_neighbors_count")));
#endif

void iscf_graph_neighbors_count(int *comm, int *rank, int *nneighbors, int *ierr)
{
    *ierr = MPI_Graph_neighbors_count (*comm, *rank, nneighbors);
}
