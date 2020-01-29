
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_amode
 */

#include <_mpi.h>

int
MPI_File_get_amode (MPI_File fh, int *amode)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_get_amode")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_get_amode",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    int (*VendorMPI_File_get_amode)(void *, int *amode) = address;
    mpi_return = (*VendorMPI_File_get_amode)(local_a0[fh].mpi_const,amode);
  } else { api_use_ints *local_a0=active_files->api_declared;
    int (*VendorMPI_File_get_amode)(int, int *amode) = address;
    mpi_return = (*VendorMPI_File_get_amode)(local_a0[fh].mpi_const,amode);
  }
  return mpi_return;
}
