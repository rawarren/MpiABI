
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Status_c2f
 */

#include <_mpi.h>

int
MPI_Status_c2f (MPI_Status *c_status, MPI_Fint *f_status)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Status_c2f")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Status_c2f",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    int (*VendorMPI_Status_c2f) (void *c_status, int *f_status) = address;
    isc_status_to_native(1, (int *)c_status, c_status->reserved);
    mpi_return = (*VendorMPI_Status_c2f)(&c_status->reserved,f_status);
    return mpi_return;
}
