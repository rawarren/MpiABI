
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Wtick
 */

#include <_mpi.h>

double
MPI_Wtick (void)
{
    static void *address=0;
    double mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Wtick")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Wtick",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    double (*VendorMPI_Wtick) (void) = address;
    mpi_return = (*VendorMPI_Wtick)();
return mpi_return;
}
