
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_iread_at_all
 */

#include <_mpi.h>

int
MPI_File_iread_at_all (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_iread_at_all")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_iread_at_all",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *request = new_index(active_requests);
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a2=active_requests->api_declared;
      int (*VendorMPI_File_iread_at_all)(void *,MPI_Offset offset,void *buf,int count,void *,void **) = address;
      mpi_return = (*VendorMPI_File_iread_at_all)(local_a0[fh].mpi_const,offset,buf,count,local_a1[datatype].mpi_const,&local_a2[*request].mpi_const);
    } else { api_use_ints *local_a2=active_requests->api_declared;
      int (*VendorMPI_File_iread_at_all)(void *,MPI_Offset offset,void *buf,int count,void *,int *) = address;
      mpi_return = (*VendorMPI_File_iread_at_all)(local_a0[fh].mpi_const,offset,buf,count,local_a1[datatype].mpi_const,&local_a2[*request].mpi_const);
    }
  } else { api_use_ints *local_a0=active_files->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a2=active_requests->api_declared;
      int (*VendorMPI_File_iread_at_all)(int,MPI_Offset offset,void *buf,int count,int,void **) = address;
      mpi_return = (*VendorMPI_File_iread_at_all)(local_a0[fh].mpi_const,offset,buf,count,local_a1[datatype].mpi_const,&local_a2[*request].mpi_const);
    } else { api_use_ints *local_a2=active_requests->api_declared;
      int (*VendorMPI_File_iread_at_all)(int,MPI_Offset offset,void *buf,int count,int,int *) = address;
      mpi_return = (*VendorMPI_File_iread_at_all)(local_a0[fh].mpi_const,offset,buf,count,local_a1[datatype].mpi_const,&local_a2[*request].mpi_const);
    }
  }
  return mpi_return;

}
