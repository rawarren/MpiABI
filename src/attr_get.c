
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Attr_get
 */

#include <_mpi.h>

int
MPI_Attr_get (MPI_Comm comm, int keyval, void *attribute_val, int *flag)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a1 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Attr_get")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Attr_get",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    int (*VendorMPI_Attr_get)(void *,int keyval,void *attribute_val, int *flag) = address;
    mpi_return = (*VendorMPI_Attr_get)(local_a0[comm].mpi_const,local_a1[keyval].mpi_const,attribute_val,flag);
  } else { api_use_ints *local_a0= active_comms->api_declared;
    int (*VendorMPI_Attr_get)(int,int keyval,void *attribute_val, int *flag) = address;
    mpi_return = (*VendorMPI_Attr_get)(local_a0[comm].mpi_const,local_a1[keyval].mpi_const,attribute_val,flag);
  }

  /* We need to translate MPI_PROC_NULL when it get's returned */
  if (keyval == MPI_HOST) {
    int **vendor_val = attribute_val;
    if (*vendor_val[0] == local_a1[ISC_PROC_NULL_].mpi_const)
        *vendor_val[0] = MPI_PROC_NULL;
  }

  return mpi_return;
}
