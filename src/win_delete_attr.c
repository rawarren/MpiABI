
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_delete_attr
 */

#include <_mpi.h>

int
MPI_Win_delete_attr (MPI_Win win, int win_keyval)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_delete_attr")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_delete_attr",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_delete_attr)(void *, int win_keyval) = address;
     mpi_return = (*VendorMPI_Win_delete_attr)(local_a0[win].mpi_const,win_keyval);
    } else { api_use_ints *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_delete_attr)(int, int win_keyval) = address;
     mpi_return = (*VendorMPI_Win_delete_attr)(local_a0[win].mpi_const,win_keyval);
   }
    return mpi_return;
}
