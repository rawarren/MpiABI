
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_translate_ranks
 */

#include <_mpi.h>

int
MPI_Group_translate_ranks (MPI_Group group1, int n, int *ranks1, MPI_Group group2, int *ranks2)
{
  static void *address=0;
  api_use_ints *local_a2=active_miscs->api_declared;
  int i, mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Group_translate_ranks")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Group_translate_ranks",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_groups->use_ptrs) { 
    api_use_ptrs *local_a0=active_groups->api_declared;
    api_use_ptrs *local_a1=active_groups->api_declared;
    int (*VendorMPI_Group_translate_ranks)(void *,int n,int *ranks1,void *, int *ranks2) = address;
    mpi_return = (*VendorMPI_Group_translate_ranks)(local_a0[group1].mpi_const,n,ranks1,local_a1[group2].mpi_const,ranks2);
  } else { 
    api_use_ints *local_a0=active_groups->api_declared;
    api_use_ints *local_a1=active_groups->api_declared;
    int (*VendorMPI_Group_translate_ranks)(int,int n,int *ranks1,int, int *ranks2) = address;
    mpi_return = (*VendorMPI_Group_translate_ranks)(local_a0[group1].mpi_const,n,ranks1,local_a1[group2].mpi_const,ranks2);
  }

  if (mpi_return == 0) {
     for (i=0; i<n; i++) {
	if (ranks2[i] == local_a2[ISC_UNDEFINED_].mpi_const)
	    ranks2[i] = MPI_UNDEFINED;
     }
  }
  return mpi_return;
}
