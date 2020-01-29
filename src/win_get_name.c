
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_get_name
 */

#include <_mpi.h>

int
MPI_Win_get_name (MPI_Win win, char *win_name, int *resultlen)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_get_name")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_get_name",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_get_name)(void *,char *win_name, int *resultlen) = address;
     mpi_return = (*VendorMPI_Win_get_name)(local_a0[win].mpi_const,win_name,resultlen);
    } else { api_use_ints *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_get_name)(int,char *win_name, int *resultlen) = address;
     mpi_return = (*VendorMPI_Win_get_name)(local_a0[win].mpi_const,win_name,resultlen);
   }
    return mpi_return;
}
