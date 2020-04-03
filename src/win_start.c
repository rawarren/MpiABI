
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_start
 */

#include <_mpi.h>

int
MPI_Win_start (MPI_Group group, int assert, MPI_Win win)
{
    static void *address=0;
    int mpi_return;
    api_use_ints *local_a2=active_winassertbitfield->api_declared;
    int native_assert = 0;

    if (assert > 0) {
	if (assert & ISC_MODE_NOCHECK) 
	    native_assert |= local_a2[ISC_MODE_NOCHECK_].mpi_const;
	if (assert & ISC_MODE_NOPRECEDE)
	    native_assert |= local_a2[ISC_MODE_NOPRECEDE_].mpi_const;
	if (assert & ISC_MODE_NOPUT)
	    native_assert |= local_a2[ISC_MODE_NOPUT_].mpi_const;
	if (assert & ISC_MODE_NOSTORE)
	    native_assert |= local_a2[ISC_MODE_NOSTORE_].mpi_const;
	if (assert & ISC_MODE_NOSUCCEED)
	    native_assert |= local_a2[ISC_MODE_NOSUCCEED_].mpi_const;
    }

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_start")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_start",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_groups->use_ptrs) { api_use_ptrs *local_a0=active_groups->api_declared;
        api_use_ptrs *local_a1=active_wins->api_declared;
        int (*VendorMPI_Win_start)(void *,int assert,void *) = address;
        mpi_return = (*VendorMPI_Win_start)(local_a0[group].mpi_const,native_assert,local_a1[win].mpi_const);
    } else { api_use_ints *local_a0=active_groups->api_declared;
        api_use_ints *local_a1=active_wins->api_declared;
        int (*VendorMPI_Win_start)(int,int assert,int) = address;
        mpi_return = (*VendorMPI_Win_start)(local_a0[group].mpi_const,native_assert,local_a1[win].mpi_const);
    }
    return mpi_return;
}
