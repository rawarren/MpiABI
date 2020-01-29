
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_dup
 */

#include <_mpi.h>

int
MPI_Type_dup (MPI_Datatype type, MPI_Datatype *newtype)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_dup")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_dup",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newtype = new_index(active_datatypes);
  // remove_object_keyval_callbacks(*newtype,-1,DATATYPE_CALLBACK);
  
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_dup)(void *,void **) = address;
    mpi_return = (*VendorMPI_Type_dup)(local_a0[type].mpi_const,&local_a1[*newtype].mpi_const);
    if (local_a1[*newtype].mpi_const == local_a1[MPI_DATATYPE_NULL].mpi_const) {
      free_index(active_datatypes,*newtype);
      *newtype = MPI_DATATYPE_NULL;
      return mpi_return;
    }

  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_dup)(int,int *) = address;
    mpi_return = (*VendorMPI_Type_dup)(local_a0[type].mpi_const,&local_a1[*newtype].mpi_const);
    if (local_a1[*newtype].mpi_const == local_a1[MPI_DATATYPE_NULL].mpi_const) {
      free_index(active_datatypes,*newtype);
      *newtype = MPI_DATATYPE_NULL;
      return mpi_return;
    }
  }
  maybe_dup_internal_reference(-1,type,*newtype,DATATYPE_CALLBACK);
  
  return mpi_return;
}
