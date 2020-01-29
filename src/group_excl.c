
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_excl
 */

#include <_mpi.h>

int
MPI_Group_excl (MPI_Group group, int n, int *ranks, MPI_Group *newgroup)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Group_excl")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Group_excl",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newgroup = new_index(active_groups);
  if (active_groups->use_ptrs) { api_use_ptrs *local_a0=active_groups->api_declared;
    api_use_ptrs *local_a1=active_groups->api_declared;
    int (*VendorMPI_Group_excl)(void *,int, int *, void **) = address;
    mpi_return = (*VendorMPI_Group_excl)(local_a0[group].mpi_const,n, ranks,&local_a1[*newgroup].mpi_const);
    if (local_a1[*newgroup].mpi_const == local_a1[MPI_GROUP_NULL].mpi_const) {
      free_index(active_requests,*newgroup);
      *newgroup = MPI_GROUP_NULL;
    } else if (local_a1[*newgroup].mpi_const == local_a1[MPI_GROUP_EMPTY].mpi_const) {
      free_index(active_requests,*newgroup);
      *newgroup = MPI_GROUP_EMPTY;
    }

  } else { api_use_ints *local_a0=active_groups->api_declared;
    api_use_ints *local_a1=active_groups->api_declared;
    int (*VendorMPI_Group_excl)(int ,int, int *, int *) = address;
    mpi_return = (*VendorMPI_Group_excl)(local_a0[group].mpi_const,n, ranks,&local_a1[*newgroup].mpi_const);
    if (local_a1[*newgroup].mpi_const == local_a1[MPI_GROUP_NULL].mpi_const) {
      free_index(active_requests,*newgroup);
      *newgroup = MPI_GROUP_NULL;
    } else if (local_a1[*newgroup].mpi_const == local_a1[MPI_GROUP_EMPTY].mpi_const) {
      free_index(active_requests,*newgroup);
      *newgroup = MPI_GROUP_EMPTY;
    }
  }
  return mpi_return;
}
