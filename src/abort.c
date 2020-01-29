
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Abort
 */

#include <_mpi.h>

int
MPI_Abort (MPI_Comm comm, int errorcode)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Abort")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Abort",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
     int (*VendorMPI_Abort)(void *, int errorcode) = address;
     mpi_return = (*VendorMPI_Abort)(local_a0[comm].mpi_const,errorcode);
    } else { api_use_ints *local_a0= active_comms->api_declared;
     int (*VendorMPI_Abort)(int, int errorcode) = address;
     mpi_return = (*VendorMPI_Abort)(local_a0[comm].mpi_const,errorcode);
   }
    return mpi_return;
}
