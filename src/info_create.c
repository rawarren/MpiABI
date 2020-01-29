
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_create
 */

#include <_mpi.h>

int
MPI_Info_create (MPI_Info *info)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Info_create")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Info_create",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *info = new_index(active_infos);
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_create)(void **) = address;
    mpi_return = (*VendorMPI_Info_create)(&local_a0[*info].mpi_const);
  } else { api_use_ints *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_create)(int *) = address;
    mpi_return = (*VendorMPI_Info_create)(&local_a0[*info].mpi_const);
  }
  return mpi_return;
}
