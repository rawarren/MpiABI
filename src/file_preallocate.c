
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_preallocate
 */

#include <_mpi.h>

int
MPI_File_preallocate (MPI_File fh, MPI_Offset size)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_preallocate")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_preallocate",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    int (*VendorMPI_File_preallocate)(void *, MPI_Offset size) = address;
    mpi_return = (*VendorMPI_File_preallocate)(local_a0[fh].mpi_const,size);
  } else { api_use_ints *local_a0=active_files->api_declared;
    int (*VendorMPI_File_preallocate)(int, MPI_Offset size) = address;
    mpi_return = (*VendorMPI_File_preallocate)(local_a0[fh].mpi_const,size);
  }
  return mpi_return;
}
