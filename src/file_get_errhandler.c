
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_errhandler
 */

#include <_mpi.h>

int
MPI_File_get_errhandler ( MPI_File file, MPI_Errhandler *errhandler)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_get_errhandler")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_get_errhandler",SYM_MISSING_TRAILER);
      return -1;
    }
  }
#if 0
  *errhandler = new_index(active_errhandlers);
#endif
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    api_use_ptrs *local_a1=active_errhandlers->api_declared;
    int (*VendorMPI_File_get_errhandler)(void *,void **) = address;
#if 0
    mpi_return = (*VendorMPI_File_get_errhandler)(local_a0[file].mpi_const,&local_a1[*errhandler].mpi_const);
    if (local_a1[*errhandler].mpi_const == local_a1[MPI_ERRHANDLER_NULL].mpi_const) {
      free_index(active_errhandlers,*errhandler);
      *errhandler = MPI_ERRHANDLER_NULL;
    }
#else
    void *vendor_value=0;
    mpi_return = (*VendorMPI_File_get_errhandler)(local_a0[file].mpi_const,&vendor_value);
    *errhandler = get_index(active_errhandlers,(void *)&vendor_value);
#endif
  } else { api_use_ints *local_a0=active_files->api_declared;
    api_use_ints *local_a1=active_errhandlers->api_declared;
    int (*VendorMPI_File_get_errhandler)(int,int *) = address;
#if 0
    mpi_return = (*VendorMPI_File_get_errhandler)(local_a0[file].mpi_const,&local_a1[*errhandler].mpi_const);
    if (local_a1[*errhandler].mpi_const == local_a1[MPI_ERRHANDLER_NULL].mpi_const) {
      free_index(active_errhandlers,*errhandler);
      *errhandler = MPI_ERRHANDLER_NULL;
    }
#else
    int vendor_value=0;
    mpi_return = (*VendorMPI_File_get_errhandler)(local_a0[file].mpi_const,&vendor_value);
    *errhandler = get_index(active_errhandlers,(void *)&vendor_value);
#endif
  }
  return mpi_return;
}
