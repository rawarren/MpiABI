
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_set_view
 */

#include <_mpi.h>

int
MPI_File_set_view (MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, char *datarep, MPI_Info info)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_set_view")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_set_view",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    if (active_datatypes->use_ptrs) {
      api_use_ptrs *local_a1= active_datatypes->api_declared;
      api_use_ptrs *local_a2= active_datatypes->api_declared;
      if (active_infos->use_ptrs) { api_use_ptrs *local_a3=active_infos->api_declared;
	int (*VendorMPI_File_set_view)(void *,MPI_Offset disp,void *,void *,char *datarep,void *) = address;
	mpi_return = (*VendorMPI_File_set_view)(local_a0[fh].mpi_const,disp,local_a1[etype].mpi_const,local_a2[filetype].mpi_const,datarep,local_a3[info].mpi_const);
      } else { api_use_ints *local_a3=active_infos->api_declared;
	int (*VendorMPI_File_set_view)(void *,MPI_Offset disp,void *,void *,char *datarep,int) = address;
	mpi_return = (*VendorMPI_File_set_view)(local_a0[fh].mpi_const,disp,local_a1[etype].mpi_const,local_a2[filetype].mpi_const,datarep,local_a3[info].mpi_const);
      }
    } else {
      api_use_ints *local_a1= active_datatypes->api_declared;
      api_use_ints *local_a2= active_datatypes->api_declared;
      if (active_infos->use_ptrs) { api_use_ptrs *local_a3=active_infos->api_declared;
	int (*VendorMPI_File_set_view)(void *,MPI_Offset disp,int ,int ,char *datarep,void *) = address;
	mpi_return = (*VendorMPI_File_set_view)(local_a0[fh].mpi_const,disp,local_a1[etype].mpi_const,local_a2[filetype].mpi_const,datarep,local_a3[info].mpi_const);
      } else { api_use_ints *local_a3=active_infos->api_declared;
	int (*VendorMPI_File_set_view)(void *,MPI_Offset disp,int ,int ,char *datarep,int) = address;
	mpi_return = (*VendorMPI_File_set_view)(local_a0[fh].mpi_const,disp,local_a1[etype].mpi_const,local_a2[filetype].mpi_const,datarep,local_a3[info].mpi_const);
      }
    }
  } else { api_use_ints *local_a0=active_files->api_declared;
    if (active_datatypes->use_ptrs) {
      api_use_ptrs *local_a1= active_datatypes->api_declared;
      api_use_ptrs *local_a2= active_datatypes->api_declared;
      if (active_infos->use_ptrs) { api_use_ptrs *local_a3=active_infos->api_declared;
	int (*VendorMPI_File_set_view)(int,MPI_Offset disp,void *,void *,char *datarep,void *) = address;
	mpi_return = (*VendorMPI_File_set_view)(local_a0[fh].mpi_const,disp,local_a1[etype].mpi_const,local_a2[filetype].mpi_const,datarep,local_a3[info].mpi_const);
      } else { api_use_ints *local_a3=active_infos->api_declared;
	int (*VendorMPI_File_set_view)(int,MPI_Offset disp,void *,void *,char *datarep,int) = address;
	mpi_return = (*VendorMPI_File_set_view)(local_a0[fh].mpi_const,disp,local_a1[etype].mpi_const,local_a2[filetype].mpi_const,datarep,local_a3[info].mpi_const);
      }
    } else {
      api_use_ints *local_a1= active_datatypes->api_declared;
      api_use_ints *local_a2= active_datatypes->api_declared;
      if (active_infos->use_ptrs) { api_use_ptrs *local_a3=active_infos->api_declared;
	int (*VendorMPI_File_set_view)(int ,MPI_Offset disp,int ,int ,char *datarep,void *) = address;
	mpi_return = (*VendorMPI_File_set_view)(local_a0[fh].mpi_const,disp,local_a1[etype].mpi_const,local_a2[filetype].mpi_const,datarep,local_a3[info].mpi_const);
      } else { api_use_ints *local_a3=active_infos->api_declared;
	int (*VendorMPI_File_set_view)(int ,MPI_Offset disp,int ,int ,char *datarep,int) = address;
	mpi_return = (*VendorMPI_File_set_view)(local_a0[fh].mpi_const,disp,local_a1[etype].mpi_const,local_a2[filetype].mpi_const,datarep,local_a3[info].mpi_const);
      }
    }
  }
  return mpi_return;
}
