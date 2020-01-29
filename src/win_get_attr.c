
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_get_attr
 */

#include <_mpi.h>

int
MPI_Win_get_attr (MPI_Win win, int win_keyval, void *attribute_val, int *flag)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_get_attr")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_get_attr",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_get_attr)(void *,int win_keyval,void *attribute_val, int *flag) = address;
     mpi_return = (*VendorMPI_Win_get_attr)(local_a0[win].mpi_const,win_keyval,attribute_val,flag);
    } else { api_use_ints *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_get_attr)(int,int win_keyval,void *attribute_val, int *flag) = address;
     mpi_return = (*VendorMPI_Win_get_attr)(local_a0[win].mpi_const,win_keyval,attribute_val,flag);
   }
    return mpi_return;
}
