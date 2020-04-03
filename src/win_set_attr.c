
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_set_attr
 */

#include <_mpi.h>

int
MPI_Win_set_attr (MPI_Win win, int win_keyval, void *attribute_val)
{
    static void *address=0;
    int mpi_return;
    api_use_ints *local_a1 = active_miscs->api_declared;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_set_attr")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_set_attr",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_set_attr)(void *,int win_keyval, void *attribute_val) = address;
     mpi_return = (*VendorMPI_Win_set_attr)(local_a0[win].mpi_const,local_a1[win_keyval].mpi_const,attribute_val);
    } else { api_use_ints *local_a0=active_wins->api_declared;
     int (*VendorMPI_Win_set_attr)(int,int win_keyval, void *attribute_val) = address;
     mpi_return = (*VendorMPI_Win_set_attr)(local_a0[win].mpi_const,local_a1[win_keyval].mpi_const,attribute_val);
   }
    return mpi_return;
}
