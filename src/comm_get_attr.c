
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_get_attr
 */

#include <_mpi.h>

static int _isc_proc_null = MPI_PROC_NULL;

int
MPI_Comm_get_attr (MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a1 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_get_attr")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_get_attr",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
      int (*VendorMPI_Comm_get_attr)(void *,int ,void *, int *) = address;
      mpi_return = (*VendorMPI_Comm_get_attr)(local_a0[comm].mpi_const,local_a1[comm_keyval].mpi_const,attribute_val,flag);
  } else { api_use_ints *local_a0= active_comms->api_declared;
      int (*VendorMPI_Comm_get_attr)(int,int comm_keyval,void *attribute_val, int *flag) = address;
      mpi_return = (*VendorMPI_Comm_get_attr)(local_a0[comm].mpi_const,local_a1[comm_keyval].mpi_const,attribute_val,flag);
  }
  if (*flag) {
	  int *a_val = (int *)attribute_val;
	  if (*a_val == local_a1[ISC_PROC_NULL_].mpi_const) {
		  *a_val = local_a1[ISC_PROC_NULL_].self;
      }
  }
  return mpi_return;
}
