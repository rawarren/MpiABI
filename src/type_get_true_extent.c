
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_true_extent
 */

#include <_mpi.h>

int
MPI_Type_get_true_extent (MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_get_true_extent")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_get_true_extent",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_true_extent)(void *,MPI_Aint *true_lb, MPI_Aint *true_extent) = address;
    mpi_return = (*VendorMPI_Type_get_true_extent)(local_a0[datatype].mpi_const,true_lb,true_extent);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_true_extent)(int,MPI_Aint *true_lb, MPI_Aint *true_extent) = address;
    mpi_return = (*VendorMPI_Type_get_true_extent)(local_a0[datatype].mpi_const,true_lb,true_extent);
  }
  return mpi_return;
}

int
MPI_Type_get_true_extent_x (MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_get_true_extent_x")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_get_true_extent_x",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_true_extent_x)(void *,MPI_Count *, MPI_Count *) = address;
    mpi_return = (*VendorMPI_Type_get_true_extent_x)(local_a0[datatype].mpi_const,true_lb,true_extent);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_true_extent_x)(int,MPI_Count *, MPI_Count *) = address;
    mpi_return = (*VendorMPI_Type_get_true_extent_x)(local_a0[datatype].mpi_const,true_lb,true_extent);
  }
  return mpi_return;
}
