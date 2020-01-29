
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_contents
 */

#include <_mpi.h>
#include <stdlib.h>

int
MPI_Type_get_contents (MPI_Datatype mtype, int max_integers, int max_addresses, int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Datatype array_of_datatypes[])
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_get_contents")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_get_contents",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int i,j;
    int (*VendorMPI_Type_get_contents)(void *,int max_integers,int max_addresses,int max_datatypes,int array_of_integers[],MPI_Aint array_of_addresses[],void **) = address;
    void *temp[64],**dtemp=0, **dfill;
    if (max_datatypes > 64)
      dfill = dtemp = (void **)calloc(max_addresses,sizeof(void **));
    else dfill = temp;
    mpi_return = (*VendorMPI_Type_get_contents)(local_a0[mtype].mpi_const,max_integers,max_addresses,max_datatypes,array_of_integers,array_of_addresses,dfill);

    /* Translate vendor datatype values to ISC indices */
    for(i=0; i<max_datatypes; i++) {
      for(j=0; j<active_datatypes->limit; j++) {
	if (local_a1[j].mpi_const == NULL) {
	  /* We haven't ever seen this datatype before!
	   * It appears that the implementation has made an
	   * an internal DUP of the orignal, so we'll record
	   * that duplicate here!
	   */
	  int newtype = new_index(active_datatypes);
	  array_of_datatypes[i] = newtype;
	  local_a1[newtype].mpi_const = dfill[i];
	  break;
	} else if (local_a1[j].mpi_const == dfill[i]) {
	  array_of_datatypes[i] = j; 
	  break;
	}
      }
    }

    if (dtemp) free(dtemp);

  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    api_use_ints *local_a1= active_datatypes->api_declared;
    int i,j;
    int (*VendorMPI_Type_get_contents)(int,int max_integers,int max_addresses,int max_datatypes,int array_of_integers[],MPI_Aint array_of_addresses[],int *) = address;
    int temp[64],*dtemp=0, *dfill;
    if (max_datatypes > 64)
      dfill = dtemp = (int *)calloc(max_addresses,sizeof(int));
    else dfill = temp;

    mpi_return = (*VendorMPI_Type_get_contents)(local_a0[mtype].mpi_const,max_integers,max_addresses,max_datatypes,array_of_integers,array_of_addresses,dfill);
    for(i=0; i<max_datatypes; i++) {
      for(j=0; j<active_datatypes->limit; j++) {
	if (local_a1[j].mpi_const == 0) {
	  int newtype = new_index(active_datatypes);
	  array_of_datatypes[i] = newtype;
	  local_a1[newtype].mpi_const = dfill[i];
	  break;
	} else if (local_a1[j].mpi_const == dfill[i]) {
	  array_of_datatypes[i] = j; 
	  break;
	}
      }
    }
    if (dtemp) free(dtemp);
  }
  return mpi_return;
}
