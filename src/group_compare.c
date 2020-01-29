
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_compare
 */

#include <_mpi.h>

int
MPI_Group_compare (MPI_Group group1, MPI_Group group2, int *result)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Group_compare")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Group_compare",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_groups->use_ptrs) { api_use_ptrs *local_a0=active_groups->api_declared;
    api_use_ptrs *local_a1=active_groups->api_declared;
    int (*VendorMPI_Group_compare)(void *,void *, int *result) = address;
    mpi_return = (*VendorMPI_Group_compare)(local_a0[group1].mpi_const,local_a1[group2].mpi_const,result);
  } else { api_use_ints *local_a0=active_groups->api_declared;
    api_use_ints *local_a1=active_groups->api_declared;
    int (*VendorMPI_Group_compare)(int,int, int *result) = address;
    mpi_return = (*VendorMPI_Group_compare)(local_a0[group1].mpi_const,local_a1[group2].mpi_const,result);
  }
  return mpi_return;
}
