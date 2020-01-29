
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Pack_size
 */

#include <_mpi.h>

int
MPI_Pack_size (int incount, MPI_Datatype datatype, MPI_Comm comm, int *size)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Pack_size")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Pack_size",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    int (*VendorMPI_Pack_size)(int incount,void *,void *, int *size) = address;
    mpi_return = (*VendorMPI_Pack_size)(incount,local_a0[datatype].mpi_const,local_a1[comm].mpi_const,size);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    int (*VendorMPI_Pack_size)(int incount,int,int, int *size) = address;
    mpi_return = (*VendorMPI_Pack_size)(incount,local_a0[datatype].mpi_const,local_a1[comm].mpi_const,size);
  }
  return mpi_return;
}
