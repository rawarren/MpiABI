
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_set_info
 */

#include <_mpi.h>

int
MPI_Comm_set_info (MPI_Comm comm, MPI_Info info)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_Comm_set_info")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_set_info",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0=active_comms->api_declared;
    if (active_infos->use_ptrs) { api_use_ptrs *local_a1=active_infos->api_declared;
      int (*VendorMPI_Comm_set_info)(void *,void *) = address;
      mpi_return = (*VendorMPI_Comm_set_info)(local_a0[comm].mpi_const,local_a1[info].mpi_const);
    } else { api_use_ints *local_a1=active_infos->api_declared;
      int (*VendorMPI_Comm_set_info)(void *,int) = address;
      mpi_return = (*VendorMPI_Comm_set_info)(local_a0[comm].mpi_const,local_a1[info].mpi_const);
    }
  } else { api_use_ints *local_a0=active_comms->api_declared;
    if (active_infos->use_ptrs) { api_use_ptrs *local_a1=active_infos->api_declared;
      int (*VendorMPI_Comm_set_info)(int ,void *) = address;
      mpi_return = (*VendorMPI_Comm_set_info)(local_a0[comm].mpi_const,local_a1[info].mpi_const);
    } else { api_use_ints *local_a1=active_infos->api_declared;
      int (*VendorMPI_Comm_set_info)(int ,int) = address;
      mpi_return = (*VendorMPI_Comm_set_info)(local_a0[comm].mpi_const,local_a1[info].mpi_const);
    }
  }

  return mpi_return;
}
