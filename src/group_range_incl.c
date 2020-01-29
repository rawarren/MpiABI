
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_range_incl
 */

#include <_mpi.h>

int
MPI_Group_range_incl (MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Group_range_incl")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Group_range_incl",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newgroup = new_index(active_groups);

  if (active_groups->use_ptrs) { api_use_ptrs *local_a0=active_groups->api_declared;
    api_use_ptrs *local_a1=active_groups->api_declared;
    int (*VendorMPI_Group_range_incl)(void *,int n, int ranges[][3], void **) = address;
    mpi_return = (*VendorMPI_Group_range_incl)(local_a0[group].mpi_const,n,ranges,&local_a1[*newgroup].mpi_const);
    if (local_a0[*newgroup].mpi_const == local_a0[MPI_GROUP_NULL].mpi_const) {
      free_index(active_groups,*newgroup);
      *newgroup = MPI_GROUP_NULL;
    }
  } else { api_use_ints *local_a0=active_groups->api_declared;
    int (*VendorMPI_Group_range_incl)(int,int n, int ranges[][3], int *) = address;
    api_use_ints *local_a1=active_groups->api_declared;
    mpi_return = (*VendorMPI_Group_range_incl)(local_a0[group].mpi_const,n,ranges,&local_a1[*newgroup].mpi_const);
    if (local_a0[*newgroup].mpi_const == local_a0[MPI_GROUP_NULL].mpi_const) {
      free_index(active_groups,*newgroup);
      *newgroup = MPI_GROUP_NULL;
    }
  }
  return mpi_return;
}
