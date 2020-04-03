
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Ibcast
 */

#include <_mpi.h>

int
MPI_Ibcast (void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request)
{
  static void *address=0;
  int vendor_root;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Ibcast")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Ibcast",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *request = new_index(active_requests);
  vendor_root = PROCNULL(root);
  if (vendor_root == root) 
      vendor_root = ISROOT(root);

  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a2=active_requests->api_declared;
      int (*VendorMPI_Ibcast)(void *buffer,int count,void *,int root,void *, void **) = address;
      mpi_return = (*VendorMPI_Ibcast)(INPLACE(buffer),count,local_a0[datatype].mpi_const,vendor_root,local_a1[comm].mpi_const,&local_a2[*request].mpi_const);
    }
    else { api_use_ints *local_a2=active_requests->api_declared;
      int (*VendorMPI_Ibcast)(void *buffer,int count,void *,int root,void *, int *) = address;
      mpi_return = (*VendorMPI_Ibcast)(INPLACE(buffer),count,local_a0[datatype].mpi_const,vendor_root,local_a1[comm].mpi_const,&local_a2[*request].mpi_const);
    }
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a2=active_requests->api_declared;
      int (*VendorMPI_Ibcast)(void *buffer,int count, int, int, int, void **) = address;
      mpi_return = (*VendorMPI_Ibcast)(INPLACE(buffer),count,local_a0[datatype].mpi_const,vendor_root,local_a1[comm].mpi_const,&local_a2[*request].mpi_const);
    }
    else { api_use_ints *local_a2=active_requests->api_declared;
      int (*VendorMPI_Ibcast)(void *buffer,int count, int, int, int, int *) = address;
      mpi_return = (*VendorMPI_Ibcast)(INPLACE(buffer),count,local_a0[datatype].mpi_const,vendor_root,local_a1[comm].mpi_const,&local_a2[*request].mpi_const);
    }
  }
  return mpi_return;
}
