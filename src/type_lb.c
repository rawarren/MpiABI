
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_lb
 */

#include <_mpi.h>

int
MPI_Type_lb (MPI_Datatype type, MPI_Aint *lb)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_lb")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_lb",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_lb)(void *, MPI_Aint *lb) = address;
    mpi_return = (*VendorMPI_Type_lb)(local_a0[type].mpi_const,lb);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_lb)(int, MPI_Aint *lb) = address;
    mpi_return = (*VendorMPI_Type_lb)(local_a0[type].mpi_const,lb);
  }
  return mpi_return;
}
