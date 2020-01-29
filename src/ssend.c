
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Ssend
 */

#include <_mpi.h>

int
MPI_Ssend (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
  static void *address=0;
  int mpi_return;
  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Ssend")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Ssend",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (active_comms->use_ptrs) {
    api_use_ptrs *local_a0= active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;

    int (*VendorMPI_Ssend)(void *buf,int count,void *,int dest,int tag,void *) = address;
    mpi_return = (*VendorMPI_Ssend)(BOTTOM(buf),count,local_a0[datatype].mpi_const,dest,tag,local_a1[comm].mpi_const);
  } else {
    api_use_ints *local_a0= active_datatypes->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;

    int (*VendorMPI_Ssend)(void *buf,int count,int,int dest,int tag,int) = address;
    mpi_return = (*VendorMPI_Ssend)(BOTTOM(buf),count,local_a0[datatype].mpi_const,dest,tag,local_a1[comm].mpi_const);
  }
  return mpi_return;
}
