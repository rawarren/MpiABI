
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_f2c
 */

#include <_mpi.h>

MPI_Win
MPI_Win_f2c (MPI_Fint win)
{
#if 1
  return (MPI_Win) win;
#else
    static void *address=0;
    MPI_Win mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_f2c")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_f2c",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    MPI_Win (*VendorMPI_Win_f2c) (MPI_Fint win) = address;
    mpi_return = (*VendorMPI_Win_f2c)(win);
    return mpi_return;
#endif
}
