
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Open_port
 */

#include <_mpi.h>

int
MPI_Open_port (MPI_Info info, char *port_name)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Open_port")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Open_port",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int (*VendorMPI_Open_port)(void *, char *port_name) = address;
    mpi_return = (*VendorMPI_Open_port)(local_a0[info].mpi_const,port_name);
  } else { api_use_ints *local_a0=active_infos->api_declared;
    int (*VendorMPI_Open_port)(int, char *port_name) = address;
    mpi_return = (*VendorMPI_Open_port)(local_a0[info].mpi_const,port_name);
  }
  return mpi_return;
}
