
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_set_attr
 */

#include <_mpi.h>

int
MPI_Type_set_attr (MPI_Datatype type, int type_keyval, void *attr_val)
{
  static void *address=0;
  api_use_ints *local_a1 = active_miscs->api_declared;
  int mpi_return;
  int native_keyval = local_a1[type_keyval].mpi_const;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_set_attr")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_set_attr",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  /* See related: MPI_Type_create_attr */
  maybe_update_callbacks(type,type_keyval,DATATYPE_CALLBACK);

  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_set_attr)(void *,int type_keyval, void *attr_val) = address;
    mpi_return = (*VendorMPI_Type_set_attr)(local_a0[type].mpi_const,native_keyval,attr_val);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_set_attr)(int,int type_keyval, void *attr_val) = address;
    mpi_return = (*VendorMPI_Type_set_attr)(local_a0[type].mpi_const,native_keyval,attr_val);
  }
  return mpi_return;
}
