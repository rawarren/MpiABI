
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_get_errhandler
 */

#include <_mpi.h>

int
MPI_Comm_get_errhandler (MPI_Comm comm, MPI_Errhandler *erhandler)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_get_errhandler")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_get_errhandler",SYM_MISSING_TRAILER);
      return -1;
    }
  }

#if 0
  *erhandler = new_index(active_errhandlers);
#endif

  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1=active_errhandlers->api_declared;
    int (*VendorMPI_Comm_get_errhandler)(void *,void **) = address;
#if 0
    mpi_return = (*VendorMPI_Comm_get_errhandler)(local_a0[comm].mpi_const,&local_a1[*erhandler].mpi_const);
    if (local_a1[*erhandler].mpi_const == local_a1[MPI_ERRHANDLER_NULL].mpi_const) {
      free_index(active_errhandlers,*erhandler);
      *erhandler = MPI_ERRHANDLER_NULL;
    }
#else
    void *vendor_value=0;
    mpi_return = (*VendorMPI_Comm_get_errhandler)(local_a0[comm].mpi_const,&vendor_value);
    *erhandler = get_index(active_errhandlers,(void *)&vendor_value);
#endif
  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1=active_errhandlers->api_declared;
    int (*VendorMPI_Comm_get_errhandler)(int,int *) = address;
#if 0
    mpi_return = (*VendorMPI_Comm_get_errhandler)(local_a0[comm].mpi_const,&local_a1[*erhandler].mpi_const);
    if (local_a1[*erhandler].mpi_const == local_a1[MPI_ERRHANDLER_NULL].mpi_const) {
      free_index(active_errhandlers,*erhandler);
      *erhandler = MPI_ERRHANDLER_NULL;
    }
#else
    int vendor_value=0;
    mpi_return = (*VendorMPI_Comm_get_errhandler)(local_a0[comm].mpi_const,&vendor_value);
    *erhandler = get_index(active_errhandlers,(void *)&vendor_value);
#endif
  }
  return mpi_return;
}
