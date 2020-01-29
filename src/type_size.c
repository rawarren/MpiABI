
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_size
 */

#include <_mpi.h>

int
MPI_Type_size (MPI_Datatype type, int *size)
{
  static void *address=0;
  api_use_ints *local_a1= active_miscs->api_declared;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_size")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_size",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_size)(void *, int *size) = address;
    mpi_return = (*VendorMPI_Type_size)(local_a0[type].mpi_const,size);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_size)(int, int *size) = address;
    mpi_return = (*VendorMPI_Type_size)(local_a0[type].mpi_const,size);
  }

  if (*size == local_a1[ISC_UNDEFINED_].mpi_const)
    *size = MPI_UNDEFINED;
  return mpi_return;
}

int
MPI_Type_size_x (MPI_Datatype type, MPI_Count *size)
{
  static void *address=0;
  api_use_ints *local_a1= active_miscs->api_declared;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_size_x")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_size_x",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_size)(void *, MPI_Count *size) = address;
    mpi_return = (*VendorMPI_Type_size)(local_a0[type].mpi_const,size);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_size)(int, MPI_Count *size) = address;
    mpi_return = (*VendorMPI_Type_size)(local_a0[type].mpi_const,size);
  }
  if (*size == local_a1[ISC_UNDEFINED_].mpi_const)
    *size = (MPI_Count)MPI_UNDEFINED;

  return mpi_return;
}
