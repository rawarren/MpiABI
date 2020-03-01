
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Topo_test
 */

#include <_mpi.h>

int
MPI_Topo_test (MPI_Comm comm, int *status)
{
    static void *address=0;
    int mpi_return;
    int vendor_status;
    api_use_ints *local_a1 = active_miscs->api_declared;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Topo_test")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Topo_test",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
     int (*VendorMPI_Topo_test)(void *, int *status) = address;
     mpi_return = (*VendorMPI_Topo_test)(local_a0[comm].mpi_const,&vendor_status);
    } else { api_use_ints *local_a0= active_comms->api_declared;
     int (*VendorMPI_Topo_test)(int, int *status) = address;
     mpi_return = (*VendorMPI_Topo_test)(local_a0[comm].mpi_const,&vendor_status);
    }

    if (vendor_status == local_a1[MPI_CART].mpi_const) *status = MPI_CART;
    else if (vendor_status == local_a1[MPI_GRAPH].mpi_const) *status = MPI_GRAPH;
    else if (vendor_status == local_a1[MPI_DIST_GRAPH].mpi_const) *status = MPI_DIST_GRAPH;
    else *status = MPI_UNDEFINED;

    return mpi_return;
}
