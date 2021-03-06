
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_delete
 */

#include <_mpi.h>

int
MPI_File_delete (char *filename, MPI_Info info)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_delete")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_delete",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int (*VendorMPI_File_delete)(char *filename,void *) = address;
    mpi_return = (*VendorMPI_File_delete)(filename,local_a0[info].mpi_const);
  } else { api_use_ints *local_a0=active_infos->api_declared;
    int (*VendorMPI_File_delete)(char *filename,int) = address;
    mpi_return = (*VendorMPI_File_delete)(filename,local_a0[info].mpi_const);
  }
  return mpi_return;
}
