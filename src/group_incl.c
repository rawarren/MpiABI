
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_incl
 */

#include <_mpi.h>

int
MPI_Group_incl (MPI_Group group, int n, int *ranks, MPI_Group *newgroup)
{
  static void *address=0;
  int mpi_return = MPI_SUCCESS;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Group_incl")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Group_incl",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newgroup = new_index(active_groups);
  if (active_groups->use_ptrs) { api_use_ptrs *local_a0=active_groups->api_declared;
      api_use_ptrs *local_a1=active_groups->api_declared;
      void *natvalue = NULL;
      int (*VendorMPI_Group_incl)(void *,int n,int *ranks,void **) = address;
      mpi_return = (*VendorMPI_Group_incl)(local_a0[group].mpi_const,n,ranks,&natvalue);
      if (natvalue == local_a1[MPI_GROUP_NULL].mpi_const) {
	  free_index(active_groups,*newgroup);
	  *newgroup = ISC_GROUP_NULL;
      }
      else local_a0[*newgroup].mpi_const = natvalue;
  }
  else { api_use_ints *local_a0=active_groups->api_declared;
      api_use_ints *local_a1=active_groups->api_declared;
      int natvalue = 0;
      int (*VendorMPI_Group_incl)(int,int n,int *ranks,int *) = address;
      mpi_return = (*VendorMPI_Group_incl)(local_a0[group].mpi_const,n,ranks,&natvalue);
      if (natvalue == local_a0[MPI_GROUP_NULL].mpi_const) {
	  free_index(active_groups,*newgroup);
	  *newgroup = ISC_GROUP_NULL;
      }
      else local_a0[*newgroup].mpi_const = natvalue;
  }
  return mpi_return;
}
