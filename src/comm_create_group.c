
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_create
 */

#include <_mpi.h>

int
MPI_Comm_create_group (MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_create_group")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_create_group",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newcomm = new_index(active_comms);
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1=active_groups->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    int (*VendorMPI_Comm_create_group)(void *,void *,int,void **) = address;
    mpi_return = (*VendorMPI_Comm_create_group)(local_a0[comm].mpi_const,local_a1[group].mpi_const,tag,&local_a2[*newcomm].mpi_const);
    if (local_a2[*newcomm].mpi_const == local_a2[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }

  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1=active_groups->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    int (*VendorMPI_Comm_create_group)(int,int,int,int *) = address;
    mpi_return = (*VendorMPI_Comm_create_group)(local_a0[comm].mpi_const,local_a1[group].mpi_const, tag, &local_a2[*newcomm].mpi_const);
    if (local_a2[*newcomm].mpi_const == local_a2[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }
  }
  return mpi_return;
}
