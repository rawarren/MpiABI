
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Scan
 */

#include <_mpi.h>

int
MPI_Iscan (void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Iscan")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Iscan",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *request = new_index(active_requests);

  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1=active_ops->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
	int (*VendorMPI_Iscan)(void *sendbuf,void *recvbuf,int count,void *,void *,void *, void **) = address;
	mpi_return = (*VendorMPI_Iscan)(INPLACE(sendbuf),INPLACE(recvbuf),count,local_a0[datatype].mpi_const,local_a1[op].mpi_const,local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
    }
    else { api_use_ints *local_a3=active_requests->api_declared;
	int (*VendorMPI_Iscan)(void *sendbuf,void *recvbuf,int count,void *,void *,void *, void *) = address;
	mpi_return = (*VendorMPI_Iscan)(INPLACE(sendbuf),INPLACE(recvbuf),count,local_a0[datatype].mpi_const,local_a1[op].mpi_const,local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
    }
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1=active_ops->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
	int (*VendorMPI_Iscan)(void *sendbuf,void *recvbuf,int count,int,int,int, void **) = address;
	mpi_return = (*VendorMPI_Iscan)(INPLACE(sendbuf),INPLACE(recvbuf),count,local_a0[datatype].mpi_const,local_a1[op].mpi_const,local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
    }
    else { api_use_ints *local_a3=active_requests->api_declared;
	int (*VendorMPI_Iscan)(void *sendbuf,void *recvbuf,int count,int,int,int, void *) = address;
	mpi_return = (*VendorMPI_Iscan)(INPLACE(sendbuf),INPLACE(recvbuf),count,local_a0[datatype].mpi_const,local_a1[op].mpi_const,local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
    }
  }
  return mpi_return;
}
