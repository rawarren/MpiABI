
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_struct
 */

#include <_mpi.h>
#include <stdlib.h>

int
MPI_Type_struct (int count, int array_of_block_lengths[], MPI_Aint array_of_displacements[], MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_struct")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_struct",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newtype = new_index(active_datatypes);
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int i;
    int (*VendorMPI_Type_struct)(int count,int array_of_block_lengths[],MPI_Aint array_of_displacements[],void **,void **) = address;
    void *temp[64],**dtemp=0, **dfill;
    if (count > 64)
      dfill = dtemp = (void *)calloc(count,sizeof(void *));
    else dfill = temp;

    for(i=0; i<count; i++)
      dfill[i] = local_a0[array_of_types[i]].mpi_const;

    mpi_return = (*VendorMPI_Type_struct)(count,array_of_block_lengths,array_of_displacements,dfill,&local_a1[*newtype].mpi_const);
    if (dtemp) free(dtemp);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int i;
    int (*VendorMPI_Type_struct)(int count,int array_of_block_lengths[],MPI_Aint array_of_displacements[],int *,int *) = address;
    int temp[64],*dtemp=0, *dfill;
    if (count > 64)
      dfill = dtemp = (int *)calloc(count,sizeof(int));
    else dfill = temp;

    for(i=0; i<count; i++)
      dfill[i] = local_a0[array_of_types[i]].mpi_const;

    mpi_return = (*VendorMPI_Type_struct)(count,array_of_block_lengths,array_of_displacements,dfill,&local_a1[*newtype].mpi_const);
    if (dtemp) free(dtemp);
  }
  return mpi_return;
}
