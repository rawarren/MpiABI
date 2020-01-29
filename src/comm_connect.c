
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_connect
 */

#include <_mpi.h>

int
MPI_Comm_connect (char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_connect")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_connect",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newcomm = new_index(active_comms);
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    int (*VendorMPI_Comm_connect)(char *port_name,void *,int root,void *,void **) = address;
    mpi_return = (*VendorMPI_Comm_connect)(port_name,local_a0[info].mpi_const,root,local_a1[comm].mpi_const,&local_a2[*newcomm].mpi_const);
    if (local_a2[*newcomm].mpi_const == local_a2[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }
  } else { api_use_ints *local_a0=active_infos->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    int (*VendorMPI_Comm_connect)(char *port_name,int,int root,int,int *) = address;
    mpi_return = (*VendorMPI_Comm_connect)(port_name,local_a0[info].mpi_const,root,local_a1[comm].mpi_const,&local_a2[*newcomm].mpi_const);
    if (local_a2[*newcomm].mpi_const == local_a2[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }
  }
  return mpi_return;
}
