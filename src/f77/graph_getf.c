
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graph_get
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GRAPH_GET() __attribute__ ((weak, alias("iscf_graph_get")));
void mpi_graph_get() __attribute__ ((weak, alias("iscf_graph_get")));
void mpi_graph_get_() __attribute__ ((weak, alias("iscf_graph_get")));
void mpi_graph_get__() __attribute__ ((weak, alias("iscf_graph_get")));
#endif

void iscf_graph_get(int *comm, int *maxindex, int *maxedges, int *index, int *edges, int *ierr)
{
    *ierr = MPI_Graph_get (*comm, *maxindex, *maxedges, index, edges);
}
