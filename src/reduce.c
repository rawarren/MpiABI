
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Reduce
 */

#include <_mpi.h>

int
MPI_Reduce (void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)
{
  static void *address=0;
  int vendor_root;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Reduce")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Reduce",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  vendor_root = PROCNULL(root);
  if (vendor_root == root) 
      vendor_root = ISROOT(root);

  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1=active_ops->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    int (*VendorMPI_Reduce)(void *sendbuf,void *recvbuf,int count,void *,void *,int root,void *) = address;
    mpi_return = (*VendorMPI_Reduce)(INPLACE(sendbuf),INPLACE(recvbuf),count,local_a0[datatype].mpi_const,local_a1[op].mpi_const,vendor_root,local_a2[comm].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1=active_ops->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    int (*VendorMPI_Reduce)(void *sendbuf,void *recvbuf,int count,int,int,int root,int) = address;
    mpi_return = (*VendorMPI_Reduce)(INPLACE(sendbuf),INPLACE(recvbuf),count,local_a0[datatype].mpi_const,local_a1[op].mpi_const,vendor_root,local_a2[comm].mpi_const);
  }
  return mpi_return;
}
