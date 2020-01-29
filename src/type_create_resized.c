
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_resized
 */

#include <_mpi.h>

int
MPI_Type_create_resized (MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Datatype *newtype)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_create_resized")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_create_resized",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newtype = new_index(active_datatypes);
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_create_resized)(void *,MPI_Aint lb,MPI_Aint extent,void **) = address;
    mpi_return = (*VendorMPI_Type_create_resized)(local_a0[oldtype].mpi_const,lb,extent,&local_a1[*newtype].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_create_resized)(int,MPI_Aint lb,MPI_Aint extent,int *) = address;
    mpi_return = (*VendorMPI_Type_create_resized)(local_a0[oldtype].mpi_const,lb,extent,&local_a1[*newtype].mpi_const);
  }
  return mpi_return;
}
