
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_match_size
 */

#include <_mpi.h>

int
MPI_Type_match_size (int typeclass, int size, MPI_Datatype *type)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_match_size")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_match_size",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int i;
    int (*VendorMPI_Type_match_size)(int typeclass,int size,void **) = address;
    void *mpitype;
    mpi_return = (*VendorMPI_Type_match_size)(typeclass,size,&mpitype);
    for(i=0; i<active_datatypes->limit; i++) {
      if (local_a0[i].mpi_const == mpitype) {
	*type = i;
	return mpi_return;
      }
    }
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int i;
    int (*VendorMPI_Type_match_size)(int typeclass,int size,int *) = address;
    int mpitype;
    mpi_return = (*VendorMPI_Type_match_size)(typeclass,size,&mpitype);
    for(i=0; i<active_datatypes->limit; i++) {
      if (local_a0[i].mpi_const == mpitype) {
	*type = i;
	return mpi_return;
      }
    }
  }
  return mpi_return;
}
