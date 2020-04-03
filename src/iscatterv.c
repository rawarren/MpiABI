
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Iscatterv
 */

#include <_mpi.h>

int
MPI_Iscatterv (void *sendbuf, int sendcounts[], int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
  static void *address=0;
  int vendor_root;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Iscatterv")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Iscatterv",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *request = new_index(active_requests);
  vendor_root = PROCNULL(root);
  if (vendor_root == root) 
      vendor_root = ISROOT(root);

  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
      int (*VendorMPI_Iscatterv)(void *sendbuf,int sendcounts[],int displs[],void *,void *recvbuf,int recvcount,void *,int root,void *, void **) = address;
      mpi_return = (*VendorMPI_Iscatterv)(INPLACE(sendbuf),sendcounts,displs,local_a0[sendtype].mpi_const,INPLACE(recvbuf),recvcount,local_a1[recvtype].mpi_const,vendor_root,local_a2[comm].mpi_const,&local_a3[*request].mpi_const);
    }
    else { api_use_ints *local_a3=active_requests->api_declared;
      int (*VendorMPI_Iscatterv)(void *sendbuf,int sendcounts[],int displs[],void *,void *recvbuf,int recvcount,void *,int root,void *, int *) = address;
      mpi_return = (*VendorMPI_Iscatterv)(INPLACE(sendbuf),sendcounts,displs,local_a0[sendtype].mpi_const,INPLACE(recvbuf),recvcount,local_a1[recvtype].mpi_const,vendor_root,local_a2[comm].mpi_const,&local_a3[*request].mpi_const);
    }    
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
      int (*VendorMPI_Iscatterv)(void *sendbuf,int sendcounts[],int displs[],int,void *recvbuf,int recvcount,int,int root,int, void **) = address;
      mpi_return = (*VendorMPI_Iscatterv)(INPLACE(sendbuf),sendcounts,displs,local_a0[sendtype].mpi_const,INPLACE(recvbuf),recvcount,local_a1[recvtype].mpi_const,vendor_root,local_a2[comm].mpi_const,&local_a3[*request].mpi_const);
    }
    else { api_use_ints *local_a3=active_requests->api_declared;
      int (*VendorMPI_Iscatterv)(void *sendbuf,int sendcounts[],int displs[],int,void *recvbuf,int recvcount,int,int root,int, int *) = address;
      mpi_return = (*VendorMPI_Iscatterv)(INPLACE(sendbuf),sendcounts,displs,local_a0[sendtype].mpi_const,INPLACE(recvbuf),recvcount,local_a1[recvtype].mpi_const,vendor_root,local_a2[comm].mpi_const,&local_a3[*request].mpi_const);
    }
  }
  return mpi_return;
}
