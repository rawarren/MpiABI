
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_read_at
 */

#include <_mpi.h>

int
MPI_File_read_at (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
  static void *address=0;
  int mpi_return;
  int natstat[MAX_MPI_STATUS_SIZE] = {0,};

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_read_at")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_read_at",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_File_read_at)(void *,MPI_Offset offset,void *buf,int count,void *, MPI_Status *status) = address;
    mpi_return = (*VendorMPI_File_read_at)(local_a0[fh].mpi_const,offset,buf,count,local_a1[datatype].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,natstat,(int *)status);
  } else { api_use_ints *local_a0=active_files->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_File_read_at)(int,MPI_Offset offset,void *buf,int count,int, MPI_Status *status) = address;
    mpi_return = (*VendorMPI_File_read_at)(local_a0[fh].mpi_const,offset,buf,count,local_a1[datatype].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,natstat,(int *)status);
  }
  return mpi_return;
}
