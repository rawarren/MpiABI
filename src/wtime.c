
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Wtime
 */

#include <_mpi.h>

double
MPI_Wtime (void)
{
    static void *address=0;
    double mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Wtime")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Wtime",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    double (*VendorMPI_Wtime) (void) = address;
    mpi_return = (*VendorMPI_Wtime)();
return mpi_return;
}
