
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_attr
 */

#include <_mpi.h>

static int _isc_proc_null = MPI_PROC_NULL;

int
MPI_Type_get_attr (MPI_Datatype type, int type_keyval, void *attribute_val, int *flag)
{
  static void *address=0;
  api_use_ints *local_a1 = active_miscs->api_declared;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_get_attr")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_get_attr",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_attr)(void *,int type_keyval,void *attribute_val, int *flag) = address;
    mpi_return = (*VendorMPI_Type_get_attr)(local_a0[type].mpi_const,local_a1[type_keyval].mpi_const,attribute_val,flag);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_attr)(int,int type_keyval,void *attribute_val, int *flag) = address;
    mpi_return = (*VendorMPI_Type_get_attr)(local_a0[type].mpi_const,local_a1[type_keyval].mpi_const,attribute_val,flag);
  }
  if (*flag) {
      int *a_val = (int *)attribute_val;
      if (*a_val == local_a1[ISC_PROC_NULL_].mpi_const)
		  *a_val = local_a1[ISC_PROC_NULL_].self;
  }
  return mpi_return;
}
