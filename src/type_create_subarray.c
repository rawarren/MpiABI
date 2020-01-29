
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_subarray
 */

#include <_mpi.h>

int
MPI_Type_create_subarray (int ndims, int size_array[], int subsize_array[], int start_array[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_Type_create_subarray")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_create_subarray",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newtype = new_index(active_datatypes);

  api_use_ints *local_a1 = active_miscs->api_declared;
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_create_subarray)(int ndims,int size_array[],int subsize_array[],int start_array[],int order,void *,void **) = address;
    mpi_return = (*VendorMPI_Type_create_subarray)(ndims,size_array,subsize_array,start_array,local_a1[order].mpi_const,local_a0[oldtype].mpi_const,&local_a0[*newtype].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_create_subarray)(int ndims,int size_array[],int subsize_array[],int start_array[],int order,int,int *) = address;
    mpi_return = (*VendorMPI_Type_create_subarray)(ndims,size_array,subsize_array,start_array,local_a1[order].mpi_const,local_a0[oldtype].mpi_const,&local_a0[*newtype].mpi_const);
  }
  return mpi_return;
}
