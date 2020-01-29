
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Unpack_external
 */

#include <_mpi.h>

int
MPI_Unpack_external  (char *datarep, void *inbuf, MPI_Aint insize, MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Unpack_external")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Unpack_external",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
     int (*VendorMPI_Unpack_external)(char *datarep,void *inbuf,MPI_Aint insize,MPI_Aint *position,void *outbuf,int outcount,void *) = address;
     mpi_return = (*VendorMPI_Unpack_external)(datarep,inbuf,insize,position,outbuf,outcount,local_a0[datatype].mpi_const);
    } else { api_use_ints *local_a0 = active_datatypes->api_declared;
     int (*VendorMPI_Unpack_external)(char *datarep,void *inbuf,MPI_Aint insize,MPI_Aint *position,void *outbuf,int outcount,int) = address;
     mpi_return = (*VendorMPI_Unpack_external)(datarep,inbuf,insize,position,outbuf,outcount,local_a0[datatype].mpi_const);
   }
    return mpi_return;
}
