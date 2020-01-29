
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_free
 */

#include <_mpi.h>

int
MPI_Type_free (MPI_Datatype *type)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_free")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_free",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_free)(void **) = address;
    void *native_type = local_a0[*type].mpi_const;
    mpi_return = (*VendorMPI_Type_free)(&native_type);
    if (native_type == local_a0[ISC_DATATYPE_NULL].mpi_const) {
      remove_object_keyval_callbacks(*type,-1,DATATYPE_CALLBACK);
      free_index(active_datatypes,*type);
      *type = ISC_DATATYPE_NULL;
    }
  }
  else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_free)(int *) = address;
    int native_type = local_a0[*type].mpi_const;
    mpi_return = (*VendorMPI_Type_free)(&native_type);
    if (native_type == local_a0[ISC_DATATYPE_NULL].mpi_const) {
      remove_object_keyval_callbacks(*type,-1,DATATYPE_CALLBACK);
      free_index(active_datatypes,*type);
      *type = ISC_DATATYPE_NULL;
    }
  }
  return mpi_return;
}
