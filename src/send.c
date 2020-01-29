
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Send
 */

#include <_mpi.h>

int
MPI_Send (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
  static void *address=0;
  api_use_ints *local_a2= active_miscs->api_declared;
  int native_dest = dest;
  int mpi_return;
  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Send")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Send",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (dest == ISC_PROC_NULL) native_dest = local_a2[ISC_PROC_NULL_].mpi_const;

  if (active_comms->use_ptrs) {
    api_use_ptrs *local_a0= active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;

    int (*VendorMPI_Send)(void *buf,int count,void *,int dest,int tag,void *) = address;
    mpi_return = (*VendorMPI_Send)(BOTTOM(buf),count,local_a0[datatype].mpi_const,native_dest,tag,local_a1[comm].mpi_const);
  } else {
    api_use_ints *local_a0= active_datatypes->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;

    int (*VendorMPI_Send)(void *buf,int count,int,int dest,int tag,int) = address;
    mpi_return = (*VendorMPI_Send)(BOTTOM(buf),count,local_a0[datatype].mpi_const,native_dest,tag,local_a1[comm].mpi_const);
  }
  return mpi_return;
}
