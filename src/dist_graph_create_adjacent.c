
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Graph_create
 */

#include <_mpi.h>

int
MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, int sources[],
			       int sourceweights[], int outdegree,
			       int destinations[], int destweights[],
			       MPI_Info info, int reorder, MPI_Comm *comm_dist_graph)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Dist_graph_create_adjacent")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Dist_graph_create_adjacent",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    *comm_dist_graph = new_index(active_comms);
    if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
	api_use_ptrs *local_a1= active_comms->api_declared;
	if (active_infos->use_ptrs) { api_use_ptrs *local_a2=active_infos->api_declared;
	    int (*VendorMPI_Dist_graph_create_adjacent)(void *, int, int *, int *, int, int *, int *, void *, int, void **) = address;
	    mpi_return = (*VendorMPI_Dist_graph_create_adjacent)(local_a0[comm_old].mpi_const,indegree,sources,sourceweights,outdegree,
				       destinations,destweights,local_a2[info].mpi_const,reorder,&local_a1[*comm_dist_graph].mpi_const);
	}
	else {
	    api_use_ints *local_a2=active_infos->api_declared;
	    int (*VendorMPI_Dist_graph_create_adjacent)(void *, int, int *, int *, int, int *, int *, int, int, void **) = address;
	    mpi_return = (*VendorMPI_Dist_graph_create_adjacent)(local_a0[comm_old].mpi_const,indegree,sources,sourceweights,outdegree,
				       destinations,destweights,local_a2[info].mpi_const,reorder,&local_a1[*comm_dist_graph].mpi_const);
	}
    } else { api_use_ints *local_a0= active_comms->api_declared;
	api_use_ints *local_a1= active_comms->api_declared;
	if (active_infos->use_ptrs) { api_use_ptrs *local_a2=active_infos->api_declared;
	    int (*VendorMPI_Dist_graph_create_adjacent)(int, int, int *, int *, int, int *, int *, void *, int, int *) = address;
	    mpi_return = (*VendorMPI_Dist_graph_create_adjacent)(local_a0[comm_old].mpi_const,indegree,sources,sourceweights,outdegree,
				       destinations,destweights,local_a2[info].mpi_const,reorder,&local_a1[*comm_dist_graph].mpi_const);
	}
	else {
	    api_use_ints *local_a2=active_infos->api_declared;
	    int (*VendorMPI_Dist_graph_create_adjacent)(int, int, int *, int *, int, int *, int *, int, int, int*) = address;
	    mpi_return = (*VendorMPI_Dist_graph_create_adjacent)(local_a0[comm_old].mpi_const,indegree,sources,sourceweights,outdegree,
				       destinations,destweights,local_a2[info].mpi_const,reorder,&local_a1[*comm_dist_graph].mpi_const);
	}
    }
    return mpi_return;
}
