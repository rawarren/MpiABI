
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Alloc_mem
 */

#include <_mpi.h>

int
MPI_Alloc_mem (MPI_Aint size, MPI_Info info, void *baseptr)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Alloc_mem")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Alloc_mem",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int (*VendorMPI_Alloc_mem)(MPI_Aint size,void *, void *baseptr) = address;
    mpi_return = (*VendorMPI_Alloc_mem)(size,local_a0[info].mpi_const,baseptr);
  } else { api_use_ints *local_a0=active_infos->api_declared;
    int (*VendorMPI_Alloc_mem)(MPI_Aint size,int, void *baseptr) = address;
    mpi_return = (*VendorMPI_Alloc_mem)(size,local_a0[info].mpi_const,baseptr);
  }
  return mpi_return;
}
