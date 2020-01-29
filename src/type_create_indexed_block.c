
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_indexed_block
 */

#include <_mpi.h>

int
MPI_Type_create_indexed_block (int count, int blocklength, int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_create_indexed_block")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_create_indexed_block",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newtype = new_index(active_datatypes);
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_create_indexed_block)(int count,int blocklength,int array_of_displacements[],void *,void **) = address;
    mpi_return = (*VendorMPI_Type_create_indexed_block)(count,blocklength,array_of_displacements,local_a0[oldtype].mpi_const,&local_a1[*newtype].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_create_indexed_block)(int count,int blocklength,int array_of_displacements[],int,int *) = address;
    mpi_return = (*VendorMPI_Type_create_indexed_block)(count,blocklength,array_of_displacements,local_a0[oldtype].mpi_const,&local_a1[*newtype].mpi_const);
  }
  return mpi_return;
}

int
MPI_Type_create_hindexed_block (int count, int blocklength, MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_create_hindexed_block")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_create_hindexed_block",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newtype = new_index(active_datatypes);
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_create_hindexed_block)(int count,int blocklength,MPI_Aint array_of_displacements[],void *,void **) = address;
    mpi_return = (*VendorMPI_Type_create_hindexed_block)(count,blocklength,array_of_displacements,local_a0[oldtype].mpi_const,&local_a1[*newtype].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_create_hindexed_block)(int count,int blocklength,MPI_Aint array_of_displacements[],int,int *) = address;
    mpi_return = (*VendorMPI_Type_create_hindexed_block)(count,blocklength,array_of_displacements,local_a0[oldtype].mpi_const,&local_a1[*newtype].mpi_const);
  }
  return mpi_return;
}
