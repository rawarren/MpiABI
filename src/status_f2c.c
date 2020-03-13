
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Status_f2c
 */

#include <_mpi.h>

int
MPI_Status_f2c (MPI_Fint *f_status, MPI_Status *c_status)
{
    static void *address=0;
    int mpi_return;
    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Status_f2c")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Status_f2c",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    int (*VendorMPI_Status_f2c) (MPI_Fint *f_status, int *c_status) = address;
    mpi_return = (*VendorMPI_Status_f2c)(f_status,(int *)c_status->reserved);
    native_status_to_isc(1,c_status->reserved,(int *)c_status);
    return mpi_return;
}
