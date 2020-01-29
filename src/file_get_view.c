
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_view
 */

#include <_mpi.h>

int
MPI_File_get_view (MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_File_get_view")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_File_get_view",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  *etype = new_index(active_datatypes);
  *filetype = new_index(active_datatypes);

  if (active_files->use_ptrs) { api_use_ptrs *local_a0=active_files->api_declared;
    if (active_datatypes->use_ptrs) {
      api_use_ptrs *local_a1= active_datatypes->api_declared;
      api_use_ptrs *local_a2= active_datatypes->api_declared;
      int (*VendorMPI_File_get_view)(void *,MPI_Offset *disp,void **,void **, char *datarep) = address;
      mpi_return = (*VendorMPI_File_get_view)(local_a0[fh].mpi_const,disp,&local_a1[*etype].mpi_const,&local_a2[*filetype].mpi_const,datarep);
    } else {
      api_use_ints *local_a1= active_datatypes->api_declared;
      api_use_ints *local_a2= active_datatypes->api_declared;
      int (*VendorMPI_File_get_view)(void *,MPI_Offset *disp,int *,int *, char *datarep) = address;
      mpi_return = (*VendorMPI_File_get_view)(local_a0[fh].mpi_const,disp,&local_a1[*etype].mpi_const,&local_a2[*filetype].mpi_const,datarep);
    }
  } else { api_use_ints *local_a0=active_files->api_declared;
    if (active_datatypes->use_ptrs) {
      api_use_ptrs *local_a1= active_datatypes->api_declared;
      api_use_ptrs *local_a2= active_datatypes->api_declared;
      int (*VendorMPI_File_get_view)(int,MPI_Offset *disp,void **,void **, char *datarep) = address;
      mpi_return = (*VendorMPI_File_get_view)(local_a0[fh].mpi_const,disp,&local_a1[*etype].mpi_const,&local_a2[*filetype].mpi_const,datarep);
    } else {
      api_use_ints *local_a1= active_datatypes->api_declared;
      api_use_ints *local_a2= active_datatypes->api_declared;
      int (*VendorMPI_File_get_view)(int,MPI_Offset *disp,int *,int *, char *datarep) = address;
      mpi_return = (*VendorMPI_File_get_view)(local_a0[fh].mpi_const,disp,&local_a1[*etype].mpi_const,&local_a2[*filetype].mpi_const,datarep);
    }
  }
  return mpi_return;
}
