
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_c2f
 */

#include <_mpi.h>

MPI_Fint
MPI_Win_c2f (MPI_Win win)
{
#if 1
  return (MPI_Fint) win;
#else
    static void *address=0;
    MPI_Fint mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_c2f")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_c2f",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
     MPI_Fint (*VendorMPI_Win_c2f)(void *) = address;
     mpi_return = (*VendorMPI_Win_c2f)(local_a0[win].mpi_const);
    } else { api_use_ints *local_a0=active_wins->api_declared;
     MPI_Fint (*VendorMPI_Win_c2f)(int) = address;
     mpi_return = (*VendorMPI_Win_c2f)(local_a0[win].mpi_const);
   }
    return mpi_return;
#endif
}
