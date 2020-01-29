
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_get_nthkey
 */

#include <_mpi.h>

int
MPI_Info_get_nthkey (MPI_Info info, int n, char *key)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Info_get_nthkey")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Info_get_nthkey",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_get_nthkey)(void *,int n, char *key) = address;
    mpi_return = (*VendorMPI_Info_get_nthkey)(local_a0[info].mpi_const,n,key);
  } else { api_use_ints *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_get_nthkey)(int,int n, char *key) = address;
    mpi_return = (*VendorMPI_Info_get_nthkey)(local_a0[info].mpi_const,n,key);
  }
  return mpi_return;
}
