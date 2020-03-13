
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_free
 */

#include <_mpi.h>

int
MPI_Group_free (MPI_Group *group)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Group_free")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Group_free",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_groups->use_ptrs) { api_use_ptrs *local_a0=active_groups->api_declared;
    int (*VendorMPI_Group_free)(void **) = address;
    if (*group < active_groups->permlimit) {
	*group = MPI_GROUP_NULL;
	return MPI_SUCCESS;
    }
    mpi_return = (*VendorMPI_Group_free)(&local_a0[*group].mpi_const);
    if (local_a0[*group].mpi_const == local_a0[MPI_GROUP_NULL].mpi_const) {
      free_index(active_groups,*group);
      *group = MPI_GROUP_NULL;
    }

  } else { api_use_ints *local_a0=active_groups->api_declared;
    int (*VendorMPI_Group_free)(int *) = address;
    if (*group < active_groups->permlimit) {
	*group = MPI_GROUP_NULL;
	return MPI_SUCCESS;
    }
    mpi_return = (*VendorMPI_Group_free)(&local_a0[*group].mpi_const);
    if (local_a0[*group].mpi_const == local_a0[MPI_GROUP_NULL].mpi_const) {
      free_index(active_groups,*group);
      *group = MPI_GROUP_NULL;
    }
  }
  return mpi_return;
}
