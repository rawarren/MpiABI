
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_get_group
 */

#include <_mpi.h>

int
MPI_Win_get_group (MPI_Win win, MPI_Group *group)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_get_group")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_get_group",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    *group = new_index(active_groups);

    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
      if (active_groups->use_ptrs) { api_use_ptrs *local_a1=active_groups->api_declared;
        int (*VendorMPI_Win_get_group)(void *,void **) = address;
        mpi_return = (*VendorMPI_Win_get_group)(local_a0[win].mpi_const,&local_a1[*group].mpi_const);
      } else { api_use_ints *local_a1=active_groups->api_declared;
        int (*VendorMPI_Win_get_group)(void *,int *) = address;
        mpi_return = (*VendorMPI_Win_get_group)(local_a0[win].mpi_const,&local_a1[*group].mpi_const);
      }      
    } else { api_use_ints *local_a0=active_wins->api_declared;
      if (active_groups->use_ptrs) { api_use_ptrs *local_a1=active_groups->api_declared;
        int (*VendorMPI_Win_get_group)(int ,void **) = address;
        mpi_return = (*VendorMPI_Win_get_group)(local_a0[win].mpi_const,&local_a1[*group].mpi_const);
      } else { api_use_ints *local_a1=active_groups->api_declared;
        int (*VendorMPI_Win_get_group)(int ,int *) = address;
        mpi_return = (*VendorMPI_Win_get_group)(local_a0[win].mpi_const,&local_a1[*group].mpi_const);
      }      
    }
    return mpi_return;
}
