
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_shared_query
 */

#include <_mpi.h>

int
MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint * size, int *disp_unit, void *baseptr)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_shared_query")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_shared_query",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
	int (*VendorMPI_Win_shared_query)(void *win,int rank, MPI_Aint *size,int *disp_unit,void *baseptr) = address;
	mpi_return = (*VendorMPI_Win_shared_query)(local_a0[win].mpi_const,rank,size,disp_unit,baseptr);
    } else { api_use_ints *local_a0=active_wins->api_declared;
	int (*VendorMPI_Win_shared_query)(int win,int rank, MPI_Aint *size,int *disp_unit,void *baseptr) = address;
	mpi_return = (*VendorMPI_Win_shared_query)(local_a0[win].mpi_const,rank,size,disp_unit,baseptr);
    }
    return mpi_return;
}
