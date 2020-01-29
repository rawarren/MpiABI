
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Status_set_cancelled
 */

#include <_mpi.h>

int
MPI_Status_set_cancelled (MPI_Status *status, int flag)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Status_set_cancelled")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Status_set_cancelled",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    int (*VendorMPI_Status_set_cancelled) (int *status, int flag) = address;
    mpi_return = (*VendorMPI_Status_set_cancelled)(status->reserved,flag);
    return mpi_return;
}
