
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Intercomm_create
 */

#include <_mpi.h>

int
MPI_Intercomm_create (MPI_Comm local_comm, int local_leader, MPI_Comm bridge_comm, int remote_leader, int tag, MPI_Comm *newintercomm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Intercomm_create")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Intercomm_create",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newintercomm = new_index(active_comms);
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    int (*VendorMPI_Intercomm_create)(void *,int local_leader,void *,int remote_leader,int tag,void **) = address;
    mpi_return = (*VendorMPI_Intercomm_create)(local_a0[local_comm].mpi_const,local_leader,local_a1[bridge_comm].mpi_const,remote_leader,tag,&local_a2[*newintercomm].mpi_const);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    int (*VendorMPI_Intercomm_create)(int,int local_leader,int,int remote_leader,int tag,int *) = address;
    mpi_return = (*VendorMPI_Intercomm_create)(local_a0[local_comm].mpi_const,local_leader,local_a1[bridge_comm].mpi_const,remote_leader,tag,&local_a2[*newintercomm].mpi_const);
  }
  return mpi_return;
}
