
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_write_at_all_begin
 */

#include <_mpi.h>

int
MPI_File_write_at_all_begin (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_write_at_all_begin")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_write_at_all_begin",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_File_write_at_all_begin)(void *,MPI_Offset offset,void *buf,int count,void *) = address;
    mpi_return = (*VendorMPI_File_write_at_all_begin)(local_a0[fh].mpi_const,offset,buf,count,local_a1[datatype].mpi_const);
  } else { api_use_ints *local_a0=active_files->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_File_write_at_all_begin)(int,MPI_Offset offset,void *buf,int count,int) = address;
    mpi_return = (*VendorMPI_File_write_at_all_begin)(local_a0[fh].mpi_const,offset,buf,count,local_a1[datatype].mpi_const);
  }
  return mpi_return;
}
