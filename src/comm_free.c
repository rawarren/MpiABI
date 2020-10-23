
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_free
 */

#include <_mpi.h>

int
MPI_Comm_free (MPI_Comm *comm)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
	  if ((address = dlsym(MPI_libhandle,"MPI_Comm_free")) == NULL) {
		  printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_free",SYM_MISSING_TRAILER);
		  return -1;
	  }
  }
  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
	  int (*VendorMPI_Comm_free)(void **) = address;
	  void *native_comm = local_a0[*comm].mpi_const;
	  mpi_return = (*VendorMPI_Comm_free)(&native_comm);
	  if (native_comm == local_a0[ISC_COMM_NULL].mpi_const) {
		  // if(*comm >= active_comms->permlimit) free_index(active_comms,*comm);
		  free_index(active_comms,*comm);
		  *comm = MPI_COMM_NULL;
	  }
  } else { api_use_ints *local_a0= active_comms->api_declared;
	  int (*VendorMPI_Comm_free)(int *) = address;
	  int native_comm = local_a0[*comm].mpi_const;
	  mpi_return = (*VendorMPI_Comm_free)(&native_comm);
	  if (native_comm == local_a0[ISC_COMM_NULL].mpi_const) {
		  // if(*comm >= active_comms->permlimit) free_index(active_comms,*comm);
		  free_index(active_comms,*comm);
		  *comm = MPI_COMM_NULL;
	  }
  }
  return mpi_return;
}
