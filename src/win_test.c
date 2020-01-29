
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_test
 */

#include <_mpi.h>

int
MPI_Win_test (MPI_Win win, int *flag)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_test")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_test",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_test)(void *, int *flag) = address;
     mpi_return = (*VendorMPI_Win_test)(local_a0[win].mpi_const,flag);
    } else { api_use_ints *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_test)(int, int *flag) = address;
     mpi_return = (*VendorMPI_Win_test)(local_a0[win].mpi_const,flag);
   }
    return mpi_return;
}
