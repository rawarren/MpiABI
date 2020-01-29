
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Info_get
 */

#include <_mpi.h>

int
MPI_Info_get (MPI_Info info, char *key, int valuelen, char *value, int *flag)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Info_get")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Info_get",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_get)(void *,char *key,int valuelen,char *value, int *flag) = address;
    mpi_return = (*VendorMPI_Info_get)(local_a0[info].mpi_const,key,valuelen,value,flag);
  } else { api_use_ints *local_a0=active_infos->api_declared;
    int (*VendorMPI_Info_get)(int,char *key,int valuelen,char *value, int *flag) = address;
    mpi_return = (*VendorMPI_Info_get)(local_a0[info].mpi_const,key,valuelen,value,flag);
  }
  return mpi_return;
}
