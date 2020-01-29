
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Test_cancelled
 */

#include <_mpi.h>

int
MPI_Test_cancelled (MPI_Status *status, int *flag)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Test_cancelled")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Test_cancelled",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    int (*VendorMPI_Test_cancelled) (int *status, int *flag) = address;
    mpi_return = (*VendorMPI_Test_cancelled)(status->reserved,flag);
    return mpi_return;
}
