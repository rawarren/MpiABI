
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_read
 */

#include <_mpi.h>

int
MPI_File_read (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
  static void *address=0;
  int mpi_return;
  int natstat[MAX_MPI_STATUS_SIZE] = {0,};

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_read")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_read",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_File_read)(void *,void *buf,int count,void *, MPI_Status *status) = address;
    mpi_return = (*VendorMPI_File_read)(local_a0[fh].mpi_const,buf,count,local_a1[datatype].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,natstat,(int *)status);
  } else { api_use_ints *local_a0=active_files->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_File_read)(int,void *buf,int count,int, MPI_Status *status) = address;
    mpi_return = (*VendorMPI_File_read)(local_a0[fh].mpi_const,buf,count,local_a1[datatype].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,natstat,(int *)status);
  }
  return mpi_return;
}
