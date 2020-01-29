
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_close
 */

#include <_mpi.h>

int
MPI_File_close (MPI_File *fh)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_close")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_close",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    int (*VendorMPI_File_close)(void **) = address;
    mpi_return = (*VendorMPI_File_close)(&local_a0[*fh].mpi_const);
    if (local_a0[*fh].mpi_const == local_a0[MPI_FILE_NULL].mpi_const) {
      free_index(active_files,*fh);
      *fh = MPI_FILE_NULL;
    }
  } else { api_use_ints *local_a0=active_files->api_declared;
    int (*VendorMPI_File_close)(int *) = address;
    mpi_return = (*VendorMPI_File_close)(&local_a0[*fh].mpi_const);
    if (local_a0[*fh].mpi_const == local_a0[MPI_FILE_NULL].mpi_const) {
      free_index(active_files,*fh);
      *fh = MPI_FILE_NULL;
    }
  }
  return mpi_return;
}
