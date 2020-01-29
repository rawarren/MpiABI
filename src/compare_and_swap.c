
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Compare_and_swap
 */

#include <_mpi.h>

int
MPI_Compare_and_swap (void *origin_addr, void *compare_addr, void *result_addr, MPI_Datatype datatype,
		    int target_rank, MPI_Aint target_disp, MPI_Win win)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Compare_and_swap")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Compare_and_swap",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    api_use_ptrs *local_a3=active_wins->api_declared;
    int (*VendorMPI_Compare_and_swap)(void *origin_addr, void *compare_addr, void *result_addr, void *datatype,
				int target_rank, MPI_Aint target_disp, void *) = address;
    mpi_return = (*VendorMPI_Compare_and_swap)(origin_addr, compare_addr, result_addr,local_a0[datatype].mpi_const,
					     target_rank,target_disp, local_a3[win].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    api_use_ints *local_a3=active_wins->api_declared;
    int (*VendorMPI_Compare_and_swap)(void *origin_addr, void *compare_addr, void *result_addr, int result_datatype,
				int target_rank, MPI_Aint target_disp, int) = address;
    mpi_return = (*VendorMPI_Compare_and_swap)(origin_addr, compare_addr, result_addr,local_a0[datatype].mpi_const,
					     target_rank,target_disp, local_a3[win].mpi_const);

  }
  return mpi_return;
}
