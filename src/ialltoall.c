
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Ialltoall
 */

#include <_mpi.h>

int
MPI_Ialltoall (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Ialltoall")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Ialltoall",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *request = new_index(active_requests);

  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
      int (*VendorMPI_Ialltoall)(void *sendbuf,int sendcount,void *,void *recvbuf,int recvcount,void *,void *, void **) = address;
      mpi_return = (*VendorMPI_Ialltoall)(INPLACE(sendbuf),sendcount,local_a0[sendtype].mpi_const,INPLACE(recvbuf),recvcount,local_a1[recvtype].mpi_const,local_a2[comm].mpi_const,&local_a3[*request].mpi_const);
    }
    else { api_use_ints *local_a3=active_requests->api_declared;
      int (*VendorMPI_Ialltoall)(void *sendbuf,int sendcount,void *,void *recvbuf,int recvcount,void *,void *, int *) = address;
      mpi_return = (*VendorMPI_Ialltoall)(INPLACE(sendbuf),sendcount,local_a0[sendtype].mpi_const,INPLACE(recvbuf),recvcount,local_a1[recvtype].mpi_const,local_a2[comm].mpi_const,&local_a3[*request].mpi_const);
    }
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;      
      int (*VendorMPI_Ialltoall)(void *sendbuf,int sendcount,int,void *recvbuf,int recvcount,int,int, void **) = address;
      mpi_return = (*VendorMPI_Ialltoall)(INPLACE(sendbuf),sendcount,local_a0[sendtype].mpi_const,INPLACE(recvbuf),recvcount,local_a1[recvtype].mpi_const,local_a2[comm].mpi_const,&local_a3[*request].mpi_const);
    }
    else { api_use_ints *local_a3=active_requests->api_declared;
      int (*VendorMPI_Ialltoall)(void *sendbuf,int sendcount,int,void *recvbuf,int recvcount,int,int, int *) = address;
      mpi_return = (*VendorMPI_Ialltoall)(INPLACE(sendbuf),sendcount,local_a0[sendtype].mpi_const,INPLACE(recvbuf),recvcount,local_a1[recvtype].mpi_const,local_a2[comm].mpi_const,&local_a3[*request].mpi_const);
    }
  }
  return mpi_return;
}
