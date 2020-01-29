
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Ibarrier
 */

#include <_mpi.h>

int
MPI_Ibarrier (MPI_Comm comm, MPI_Request *request)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Ibarrier")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Ibarrier",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *request = new_index(active_requests);
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a1=active_requests->api_declared;
      int (*VendorMPI_Ibarrier)(void *, void **) = address;
      mpi_return = (*VendorMPI_Ibarrier)(local_a0[comm].mpi_const,&local_a1[*request].mpi_const);
    }
    else { api_use_ints *local_a1=active_requests->api_declared;
      int (*VendorMPI_Ibarrier)(void *, int *) = address;
      mpi_return = (*VendorMPI_Ibarrier)(local_a0[comm].mpi_const,&local_a1[*request].mpi_const);
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a1=active_requests->api_declared;
      int (*VendorMPI_Ibarrier)(int, void **) = address;
      mpi_return = (*VendorMPI_Ibarrier)(local_a0[comm].mpi_const,&local_a1[*request].mpi_const);
    }
    else { api_use_ints *local_a1=active_requests->api_declared;
      int (*VendorMPI_Ibarrier)(int, int *) = address;
      mpi_return = (*VendorMPI_Ibarrier)(local_a0[comm].mpi_const,&local_a1[*request].mpi_const);
    }
  }
  return mpi_return;
}
