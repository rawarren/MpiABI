
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_delete
 */

#include <_mpi.h>

int
MPI_Info_delete (MPI_Info info, char *key)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Info_delete")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Info_delete",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_delete)(void *, char *key) = address;
    mpi_return = (*VendorMPI_Info_delete)(local_a0[info].mpi_const,key);
  } else { api_use_ints *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_delete)(int, char *key) = address;
    mpi_return = (*VendorMPI_Info_delete)(local_a0[info].mpi_const,key);
  }
  return mpi_return;
}
