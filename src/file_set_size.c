
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_set_size
 */

#include <_mpi.h>

int
MPI_File_set_size (MPI_File fh, MPI_Offset size)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_set_size")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_set_size",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    int (*VendorMPI_File_set_size)(void *, MPI_Offset size) = address;
    mpi_return = (*VendorMPI_File_set_size)(local_a0[fh].mpi_const,size);
  } else { api_use_ints *local_a0=active_files->api_declared;
    int (*VendorMPI_File_set_size)(int, MPI_Offset size) = address;
    mpi_return = (*VendorMPI_File_set_size)(local_a0[fh].mpi_const,size);
  }
  return mpi_return;
}
