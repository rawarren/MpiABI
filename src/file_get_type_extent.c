
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_type_extent
 */

#include <_mpi.h>

int
MPI_File_get_type_extent (MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_get_type_extent")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_get_type_extent",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_File_get_type_extent)(void *,void *, MPI_Aint *extent) = address;
    mpi_return = (*VendorMPI_File_get_type_extent)(local_a0[fh].mpi_const,local_a1[datatype].mpi_const,extent);
  } else { api_use_ints *local_a0=active_files->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_File_get_type_extent)(int,int, MPI_Aint *extent) = address;
    mpi_return = (*VendorMPI_File_get_type_extent)(local_a0[fh].mpi_const,local_a1[datatype].mpi_const,extent);
  }
  return mpi_return;
}
