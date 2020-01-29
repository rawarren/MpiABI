
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_set_name
 */

#include <_mpi.h>

int
MPI_Type_set_name (MPI_Datatype type, char *type_name)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_set_name")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_set_name",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_set_name)(void *, char *type_name) = address;
    mpi_return = (*VendorMPI_Type_set_name)(local_a0[type].mpi_const,type_name);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_set_name)(int, char *type_name) = address;
    mpi_return = (*VendorMPI_Type_set_name)(local_a0[type].mpi_const,type_name);
  }
  return mpi_return;
}
