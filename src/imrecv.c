
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Irecv
 */

#include <_mpi.h>

int
MPI_Imrecv (void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request)
{
  static void *address=0;
  int mpi_return = MPI_SUCCESS;
  int msg = 0;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Imrecv")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Imrecv",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (message) {
    int msgIndex = *message;
    *request = new_index(active_requests);
    if (msgIndex == MPI_MESSAGE_NULL) 
      msg = ISC_MESSAGE_NULL_;
    else if (msgIndex == MPI_MESSAGE_NO_PROC)
      msg = ISC_MESSAGE_NO_PROC_;
    else 
      msg = msgIndex;

    if (active_datatypes->use_ptrs) {
      api_use_ptrs *local_a0= active_datatypes->api_declared;
      api_use_ptrs *local_a1= active_msgs->api_declared;
      void *native_msg = local_a1[msg].mpi_const;

      if (active_requests->use_ptrs) { api_use_ptrs *local_a2=active_requests->api_declared;
	int (*VendorMPI_Imrecv)(void *buf,int count,void *, void **,void **) = address;
	mpi_return = (*VendorMPI_Imrecv)(BOTTOM(buf),count,local_a0[datatype].mpi_const,&native_msg,&local_a2[*request].mpi_const);
      } else { api_use_ints *local_a2=active_requests->api_declared;
	int (*VendorMPI_Imrecv)(void *buf,int count,void *, void **, int *) = address;
	mpi_return = (*VendorMPI_Imrecv)(BOTTOM(buf),count,local_a0[datatype].mpi_const,&native_msg,&local_a2[*request].mpi_const);
      }
    } else {
      api_use_ints *local_a0= active_datatypes->api_declared;
      api_use_ints *local_a1= active_msgs->api_declared;
      int native_msg = local_a1[msg].mpi_const;

      if (active_requests->use_ptrs) { api_use_ptrs *local_a2=active_requests->api_declared;
	int (*VendorMPI_Imrecv)(void *buf,int count, int, int *, void **) = address;
	mpi_return = (*VendorMPI_Imrecv)(BOTTOM(buf),count,local_a0[datatype].mpi_const,&native_msg,&local_a2[*request].mpi_const);
      } else { api_use_ints *local_a2=active_requests->api_declared;
	int (*VendorMPI_Imrecv)(void *buf,int count,int, int *,int *) = address;
	mpi_return = (*VendorMPI_Imrecv)(BOTTOM(buf),count,local_a0[datatype].mpi_const,&native_msg,&local_a2[*request].mpi_const);
      }
    }
    if (mpi_return == MPI_SUCCESS) 
      if (msgIndex > 0) 
	free_index(active_msgs, msg);
      *message = MPI_MESSAGE_NULL;
  }

  return mpi_return;
}
