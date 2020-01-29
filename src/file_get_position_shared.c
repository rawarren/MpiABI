
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_position_shared
 */

#include <_mpi.h>

int
MPI_File_get_position_shared (MPI_File fh, MPI_Offset *offset)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_get_position_shared")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_get_position_shared",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    int (*VendorMPI_File_get_position_shared)(void *, MPI_Offset *offset) = address;
    mpi_return = (*VendorMPI_File_get_position_shared)(local_a0[fh].mpi_const,offset);
  } else { api_use_ints *local_a0=active_files->api_declared;
    int (*VendorMPI_File_get_position_shared)(int, MPI_Offset *offset) = address;
    mpi_return = (*VendorMPI_File_get_position_shared)(local_a0[fh].mpi_const,offset);
  }
  return mpi_return;
}
