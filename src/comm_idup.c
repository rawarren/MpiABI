
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_dup
 */

#include <_mpi.h>

int
MPI_Comm_idup (MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_idup")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_dup",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *request = new_index(active_requests);
  *newcomm = new_index(active_comms);
  remove_object_keyval_callbacks(*newcomm,-1,COMM_CALLBACK);

  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a2=active_requests->api_declared;
	int (*VendorMPI_Comm_idup)(void *,void **, void **) = address;
	mpi_return = (*VendorMPI_Comm_idup)(local_a0[comm].mpi_const,&local_a1[*newcomm].mpi_const,&local_a2[*request].mpi_const);
    }
    else { api_use_ints *local_a2=active_requests->api_declared;
	int (*VendorMPI_Comm_idup)(void *,void **, int*) = address;
	mpi_return = (*VendorMPI_Comm_idup)(local_a0[comm].mpi_const,&local_a1[*newcomm].mpi_const,&local_a2[*request].mpi_const);	
    }
    if (local_a1[*newcomm].mpi_const == local_a1[MPI_COMM_NULL].mpi_const) {
	free_index(active_comms,*newcomm);
	*newcomm = MPI_COMM_NULL;
	return mpi_return;
    }

  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    if (active_requests->use_ptrs) { api_use_ptrs *local_a2=active_requests->api_declared;
	int (*VendorMPI_Comm_idup)(int ,int *, void **) = address;
	mpi_return = (*VendorMPI_Comm_idup)(local_a0[comm].mpi_const,&local_a1[*newcomm].mpi_const,&local_a2[*request].mpi_const);
    }
    else { api_use_ints *local_a2=active_requests->api_declared;
	int (*VendorMPI_Comm_idup)(int,int *, int *) = address;
	mpi_return = (*VendorMPI_Comm_idup)(local_a0[comm].mpi_const,&local_a1[*newcomm].mpi_const,&local_a2[*request].mpi_const);
    }
    if (local_a1[*newcomm].mpi_const == local_a1[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }
  }
  maybe_dup_internal_reference(-1,comm,*newcomm,COMM_CALLBACK);

  return mpi_return;
}
