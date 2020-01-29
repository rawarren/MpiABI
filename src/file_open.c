
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_open
 */

#include <_mpi.h>

int
MPI_File_open (MPI_Comm comm, char *filename, int amode, MPI_Info info, MPI_File *fh)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a3=active_amodebitfield->api_declared;
  int native_amode=0;
  /* OR'd access modes need to be dealt with by hand... */
  if (amode & ISC_MODE_CREATE)
    native_amode = local_a3[ISC_MODE_CREATE_].mpi_const;
  if (amode & ISC_MODE_RDONLY) 
    native_amode |= local_a3[ISC_MODE_RDONLY_].mpi_const;
  if (amode & ISC_MODE_WRONLY)
    native_amode |= local_a3[ISC_MODE_WRONLY_].mpi_const;
  if (amode & ISC_MODE_RDWR)
    native_amode |= local_a3[ISC_MODE_RDWR_].mpi_const;
  if (amode & ISC_MODE_DELETE_ON_CLOSE)
    native_amode |= local_a3[ISC_MODE_DELETE_ON_CLOSE_].mpi_const;
  if (amode & ISC_MODE_UNIQUE_OPEN)
    native_amode |= local_a3[ISC_MODE_UNIQUE_OPEN_].mpi_const;
  if (amode & ISC_MODE_EXCL)
    native_amode |= local_a3[ISC_MODE_EXCL_].mpi_const;
  if (amode & ISC_MODE_APPEND)
    native_amode |= local_a3[ISC_MODE_APPEND_].mpi_const;
  if (amode & ISC_MODE_SEQUENTIAL)
    native_amode |= local_a3[ISC_MODE_SEQUENTIAL_].mpi_const;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_open")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_open",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  *fh = new_index(active_files);
  
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    if (active_infos->use_ptrs) { api_use_ptrs *local_a1=active_infos->api_declared;
      if (active_files->use_ptrs) { api_use_ptrs *local_a2=active_files->api_declared;
	int (*VendorMPI_File_open)(void *,char *filename,int native_amode,void *,void **) = address;
	mpi_return = (*VendorMPI_File_open)(local_a0[comm].mpi_const,filename,native_amode,local_a1[info].mpi_const,&local_a2[*fh].mpi_const);
      } else { api_use_ints *local_a2=active_files->api_declared;
	int (*VendorMPI_File_open)(void *,char *filename,int native_amode,void *,int *) = address;
	mpi_return = (*VendorMPI_File_open)(local_a0[comm].mpi_const,filename,native_amode,local_a1[info].mpi_const,&local_a2[*fh].mpi_const);
      }
    } else { api_use_ints *local_a1=active_infos->api_declared;
      if (active_files->use_ptrs) { api_use_ptrs *local_a2=active_files->api_declared;
	int (*VendorMPI_File_open)(void *,char *filename,int native_amode,int,void **) = address;
	mpi_return = (*VendorMPI_File_open)(local_a0[comm].mpi_const,filename,native_amode,local_a1[info].mpi_const,&local_a2[*fh].mpi_const);
      } else { api_use_ints *local_a2=active_files->api_declared;
	int (*VendorMPI_File_open)(void *,char *filename,int native_amode,int,int *) = address;
	mpi_return = (*VendorMPI_File_open)(local_a0[comm].mpi_const,filename,native_amode,local_a1[info].mpi_const,&local_a2[*fh].mpi_const);
      }
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    if (active_infos->use_ptrs) { api_use_ptrs *local_a1=active_infos->api_declared;
      if (active_files->use_ptrs) { api_use_ptrs *local_a2=active_files->api_declared;
	int (*VendorMPI_File_open)(int ,char *filename,int native_amode,void *,void **) = address;
	mpi_return = (*VendorMPI_File_open)(local_a0[comm].mpi_const,filename,native_amode,local_a1[info].mpi_const,&local_a2[*fh].mpi_const);
      } else { api_use_ints *local_a2=active_files->api_declared;
	int (*VendorMPI_File_open)(int ,char *filename,int native_amode,void *,int *) = address;
	mpi_return = (*VendorMPI_File_open)(local_a0[comm].mpi_const,filename,native_amode,local_a1[info].mpi_const,&local_a2[*fh].mpi_const);
      }
    } else { api_use_ints *local_a1=active_infos->api_declared;
      if (active_files->use_ptrs) { api_use_ptrs *local_a2=active_files->api_declared;
	int (*VendorMPI_File_open)(int ,char *filename,int native_amode,int,void **) = address;
	mpi_return = (*VendorMPI_File_open)(local_a0[comm].mpi_const,filename,native_amode,local_a1[info].mpi_const,&local_a2[*fh].mpi_const);
      } else { api_use_ints *local_a2=active_files->api_declared;
	int (*VendorMPI_File_open)(int ,char *filename,int native_amode,int,int *) = address;
	mpi_return = (*VendorMPI_File_open)(local_a0[comm].mpi_const,filename,native_amode,local_a1[info].mpi_const,&local_a2[*fh].mpi_const);
      }
    }
  }

  if (mpi_return != 0) {
    free_index(active_files, *fh);
    *fh = MPI_FILE_NULL;
  }
  return mpi_return;
}
