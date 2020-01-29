
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_darray
 */

#include <_mpi.h>

int
MPI_Type_create_darray (int size, int rank, int ndims, int gsize_array[], int distrib_array[], int darg_array[], int psize_array[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
  static void *address=0;
  int mpi_return;
  api_use_ints *local_a0 = active_miscs->api_declared;
  int *native_distrib_array = (int *)calloc(ndims,sizeof(int));
  int *native_darg_array = (int *)calloc(ndims, sizeof(int));
  int native_order;
  int i;

  if (!address) {
    if ((address = dlsym(MPIO_libhandle,"MPI_Type_create_darray")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_create_darray",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newtype = new_index(active_datatypes);
  for(i=0; i < ndims; i++) {
    if (distrib_array[i] == ISC_DISTRIBUTE_BLOCK)
      native_distrib_array[i] = local_a0[ISC_DISTRIBUTE_BLOCK].mpi_const;
    else if (distrib_array[i] == ISC_DISTRIBUTE_CYCLIC)
      native_distrib_array[i] = local_a0[ISC_DISTRIBUTE_CYCLIC].mpi_const;
    else if (distrib_array[i] == ISC_DISTRIBUTE_NONE)
      native_distrib_array[i] = local_a0[ISC_DISTRIBUTE_NONE].mpi_const;
    else native_distrib_array[i] = distrib_array[i];

    if (darg_array[i] == ISC_DISTRIBUTE_DFLT_DARG)
      native_darg_array[i] = local_a0[ISC_DISTRIBUTE_DFLT_DARG].mpi_const;
    else native_darg_array[i] = darg_array[i];
  }
  native_order = (order == ISC_ORDER_C ? local_a0[ISC_ORDER_C].mpi_const : 
		  order == ISC_ORDER_FORTRAN ? local_a0[ISC_ORDER_FORTRAN].mpi_const : order);
  
  if (active_datatypes->use_ptrs) { 
    api_use_ptrs *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_create_darray)(int size,int rank,int ndims,int gsize_array[],int distrib_array[],int darg_array[],int psize_array[],int order,void *,void **) = address;
    mpi_return = (*VendorMPI_Type_create_darray)(size,rank,ndims,gsize_array,native_distrib_array,native_darg_array,psize_array,native_order,local_a1[oldtype].mpi_const,&local_a1[*newtype].mpi_const);
  } else { 
    api_use_ints *local_a1= active_datatypes->api_declared;
    int (*VendorMPI_Type_create_darray)(int size,int rank,int ndims,int gsize_array[],int distrib_array[],int darg_array[],int psize_array[],int order,int,int *) = address;
    mpi_return = (*VendorMPI_Type_create_darray)(size,rank,ndims,gsize_array,native_distrib_array,native_darg_array,psize_array,native_order,local_a1[oldtype].mpi_const,&local_a1[*newtype].mpi_const);
  }
  if (native_distrib_array) free(native_distrib_array);
  return mpi_return;
}
