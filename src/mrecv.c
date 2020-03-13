
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Mrecv
 */

#include <_mpi.h>

int
MPI_Mrecv (void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status)
{
  static void *address=0;

  int mpi_return = MPI_SUCCESS;
  int msg = 0;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Mrecv")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Mrecv",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (message) {
    int msgIndex = *message;
    if (msgIndex == MPI_MESSAGE_NULL) 
      msg = ISC_MESSAGE_NULL_;
    else if (msgIndex == MPI_MESSAGE_NO_PROC)
      msg = ISC_MESSAGE_NO_PROC_;
    else
      msg = msgIndex;

    if (active_msgs->use_ptrs) {
      api_use_ptrs *local_a0= active_datatypes->api_declared;
      api_use_ptrs *local_a1= active_msgs->api_declared;
      void *native_msg = local_a1[msg].mpi_const;
    
      int (*VendorMPI_Mrecv)(void *buf,int count,void *, void **, MPI_Status *status) = address;
      mpi_return = (*VendorMPI_Mrecv)(BOTTOM(buf),count,local_a0[datatype].mpi_const, &native_msg,SIGNORE(status));
      if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,status->reserved,(int *)status);
    } else {
      api_use_ints *local_a0= active_datatypes->api_declared;
      api_use_ints *local_a1= active_msgs->api_declared;
      int native_msg = local_a1[msg].mpi_const;

      int (*VendorMPI_Mrecv)(void *buf,int count, int, int *, MPI_Status *status) = address;
      mpi_return = (*VendorMPI_Mrecv)(BOTTOM(buf),count,local_a0[datatype].mpi_const,&native_msg,SIGNORE(status));
      if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,status->reserved,(int *)status);
    }

    /* On success, release the message handle */
    if (mpi_return == 0) {
      if (msgIndex > 0) 
	free_index(active_msgs, msg);
      *message = MPI_MESSAGE_NULL;
    }
  }

  return mpi_return;
}
