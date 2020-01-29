
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_info
 */

#include <_mpi.h>

int
MPI_File_get_info (MPI_File fh, MPI_Info *info_used)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_get_info")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_get_info",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  *info_used = new_index(active_infos);
  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    if (active_infos->use_ptrs) { api_use_ptrs *local_a1=active_infos->api_declared;
      int (*VendorMPI_File_get_info)(void *,void **) = address;
      mpi_return = (*VendorMPI_File_get_info)(local_a0[fh].mpi_const,&local_a1[*info_used].mpi_const);
    } else { api_use_ints *local_a1=active_infos->api_declared;
      int (*VendorMPI_File_get_info)(void *,int *) = address;
      mpi_return = (*VendorMPI_File_get_info)(local_a0[fh].mpi_const,&local_a1[*info_used].mpi_const);
    }
  } else { api_use_ints *local_a0=active_files->api_declared;
    if (active_infos->use_ptrs) { api_use_ptrs *local_a1=active_infos->api_declared;
      int (*VendorMPI_File_get_info)(int,void **) = address;
      mpi_return = (*VendorMPI_File_get_info)(local_a0[fh].mpi_const,&local_a1[*info_used].mpi_const);
    } else { api_use_ints *local_a1=active_infos->api_declared;
      int (*VendorMPI_File_get_info)(int,int *) = address;
      mpi_return = (*VendorMPI_File_get_info)(local_a0[fh].mpi_const,&local_a1[*info_used].mpi_const);
    }
  }
  return mpi_return;
}
