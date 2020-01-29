
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_size
 */

#include <_mpi.h>

int
MPI_Group_size (MPI_Group group, int *size)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Group_size")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Group_size",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_groups->use_ptrs) { api_use_ptrs *local_a0=active_groups->api_declared;
    int (*VendorMPI_Group_size)(void *, int *size) = address;
    mpi_return = (*VendorMPI_Group_size)(local_a0[group].mpi_const,size);
  } else { api_use_ints *local_a0=active_groups->api_declared;
    int (*VendorMPI_Group_size)(int, int *size) = address;
    mpi_return = (*VendorMPI_Group_size)(local_a0[group].mpi_const,size);
  }
  return mpi_return;
}
