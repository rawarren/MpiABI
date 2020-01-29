
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_set
 */

#include <_mpi.h>

int
MPI_Info_set (MPI_Info info, char *key, char *value)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Info_set")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Info_set",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_set)(void *,char *key, char *value) = address;
    mpi_return = (*VendorMPI_Info_set)(local_a0[info].mpi_const,key,value);
  } else { api_use_ints *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_set)(int,char *key, char *value) = address;
    mpi_return = (*VendorMPI_Info_set)(local_a0[info].mpi_const,key,value);
  }
  return mpi_return;
}
