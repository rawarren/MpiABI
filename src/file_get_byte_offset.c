
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_byte_offset
 */

#include <_mpi.h>

int
MPI_File_get_byte_offset (MPI_File fh, MPI_Offset offset, MPI_Offset *disp)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_get_byte_offset")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_get_byte_offset",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    int (*VendorMPI_File_get_byte_offset)(void *,MPI_Offset offset, MPI_Offset *disp) = address;
    mpi_return = (*VendorMPI_File_get_byte_offset)(local_a0[fh].mpi_const,offset,disp);
  } else { api_use_ints *local_a0=active_files->api_declared;
    int (*VendorMPI_File_get_byte_offset)(int,MPI_Offset offset, MPI_Offset *disp) = address;
    mpi_return = (*VendorMPI_File_get_byte_offset)(local_a0[fh].mpi_const,offset,disp);
  }
  return mpi_return;
}
