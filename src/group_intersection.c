
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_intersection
 */

#include <_mpi.h>

int
MPI_Group_intersection (MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Group_intersection")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Group_intersection",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newgroup = new_index(active_groups);
  if (active_groups->use_ptrs) { api_use_ptrs *local_a0=active_groups->api_declared;
    api_use_ptrs *local_a1=active_groups->api_declared;
    api_use_ptrs *local_a2=active_groups->api_declared;
    int (*VendorMPI_Group_intersection)(void *,void *,void **) = address;
    mpi_return = (*VendorMPI_Group_intersection)(local_a0[group1].mpi_const,local_a1[group2].mpi_const,&local_a2[*newgroup].mpi_const);
    if (local_a2[*newgroup].mpi_const == local_a2[MPI_GROUP_NULL].mpi_const) {
      free_index(active_groups,*newgroup);
      *newgroup = MPI_GROUP_NULL;
    }

  } else { api_use_ints *local_a0=active_groups->api_declared;
    api_use_ints *local_a1=active_groups->api_declared;
    api_use_ints *local_a2=active_groups->api_declared;
    int (*VendorMPI_Group_intersection)(int,int,int *) = address;
    mpi_return = (*VendorMPI_Group_intersection)(local_a0[group1].mpi_const,local_a1[group2].mpi_const,&local_a2[*newgroup].mpi_const);
    if (local_a2[*newgroup].mpi_const == local_a2[MPI_GROUP_NULL].mpi_const) {
      free_index(active_groups,*newgroup);
      *newgroup = MPI_GROUP_NULL;
    }
  }
  return mpi_return;
}
