
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Recv
 */

#include <_mpi.h>

int
MPI_Recv (void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)
{
  static void *address=0;
  int mpi_return;
  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Recv")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Recv",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (active_comms->use_ptrs) {
    api_use_ptrs *local_a0= active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;

    int (*VendorMPI_Recv)(void *buf,int count,void *,int source,int tag,void *, MPI_Status *status) = address;
    mpi_return = (*VendorMPI_Recv)(BOTTOM(buf),count,local_a0[datatype].mpi_const,ANYSRC(source),ANYTAG(tag),local_a1[comm].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,status->reserved,(int *)status);
  } else {
    api_use_ints *local_a0= active_datatypes->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;

    int (*VendorMPI_Recv)(void *buf,int count,int,int source,int tag,int, MPI_Status *status) = address;
    mpi_return = (*VendorMPI_Recv)(BOTTOM(buf),count,local_a0[datatype].mpi_const,ANYSRC(source),ANYTAG(tag),local_a1[comm].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,status->reserved,(int *)status);
  }
  return mpi_return;
}
