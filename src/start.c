
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Start
 */

#include <_mpi.h>

int
MPI_Start (MPI_Request *request)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Start")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Start",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
     int (*VendorMPI_Start)(void **) = address;
     mpi_return = (*VendorMPI_Start)(&local_a0[*request].mpi_const);
    } else { api_use_ints *local_a0=active_requests->api_declared;
     int (*VendorMPI_Start)(int *) = address;
     mpi_return = (*VendorMPI_Start)(&local_a0[*request].mpi_const);
   }
    return mpi_return;
}
