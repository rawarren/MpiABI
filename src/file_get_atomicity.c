
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_atomicity
 */

#include <_mpi.h>

int
MPI_File_get_atomicity (MPI_File fh, int *flag)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_get_atomicity")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_get_atomicity",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    int (*VendorMPI_File_get_atomicity)(void *, int *flag) = address;
    mpi_return = (*VendorMPI_File_get_atomicity)(local_a0[fh].mpi_const,flag);
  } else { api_use_ints *local_a0=active_files->api_declared;
    int (*VendorMPI_File_get_atomicity)(int, int *flag) = address;
    mpi_return = (*VendorMPI_File_get_atomicity)(local_a0[fh].mpi_const,flag);
  }
  return mpi_return;
}
