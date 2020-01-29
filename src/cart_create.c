
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Cart_create
 */

#include <_mpi.h>

int
MPI_Cart_create (MPI_Comm old_comm, int ndims, int dims[], int periods[], int reorder, MPI_Comm *new_comm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Cart_create")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Cart_create",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  *new_comm = new_index(active_comms);
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    int (*VendorMPI_Cart_create)(void *,int ndims,int dims[],int periods[],int reorder,void **) = address;
    mpi_return = (*VendorMPI_Cart_create)(local_a0[old_comm].mpi_const,ndims,dims,periods,reorder,&local_a1[*new_comm].mpi_const);
    if (local_a1[*new_comm].mpi_const == local_a1[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*new_comm);
      *new_comm = MPI_COMM_NULL;
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    int (*VendorMPI_Cart_create)(int,int ndims,int dims[],int periods[],int reorder,int *) = address;
    mpi_return = (*VendorMPI_Cart_create)(local_a0[old_comm].mpi_const,ndims,dims,periods,reorder,&local_a1[*new_comm].mpi_const);
    if (local_a1[*new_comm].mpi_const == local_a1[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*new_comm);
      *new_comm = MPI_COMM_NULL;
    }
  }
  return mpi_return;
}
