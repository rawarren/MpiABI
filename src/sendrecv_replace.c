
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Sendrecv_replace
 */

#include <_mpi.h>

int
MPI_Sendrecv_replace (void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status)
{
  static void *address=0;
  int mpi_return;
  int natstat[MAX_MPI_STATUS_SIZE] = {0,};

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Sendrecv_replace")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Sendrecv_replace",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (active_comms->use_ptrs) {
    api_use_ptrs *local_a0= active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;

    int (*VendorMPI_Sendrecv_replace)(void *,int count,void *,int dest,int sendtag,int source,int recvtag,void *, MPI_Status *status) = address;
    mpi_return = (*VendorMPI_Sendrecv_replace)(BOTTOM(buf),count,local_a0[datatype].mpi_const,dest,sendtag,source,recvtag,local_a1[comm].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,natstat,(int *)status);
  } else {
    api_use_ints *local_a0= active_datatypes->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;

    int (*VendorMPI_Sendrecv_replace)(void *, int count,int,int dest,int sendtag,int source,int recvtag,int, MPI_Status *status) = address;
    mpi_return = (*VendorMPI_Sendrecv_replace)(BOTTOM(buf),count,local_a0[datatype].mpi_const,dest,sendtag,source,recvtag,local_a1[comm].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,natstat,(int *)status);
  }
  return mpi_return;
}
