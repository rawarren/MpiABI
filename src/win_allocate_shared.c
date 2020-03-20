
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_allocate_shared
 */

#include <_mpi.h>

int
MPI_Win_allocate_shared (MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_allocate_shared")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_allocate_shared",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    *win = new_index(active_wins);
    if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
      if (active_comms->use_ptrs) { api_use_ptrs *local_a1= active_comms->api_declared;
	if (active_wins->use_ptrs) { api_use_ptrs *local_a2=active_wins->api_declared;
	  int (*VendorMPI_Win_allocate_shared)(MPI_Aint size,int disp_unit,void *,void *,void *baseptr,void **) = address;
	  mpi_return = (*VendorMPI_Win_allocate_shared)(size,disp_unit,local_a0[info].mpi_const,local_a1[comm].mpi_const,BOTTOM(baseptr),&local_a2[*win].mpi_const);
	} else { api_use_ints *local_a2=active_wins->api_declared;
	  int (*VendorMPI_Win_allocate_shared)(MPI_Aint size,int disp_unit,void *,void *,void *baseptr,int *) = address;
	  mpi_return = (*VendorMPI_Win_allocate_shared)(size,disp_unit,local_a0[info].mpi_const,local_a1[comm].mpi_const,BOTTOM(baseptr),&local_a2[*win].mpi_const);
	}
      } else {api_use_ints *local_a1= active_comms->api_declared;
	if (active_wins->use_ptrs) { api_use_ptrs *local_a2=active_wins->api_declared;
          int (*VendorMPI_Win_allocate_shared)(MPI_Aint size,int disp_unit,void *,int, void *baseptr,void **) = address;
	  mpi_return = (*VendorMPI_Win_allocate_shared)(size,disp_unit,local_a0[info].mpi_const,local_a1[comm].mpi_const,BOTTOM(baseptr),&local_a2[*win].mpi_const);
	} else { api_use_ints *local_a2=active_wins->api_declared;
          int (*VendorMPI_Win_allocate_shared)(MPI_Aint size,int disp_unit,void *,int, void *baseptr,int *) = address;
	  mpi_return = (*VendorMPI_Win_allocate_shared)(size,disp_unit,local_a0[info].mpi_const,local_a1[comm].mpi_const,BOTTOM(baseptr),&local_a2[*win].mpi_const);
	}
      }
    } else { api_use_ints *local_a0=active_infos->api_declared;
      if (active_comms->use_ptrs) { api_use_ptrs *local_a1= active_comms->api_declared;
	if (active_wins->use_ptrs) { api_use_ptrs *local_a2=active_wins->api_declared;
	  int (*VendorMPI_Win_allocate_shared)(MPI_Aint size,int disp_unit,int,void *,void *baseptr,void **) = address;
	  mpi_return = (*VendorMPI_Win_allocate_shared)(size,disp_unit,local_a0[info].mpi_const,local_a1[comm].mpi_const,BOTTOM(baseptr),&local_a2[*win].mpi_const);
	} else { api_use_ints *local_a2=active_wins->api_declared;
	  int (*VendorMPI_Win_allocate_shared)(MPI_Aint size,int disp_unit,int,void *,void *baseptr,int *) = address;
	  mpi_return = (*VendorMPI_Win_allocate_shared)(size,disp_unit,local_a0[info].mpi_const,local_a1[comm].mpi_const,BOTTOM(baseptr),&local_a2[*win].mpi_const);
	}
      } else {api_use_ints *local_a1= active_comms->api_declared;
	if (active_wins->use_ptrs) { api_use_ptrs *local_a2=active_wins->api_declared;
	  int (*VendorMPI_Win_allocate_shared)(MPI_Aint size,int disp_unit,int,int, void *baseptr,void **) = address;
	  mpi_return = (*VendorMPI_Win_allocate_shared)(size,disp_unit,local_a0[info].mpi_const,local_a1[comm].mpi_const,BOTTOM(baseptr),&local_a2[*win].mpi_const);
	} else { api_use_ints *local_a2=active_wins->api_declared;
	  int (*VendorMPI_Win_allocate_shared)(MPI_Aint size,int disp_unit,int,int,void *baseptr,int *) = address;
	  mpi_return = (*VendorMPI_Win_allocate_shared)(size,disp_unit,local_a0[info].mpi_const,local_a1[comm].mpi_const,BOTTOM(baseptr),&local_a2[*win].mpi_const);
	}
      }

    }
    return mpi_return;
}
