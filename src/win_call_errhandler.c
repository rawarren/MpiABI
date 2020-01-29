
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_call_errhandler
 */

#include <_mpi.h>

int
MPI_Win_call_errhandler (MPI_Win win, int errorcode)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_call_errhandler")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_call_errhandler",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_call_errhandler)(void *, int errorcode) = address;
     mpi_return = (*VendorMPI_Win_call_errhandler)(local_a0[win].mpi_const,errorcode);
    } else { api_use_ints *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_call_errhandler)(int, int errorcode) = address;
     mpi_return = (*VendorMPI_Win_call_errhandler)(local_a0[win].mpi_const,errorcode);
   }
    return mpi_return;
}
