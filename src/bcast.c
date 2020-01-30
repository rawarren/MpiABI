
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Bcast
 */

#include <_mpi.h>

int
MPI_Bcast (void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
  static void *address=0;
  int vendor_root;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Bcast")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Bcast",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  
  vendor_root = PROCNULL(root);
  if (vendor_root == root) 
      vendor_root = ISROOT(root);

  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    int (*VendorMPI_Bcast)(void *buffer,int count,void *,int root,void *) = address;
    mpi_return = (*VendorMPI_Bcast)(INPLACE(buffer),count,local_a0[datatype].mpi_const,vendor_root,local_a1[comm].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    int (*VendorMPI_Bcast)(void *buffer,int count,int,int root,int) = address;
    mpi_return = (*VendorMPI_Bcast)(INPLACE(buffer),count,local_a0[datatype].mpi_const,vendor_root,local_a1[comm].mpi_const);
  }
  return mpi_return;
}
