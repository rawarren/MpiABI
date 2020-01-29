
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_ub
 */

#include <_mpi.h>

int
MPI_Type_ub (MPI_Datatype mtype, MPI_Aint *ub)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Type_ub")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_ub",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
     int (*VendorMPI_Type_ub)(void *, MPI_Aint *ub) = address;
     mpi_return = (*VendorMPI_Type_ub)(local_a0[mtype].mpi_const,ub);
    } else { api_use_ints *local_a0 = active_datatypes->api_declared;
     int (*VendorMPI_Type_ub)(int, MPI_Aint *ub) = address;
     mpi_return = (*VendorMPI_Type_ub)(local_a0[mtype].mpi_const,ub);
   }
    return mpi_return;
}
