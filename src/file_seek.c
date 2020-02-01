
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_seek
 */

#include <_mpi.h>

int
MPI_File_seek (MPI_File fh, MPI_Offset offset, int whence)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a1 = active_miscs->api_declared;
  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_seek")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_seek",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    int (*VendorMPI_File_seek)(void *,MPI_Offset offset, int whence) = address;
    mpi_return = (*VendorMPI_File_seek)(local_a0[fh].mpi_const,offset,local_a1[whence].mpi_const);
  } else { api_use_ints *local_a0=active_files->api_declared;
    int (*VendorMPI_File_seek)(int,MPI_Offset offset, int whence) = address;
    mpi_return = (*VendorMPI_File_seek)(local_a0[fh].mpi_const,offset,local_a1[whence].mpi_const);
  }
  return mpi_return;
}
