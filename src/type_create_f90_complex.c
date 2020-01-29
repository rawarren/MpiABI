
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_f90_complex
 */

#include <_mpi.h>

int
MPI_Type_create_f90_complex (int p, int r, MPI_Datatype *newtype)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_create_f90_complex")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_create_f90_complex",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newtype = new_index(active_datatypes);
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_create_f90_complex)(int p,int r,void **) = address;
    mpi_return = (*VendorMPI_Type_create_f90_complex)(p,r,&local_a0[*newtype].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_create_f90_complex)(int p,int r,int *) = address;
    mpi_return = (*VendorMPI_Type_create_f90_complex)(p,r,&local_a0[*newtype].mpi_const);
  }
  return mpi_return;
}
