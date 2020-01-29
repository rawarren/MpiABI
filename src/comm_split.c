
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_split
 */

#include <_mpi.h>
#include <stdlib.h>

int
MPI_Comm_split (MPI_Comm comm, int color, int key, MPI_Comm *newcomm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_split")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_split",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newcomm = new_index(active_comms);
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    int (*VendorMPI_Comm_split)(void *,int color,int key,void **) = address;
    mpi_return = (*VendorMPI_Comm_split)(local_a0[comm].mpi_const,UNCOLOR(color),key,&local_a1[*newcomm].mpi_const);
    if (local_a1[*newcomm].mpi_const == local_a1[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    int (*VendorMPI_Comm_split)(int,int color,int key,int *) = address;
    mpi_return = (*VendorMPI_Comm_split)(local_a0[comm].mpi_const,UNCOLOR(color),key,&local_a1[*newcomm].mpi_const);
    if (local_a1[*newcomm].mpi_const == local_a1[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }
  }

  return mpi_return;
}
