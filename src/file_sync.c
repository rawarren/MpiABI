
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_sync
 */

#include <_mpi.h>

int
MPI_File_sync (MPI_File fh)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_sync")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_sync",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    int (*VendorMPI_File_sync)(void *) = address;
    mpi_return = (*VendorMPI_File_sync)(local_a0[fh].mpi_const);
  } else { api_use_ints *local_a0=active_files->api_declared;
    int (*VendorMPI_File_sync)(int) = address;
    mpi_return = (*VendorMPI_File_sync)(local_a0[fh].mpi_const);
  }
  return mpi_return;
}
