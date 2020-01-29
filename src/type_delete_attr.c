
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_delete_attr
 */

#include <_mpi.h>

int
MPI_Type_delete_attr (MPI_Datatype type, int type_keyval)
{
  static void *address=0;
  api_use_ints *local_a1 = active_miscs->api_declared;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_delete_attr")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_delete_attr",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_delete_attr)(void *, int) = address;
    mpi_return = (*VendorMPI_Type_delete_attr)(local_a0[type].mpi_const,local_a1[type_keyval].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_delete_attr)(int, int) = address;
    mpi_return = (*VendorMPI_Type_delete_attr)(local_a0[type].mpi_const,local_a1[type_keyval].mpi_const);
  }

#if 0
  if ((mpi_return == 0) && (attr_reference_exists(type,type_keyval,DATATYPE_CALLBACK) == 0)) {
    remove_object_keyval_callbacks(type,type_keyval,DATATYPE_CALLBACK);
    free_index(active_miscs,type_keyval);
  }
#else
  if (mpi_return == 0) {
    remove_object_keyval_callbacks(type,type_keyval,DATATYPE_CALLBACK);
    if (attr_reference_exists(-1,type_keyval,DATATYPE_CALLBACK) == 0)
       free_index(active_miscs,type_keyval);
  }
#endif

  return mpi_return;
}
