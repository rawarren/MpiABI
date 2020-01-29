
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_vector
 */

#include <_mpi.h>

int
MPI_Type_vector (int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_vector")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_vector",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newtype = new_index(active_datatypes);
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    void *native_dtype = NULL;
    int (*VendorMPI_Type_vector)(int count,int blocklength,int stride,void *,void **) = address;
    mpi_return = (*VendorMPI_Type_vector)(count,blocklength,stride,local_a0[oldtype].mpi_const, &native_dtype);
    local_a1[*newtype].mpi_const = native_dtype;
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_vector)(int count,int blocklength,int stride,int,int *) = address;
    mpi_return = (*VendorMPI_Type_vector)(count,blocklength,stride,local_a0[oldtype].mpi_const,&local_a1[*newtype].mpi_const);
  }
  return mpi_return;
}
