
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_set_errhandler
 */

#include <_mpi.h>

int
MPI_File_set_errhandler ( MPI_File file, MPI_Errhandler errhandler)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_set_errhandler")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_set_errhandler",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    api_use_ptrs *local_a1=active_errhandlers->api_declared;
    int (*VendorMPI_File_set_errhandler)(void *,void *) = address;
    mpi_return = (*VendorMPI_File_set_errhandler)(local_a0[file].mpi_const,local_a1[errhandler].mpi_const);
  } else { api_use_ints *local_a0=active_files->api_declared;
    api_use_ints *local_a1=active_errhandlers->api_declared;
    int (*VendorMPI_File_set_errhandler)(int,int) = address;
    mpi_return = (*VendorMPI_File_set_errhandler)(local_a0[file].mpi_const,local_a1[errhandler].mpi_const);
  }
  return mpi_return;
}
