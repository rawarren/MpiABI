
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_group
 */

#include <_mpi.h>

int
MPI_File_get_group (MPI_File fh, MPI_Group *group)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_get_group")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_get_group",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  *group = new_index(active_groups);
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    api_use_ptrs *local_a1=active_groups->api_declared;
    int (*VendorMPI_File_get_group)(void *,void **) = address;
    mpi_return = (*VendorMPI_File_get_group)(local_a0[fh].mpi_const,&local_a1[*group].mpi_const);
    if (local_a1[*group].mpi_const == local_a1[MPI_GROUP_NULL].mpi_const) {
      free_index(active_comms,*group);
      *group = MPI_GROUP_NULL;
    }
  } else { api_use_ints *local_a0=active_files->api_declared;
    api_use_ints *local_a1=active_groups->api_declared;
    int (*VendorMPI_File_get_group)(int,int *) = address;
    mpi_return = (*VendorMPI_File_get_group)(local_a0[fh].mpi_const,&local_a1[*group].mpi_const);
    if (local_a1[*group].mpi_const == local_a1[MPI_GROUP_NULL].mpi_const) {
      free_index(active_comms,*group);
      *group = MPI_GROUP_NULL;
    }
  }
  return mpi_return;
}
