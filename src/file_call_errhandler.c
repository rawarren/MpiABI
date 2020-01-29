
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_call_errhandler
 */

#include <_mpi.h>

int
MPI_File_call_errhandler (MPI_File fh, int errorcode)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_call_errhandler")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_call_errhandler",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    int (*VendorMPI_File_call_errhandler)(void *, int errorcode) = address;
    mpi_return = (*VendorMPI_File_call_errhandler)(local_a0[fh].mpi_const,errorcode);
  } else { api_use_ints *local_a0=active_files->api_declared;
    int (*VendorMPI_File_call_errhandler)(int, int errorcode) = address;
    mpi_return = (*VendorMPI_File_call_errhandler)(local_a0[fh].mpi_const,errorcode);
  }
  return mpi_return;
}
