
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Reduce
 */

#include <_mpi.h>

int
MPI_Reduce_local (void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype, MPI_Op op)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Reduce_local")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Reduce_local",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1=active_ops->api_declared;
    int (*VendorMPI_Reduce_local)(void *inbuf,void *inoutbuf,int count,void *,void *) = address;
    mpi_return = (*VendorMPI_Reduce_local)(INPLACE(inbuf),INPLACE(inoutbuf),count,local_a0[datatype].mpi_const,local_a1[op].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1=active_ops->api_declared;
    int (*VendorMPI_Reduce_local)(void *inbuf,void *inoutbuf,int count,int,int) = address;
    mpi_return = (*VendorMPI_Reduce_local)(INPLACE(inbuf),INPLACE(inoutbuf),count,local_a0[datatype].mpi_const,local_a1[op].mpi_const);
  }
  return mpi_return;
}
