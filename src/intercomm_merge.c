
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Intercomm_merge
 */

#include <_mpi.h>

int
MPI_Intercomm_merge (MPI_Comm intercomm, int high, MPI_Comm *newintercomm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Intercomm_merge")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Intercomm_merge",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newintercomm = new_index(active_comms);
  
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    int (*VendorMPI_Intercomm_merge)(void *,int high,void **) = address;
    mpi_return = (*VendorMPI_Intercomm_merge)(local_a0[intercomm].mpi_const,high,&local_a1[*newintercomm].mpi_const);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    int (*VendorMPI_Intercomm_merge)(int,int high,int *) = address;
    mpi_return = (*VendorMPI_Intercomm_merge)(local_a0[intercomm].mpi_const,high,&local_a1[*newintercomm].mpi_const);
  }
  return mpi_return;
}
