
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_extent
 */

#include <_mpi.h>

int
MPI_Type_get_extent (MPI_Datatype type, MPI_Aint *lb, MPI_Aint *extent)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_get_extent")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_get_extent",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_extent)(void *,MPI_Aint *, MPI_Aint *) = address;
    mpi_return = (*VendorMPI_Type_get_extent)(local_a0[type].mpi_const,lb,extent);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_extent)(int,MPI_Aint *, MPI_Aint *) = address;
    mpi_return = (*VendorMPI_Type_get_extent)(local_a0[type].mpi_const,lb,extent);
  }
  return mpi_return;
}

int
MPI_Type_get_extent_x (MPI_Datatype type, MPI_Count *lb, MPI_Count *extent)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_get_extent_x")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_get_extent_x",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_extent_x)(void *,MPI_Count *, MPI_Count *) = address;
    mpi_return = (*VendorMPI_Type_get_extent_x)(local_a0[type].mpi_const,lb,extent);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_extent_x)(int,MPI_Count *, MPI_Count *) = address;
    mpi_return = (*VendorMPI_Type_get_extent_x)(local_a0[type].mpi_const,lb,extent);
  }
  return mpi_return;
}
