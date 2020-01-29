
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Pack
 */

#include <_mpi.h>

int
MPI_Pack (void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Pack")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Pack",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    int (*VendorMPI_Pack)(void *inbuf,int incount,void *,void *outbuf,int outsize,int *position,void *) = address;
    mpi_return = (*VendorMPI_Pack)(INPLACE(inbuf),incount,local_a0[datatype].mpi_const,INPLACE(outbuf),outsize,position,local_a1[comm].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    int (*VendorMPI_Pack)(void *inbuf,int incount,int,void *outbuf,int outsize,int *position,int) = address;
    mpi_return = (*VendorMPI_Pack)(INPLACE(inbuf),incount,local_a0[datatype].mpi_const,INPLACE(outbuf),outsize,position,local_a1[comm].mpi_const);
  }
  return mpi_return;
}
