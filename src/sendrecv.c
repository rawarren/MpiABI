
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Sendrecv
 */

#include <_mpi.h>

int
MPI_Sendrecv (void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm,  MPI_Status *status)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Sendrecv")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Sendrecv",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (active_comms->use_ptrs) {
    api_use_ptrs *local_a0= active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;

    int (*VendorMPI_Sendrecv)(void *sendbuf,int sendcount,void *,int dest,int sendtag,void *recvbuf,int recvcount,void *,int source,int recvtag,void *,  MPI_Status *status) = address;
    mpi_return = (*VendorMPI_Sendrecv)(BOTTOM(sendbuf),sendcount,local_a0[sendtype].mpi_const,dest,sendtag,BOTTOM(recvbuf),recvcount,local_a1[recvtype].mpi_const,ANYSRC(source),ANYTAG(recvtag),local_a2[comm].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) {
	if (mpi_return == 0)
	    native_status_to_isc_no_error(1,status->reserved, (int *)status);
	else native_status_to_isc(1,status->reserved,(int *)status);
    }
  } else {
    api_use_ints *local_a0= active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;

    int (*VendorMPI_Sendrecv)(void *sendbuf,int sendcount,int,int dest,int sendtag,void *recvbuf,int recvcount,int,int source,int recvtag,int,  MPI_Status *status) = address;
    mpi_return = (*VendorMPI_Sendrecv)(BOTTOM(sendbuf),sendcount,local_a0[sendtype].mpi_const,dest,sendtag,BOTTOM(recvbuf),recvcount,local_a1[recvtype].mpi_const,ANYSRC(source),ANYTAG(recvtag),local_a2[comm].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) {
	if (mpi_return == 0)
	    native_status_to_isc_no_error(1,status->reserved, (int *)status);
	else native_status_to_isc(1,status->reserved,(int *)status);
    }
  }
  return mpi_return;
}
