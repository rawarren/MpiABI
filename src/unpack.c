
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Unpack
 */

#include <_mpi.h>

int
MPI_Unpack (void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Unpack")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Unpack",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
       api_use_ptrs *local_a1= active_comms->api_declared;
        int (*VendorMPI_Unpack)(void *inbuf,int insize,int *position,void *outbuf,int outcount,void *,void *) = address;
        mpi_return = (*VendorMPI_Unpack)(inbuf,insize,position,outbuf,outcount,local_a0[datatype].mpi_const,local_a1[comm].mpi_const);
       } else { api_use_ints *local_a0 = active_datatypes->api_declared;
       api_use_ints *local_a1= active_comms->api_declared;
        int (*VendorMPI_Unpack)(void *inbuf,int insize,int *position,void *outbuf,int outcount,int,int) = address;
        mpi_return = (*VendorMPI_Unpack)(inbuf,insize,position,outbuf,outcount,local_a0[datatype].mpi_const,local_a1[comm].mpi_const);
      }
    return mpi_return;
}
