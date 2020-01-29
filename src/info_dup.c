
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_dup
 */

#include <_mpi.h>

int
MPI_Info_dup (MPI_Info info, MPI_Info *newinfo)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Info_dup")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Info_dup",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newinfo = new_index(active_infos);
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    api_use_ptrs *local_a1=active_infos->api_declared;
    int (*VendorMPI_Info_dup)(void *,void **) = address;
    mpi_return = (*VendorMPI_Info_dup)(local_a0[info].mpi_const,&local_a1[*newinfo].mpi_const);
  } else { api_use_ints *local_a0=active_infos->api_declared;
    api_use_ints *local_a1=active_infos->api_declared;
    int (*VendorMPI_Info_dup)(int,int *) = address;
    mpi_return = (*VendorMPI_Info_dup)(local_a0[info].mpi_const,&local_a1[*newinfo].mpi_const);
  }
  return mpi_return;
}
