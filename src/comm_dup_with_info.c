
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_dup_with_info
 */

#include <_mpi.h>

int
MPI_Comm_dup_with_info (MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_dup_with_info")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_dup_with_info",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newcomm = new_index(active_comms);
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    if (active_infos->use_ptrs) { api_use_ptrs *local_a1=active_infos->api_declared;
      int (*VendorMPI_Comm_dup_with_info)(void *,void *,void **) = address;
      mpi_return = (*VendorMPI_Comm_dup_with_info)(local_a0[comm].mpi_const,local_a1[info].mpi_const,&local_a0[*newcomm].mpi_const);
    } else { api_use_ints *local_a1= active_infos->api_declared;
      int (*VendorMPI_Comm_dup_with_info)(void *, int ,void **) = address;
      mpi_return = (*VendorMPI_Comm_dup_with_info)(local_a0[comm].mpi_const,local_a1[info].mpi_const,&local_a0[*newcomm].mpi_const);      
    }
    if (local_a0[*newcomm].mpi_const == local_a0[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    if (active_infos->use_ptrs) { api_use_ptrs *local_a1=active_infos->api_declared;    
      int (*VendorMPI_Comm_dup_with_info)(int,void *,int *) = address;
      mpi_return = (*VendorMPI_Comm_dup_with_info)(local_a0[comm].mpi_const,local_a1[info].mpi_const,&local_a0[*newcomm].mpi_const);
    }
    else { api_use_ints *local_a1= active_infos->api_declared;
      int (*VendorMPI_Comm_dup_with_info)(int,int,int *) = address;
      mpi_return = (*VendorMPI_Comm_dup_with_info)(local_a0[comm].mpi_const,local_a1[info].mpi_const,&local_a0[*newcomm].mpi_const);
    }
    if (local_a0[*newcomm].mpi_const == local_a0[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }
  }
  return mpi_return;
}
