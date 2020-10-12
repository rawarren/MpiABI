
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Pack_external
 */

#include <_mpi.h>

int
MPI_Pack_external (char *datarep, void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, MPI_Aint outsize, MPI_Aint *position)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
		if ((address = dlsym(MPI_libhandle,"MPI_Pack_external")) == NULL) {
			printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Pack_external",SYM_MISSING_TRAILER);
			return -1;
		}
    }

    if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
		int (*VendorMPI_Pack_external)(char *datarep,void *inbuf,int incount,void *,void *outbuf,MPI_Aint outsize, MPI_Aint *position) = address;
		mpi_return = (*VendorMPI_Pack_external)(datarep,inbuf,incount,local_a0[datatype].mpi_const,outbuf,outsize,position);
    } else { api_use_ints *local_a0 = active_datatypes->api_declared;
		int (*VendorMPI_Pack_external)(char *datarep,void *inbuf,int incount,int,void *outbuf,MPI_Aint outsize, MPI_Aint *position) = address;
		mpi_return = (*VendorMPI_Pack_external)(datarep,inbuf,incount,local_a0[datatype].mpi_const,outbuf,outsize,position);
	}
    return mpi_return;
}
