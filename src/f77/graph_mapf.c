
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graph_map
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GRAPH_MAP() __attribute__ ((weak, alias("iscf_graph_map")));
void mpi_graph_map() __attribute__ ((weak, alias("iscf_graph_map")));
void mpi_graph_map_() __attribute__ ((weak, alias("iscf_graph_map")));
void mpi_graph_map__() __attribute__ ((weak, alias("iscf_graph_map")));
#endif

void iscf_graph_map(int *comm, int *nnodes, int *index, int *edges, int *newrank, int *ierr)
{
    *ierr = MPI_Graph_map (*comm, *nnodes, index, edges, newrank);
}
