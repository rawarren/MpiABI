
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Neighbor_alltoallw
 */

#include <_mpi.h>
#include <stdlib.h>


int
MPI_Neighbor_alltoallw (void *sendbuf, int sendcounts[], MPI_Aint sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], MPI_Aint rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm)
{
    static void *address=0;
    int mpi_return;
    int i, csize;
    int nnodes;
    int comm_neighbor_size = 0;
    int neighbor_size;
    int topo_type = 0;
    int indegree = 0, outdegree = 0, weighted = 0;
    int rsize=0, ssize=0;


    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Neighbor_alltoallw")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Neighbor_alltoallw",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    MPI_Comm_size(comm,&csize);
    if (MPI_Topo_test(comm,&topo_type) != MPI_SUCCESS) {
	puts("MPI_Topo_test returned an ERROR!");
	fflush(stdout);
    }
    if (topo_type == MPI_GRAPH) {
	if (MPI_Graphdims_get(comm, &nnodes, &comm_neighbor_size) != MPI_SUCCESS) {
	    puts("MPI_Graphdims_get returned an ERROR!");
	    fflush(stdout);
	} else {
	    neighbor_size = comm_neighbor_size;
	}
    }
    else if (topo_type == MPI_CART) {
	if (MPI_Cartdim_get(comm, &comm_neighbor_size) != MPI_SUCCESS) {
	    puts("MPI_Cartdims_get returned an ERROR!");
	    fflush(stdout);
	}
	else {
	    neighbor_size = comm_neighbor_size;
	}
    }
    else if (topo_type == MPI_DIST_GRAPH) {
	if (MPI_Dist_graph_neighbors_count(comm, &indegree, &outdegree, &weighted) != MPI_SUCCESS) {
	    puts("MPI_Dist_graph_neighbors_countt returned an ERROR!");
	    fflush(stdout);
	}
	else {
	    neighbor_size = indegree;
	}
    }

    while((sendcounts[neighbor_size] > 0) &&
	  (sendtypes[neighbor_size] > 0) &&
	  (sendtypes[neighbor_size] < active_datatypes->how_many))
	neighbor_size++;

    if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
       void *stemp[64],*rtemp[64];
       void **sfill, **rfill;
       api_use_ptrs *local_a1= active_datatypes->api_declared;
       api_use_ptrs *local_a2= active_comms->api_declared;
       if (neighbor_size > 64) {
	   sfill = (void **)calloc(neighbor_size,sizeof(void *));
	   rfill = (void **)calloc(neighbor_size,sizeof(void *));
       }
       else {
	   sfill = stemp;
	   rfill = rtemp;
       }
       for(i=0; i<neighbor_size; i++) {
	   if ((sendcounts[i] == 0) || (sendtypes[i] > active_datatypes->how_many)) {
	       sfill[i] = local_a0[0].mpi_const;
	       sendcounts[i] = 0;
	   }
	   else sfill[i] = local_a0[sendtypes[i]].mpi_const;
       }

       neighbor_size = comm_neighbor_size;;
       while((recvcounts[neighbor_size] > 0) &&
	     (recvtypes[neighbor_size] > 0) &&
	     (recvtypes[neighbor_size] < active_datatypes->how_many))
	   neighbor_size++;

       for(i=0; i<neighbor_size; i++) {
	   if ((recvcounts[i] == 0) || (recvtypes[i] > active_datatypes->how_many)) {
	       rfill[i] = local_a1[0].mpi_const;
	       recvcounts[i] = 0;
	   }
	   else rfill[i] = local_a1[recvtypes[i]].mpi_const;
       }
       int (*VendorMPI_Neighbor_alltoallw)(void *sendbuf,int sendcounts[],MPI_Aint sdispls[],void **,void *recvbuf,int recvcounts[],MPI_Aint rdispls[],void **,void *) = address;
       mpi_return = (*VendorMPI_Neighbor_alltoallw)(INPLACE(sendbuf),sendcounts,sdispls,&sfill[0],INPLACE(recvbuf),recvcounts,rdispls,&rfill[0],local_a2[comm].mpi_const);
       if (sfill != stemp) {
	   free(sfill);
	   free(rfill);
       }
    } else { api_use_ints *local_a0 = active_datatypes->api_declared;
       int stemp[64], rtemp[64];
       int *sfill, *rfill;
       api_use_ints *local_a1= active_datatypes->api_declared;
       api_use_ints *local_a2= active_comms->api_declared;
       if (neighbor_size > 64) {
	   sfill = (int *)calloc(neighbor_size,sizeof(int));
	   rfill = (int *)calloc(neighbor_size,sizeof(int));
       }
       else {
	   sfill = stemp;
	   rfill = rtemp;
       }
       for(i=0; i<neighbor_size; i++) {
	   if ((sendcounts[i] == 0) || (sendtypes[i] > active_datatypes->how_many)) {
	       sfill[i] = local_a0[0].mpi_const;
	       sendcounts[i] = 0;
	   }
	   else sfill[i] = local_a0[sendtypes[i]].mpi_const;
       }

       neighbor_size = comm_neighbor_size;
       while((recvcounts[neighbor_size] > 0) &&
	     (recvtypes[neighbor_size] > 0) &&
	     (recvtypes[neighbor_size] < active_datatypes->how_many))
	   neighbor_size++;

       for(i=0; i<neighbor_size; i++) {
	   if ((recvcounts[i] == 0) || (recvtypes[i] > active_datatypes->how_many)) {
	       rfill[i] = local_a1[0].mpi_const;
	       recvcounts[i] = 0;
	   }
	   else rfill[i] = local_a1[recvtypes[i]].mpi_const;
       }

       int (*VendorMPI_Neighbor_alltoallw)(void *sendbuf,int sendcounts[],MPI_Aint sdispls[],int *,void *recvbuf,int recvcounts[],MPI_Aint rdispls[], int *,int) = address;
       mpi_return = (*VendorMPI_Neighbor_alltoallw)(INPLACE(sendbuf),sendcounts,sdispls,&sfill[0],INPLACE(recvbuf),recvcounts,rdispls,&rfill[0],local_a2[comm].mpi_const);
       if (sfill != stemp) {
	   free(sfill);
	   free(rfill);
       }
    }
    return mpi_return;
}
