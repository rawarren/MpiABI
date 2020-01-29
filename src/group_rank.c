
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_rank
 */

#include <_mpi.h>

int
MPI_Group_rank (MPI_Group group, int *rank)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a1=active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Group_rank")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Group_rank",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_groups->use_ptrs) { api_use_ptrs *local_a0=active_groups->api_declared;
    int (*VendorMPI_Group_rank)(void *, int *rank) = address;
    mpi_return = (*VendorMPI_Group_rank)(local_a0[group].mpi_const,rank);
  } else { api_use_ints *local_a0=active_groups->api_declared;
    int (*VendorMPI_Group_rank)(int, int *rank) = address;
    mpi_return = (*VendorMPI_Group_rank)(local_a0[group].mpi_const,rank);
  }
  if ((mpi_return == 0) && (*rank == local_a1[ISC_UNDEFINED_].mpi_const))
    *rank = MPI_UNDEFINED;

  return mpi_return;
}
