
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_get_nkeys
 */

#include <_mpi.h>

int
MPI_Info_get_nkeys (MPI_Info info, int *nkeys)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Info_get_nkeys")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Info_get_nkeys",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_get_nkeys)(void *, int *nkeys) = address;
    mpi_return = (*VendorMPI_Info_get_nkeys)(local_a0[info].mpi_const,nkeys);
  } else { api_use_ints *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_get_nkeys)(int, int *nkeys) = address;
    mpi_return = (*VendorMPI_Info_get_nkeys)(local_a0[info].mpi_const,nkeys);
  }
  return mpi_return;
}
