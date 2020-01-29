
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_free
 */

#include <_mpi.h>

int
MPI_Info_free (MPI_Info *info)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Info_free")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Info_free",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_free)(void **) = address;
    mpi_return = (*VendorMPI_Info_free)(&local_a0[*info].mpi_const);
    if (local_a0[*info].mpi_const == local_a0[MPI_INFO_NULL].mpi_const) {
      free_index(active_infos,*info);
      *info = MPI_INFO_NULL;
    }
  } else { api_use_ints *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_free)(int *) = address;
    mpi_return = (*VendorMPI_Info_free)(&local_a0[*info].mpi_const);
    if (local_a0[*info].mpi_const == local_a0[MPI_INFO_NULL].mpi_const) {
      free_index(active_infos,*info);
      *info = MPI_INFO_NULL;
    }
  }
  return mpi_return;
}
