
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Accumulate
 */

#include <_mpi.h>

int
MPI_Accumulate (void *origin_addr, int origin_count, MPI_Datatype origin_datatype,int target_rank, MPI_Aint target_disp, int target_count,MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Accumulate")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Accumulate",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    api_use_ptrs *local_a2=active_ops->api_declared;
    api_use_ptrs *local_a3=active_wins->api_declared;
    int (*VendorMPI_Accumulate)(void *origin_addr,int origin_count,void *,int target_rank,MPI_Aint target_disp,int target_count,void *,void *,void *) = address;
    mpi_return = (*VendorMPI_Accumulate)(origin_addr,origin_count,local_a0[origin_datatype].mpi_const,target_rank,target_disp,target_count,local_a1[target_datatype].mpi_const,local_a2[op].mpi_const,local_a3[win].mpi_const);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    api_use_ints *local_a2=active_ops->api_declared;
    api_use_ints *local_a3=active_wins->api_declared;
    int (*VendorMPI_Accumulate)(void *origin_addr,int origin_count,int,int target_rank,MPI_Aint target_disp,int target_count,int,int,int) = address;
    mpi_return = (*VendorMPI_Accumulate)(origin_addr,origin_count,local_a0[origin_datatype].mpi_const,target_rank,target_disp,target_count,local_a1[target_datatype].mpi_const,local_a2[op].mpi_const,local_a3[win].mpi_const);
  }
  return mpi_return;
}
