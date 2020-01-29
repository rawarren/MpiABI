
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Irsend
 */

#include <_mpi.h>

int
MPI_Irsend (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
  static void *address=0;
  int mpi_return;
  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Irsend")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Irsend",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  *request = new_index(active_requests);
  if (active_datatypes->use_ptrs) {
    api_use_ptrs *local_a0= active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;

    if (active_requests->use_ptrs) { api_use_ptrs *local_a2=active_requests->api_declared;
      int (*VendorMPI_Irsend)(void *buf,int count,void *,int dest,int tag,void *,void **) = address;
      mpi_return = (*VendorMPI_Irsend)(BOTTOM(buf),count,local_a0[datatype].mpi_const,dest,tag,local_a1[comm].mpi_const,&local_a2[*request].mpi_const);
    } else { api_use_ints *local_a2=active_requests->api_declared;
      int (*VendorMPI_Irsend)(void *buf,int count,void *,int dest,int tag,void *,int *) = address;
      mpi_return = (*VendorMPI_Irsend)(BOTTOM(buf),count,local_a0[datatype].mpi_const,dest,tag,local_a1[comm].mpi_const,&local_a2[*request].mpi_const);
    }
  } else {
    api_use_ints *local_a0= active_datatypes->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;

    if (active_requests->use_ptrs) { api_use_ptrs *local_a2=active_requests->api_declared;
      int (*VendorMPI_Irsend)(void *buf,int count,int,int dest,int tag,int,void **) = address;
      mpi_return = (*VendorMPI_Irsend)(BOTTOM(buf),count,local_a0[datatype].mpi_const,dest,tag,local_a1[comm].mpi_const,&local_a2[*request].mpi_const);
    } else { api_use_ints *local_a2=active_requests->api_declared;
      int (*VendorMPI_Irsend)(void *buf,int count,int,int dest,int tag,int,int *) = address;
      mpi_return = (*VendorMPI_Irsend)(BOTTOM(buf),count,local_a0[datatype].mpi_const,dest,tag,local_a1[comm].mpi_const,&local_a2[*request].mpi_const);
    }
  }
  return mpi_return;
}
