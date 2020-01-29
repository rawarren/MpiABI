
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Errhandler_set
 */

#include <_mpi.h>

int
MPI_Errhandler_set (MPI_Comm comm, MPI_Errhandler errhandler)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Errhandler_set")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Errhandler_set",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    if (active_errhandlers->use_ptrs) { api_use_ptrs *local_a1=active_errhandlers->api_declared;
      int (*VendorMPI_Errhandler_set)(void *,void *) = address;
      mpi_return = (*VendorMPI_Errhandler_set)(local_a0[comm].mpi_const,local_a1[errhandler].mpi_const);
    } else {
      api_use_ints *local_a1=active_errhandlers->api_declared;
      int (*VendorMPI_Errhandler_set)(void *,int) = address;
      mpi_return = (*VendorMPI_Errhandler_set)(local_a0[comm].mpi_const,local_a1[errhandler].mpi_const);
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    if (active_errhandlers->use_ptrs) { api_use_ptrs *local_a1=active_errhandlers->api_declared;
      int (*VendorMPI_Errhandler_set)(int,void *) = address;
      mpi_return = (*VendorMPI_Errhandler_set)(local_a0[comm].mpi_const,local_a1[errhandler].mpi_const);
    }
    else {api_use_ints *local_a1=active_errhandlers->api_declared;
      int (*VendorMPI_Errhandler_set)(int,int) = address;
      mpi_return = (*VendorMPI_Errhandler_set)(local_a0[comm].mpi_const,local_a1[errhandler].mpi_const);
    }
  }
  return mpi_return;
}
