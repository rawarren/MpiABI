
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_extent
 */

#include <_mpi.h>

int
MPI_Type_extent (MPI_Datatype type, MPI_Aint *extent)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_extent")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_extent",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_extent)(void *, MPI_Aint *extent) = address;
    mpi_return = (*VendorMPI_Type_extent)(local_a0[type].mpi_const,extent);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_extent)(int, MPI_Aint *extent) = address;
    mpi_return = (*VendorMPI_Type_extent)(local_a0[type].mpi_const,extent);
  }
  return mpi_return;
}
