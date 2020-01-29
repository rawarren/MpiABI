
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_envelope
 */

#include <_mpi.h>

int
MPI_Type_get_envelope (MPI_Datatype type, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner)
{
  static void *address=0;
  int native_combiner=-1;
  api_use_ints *local_a1 = active_miscs->api_declared;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_get_envelope")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_get_envelope",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_envelope)(void *,int *num_integers,int *num_addresses,int *num_datatypes, int *combiner) = address;
    mpi_return = (*VendorMPI_Type_get_envelope)(local_a0[type].mpi_const,num_integers,num_addresses,num_datatypes,&native_combiner);
  } else { api_use_ints *local_a0 = active_datatypes->api_declared;
    int (*VendorMPI_Type_get_envelope)(int,int *num_integers,int *num_addresses,int *num_datatypes, int *combiner) = address;
    mpi_return = (*VendorMPI_Type_get_envelope)(local_a0[type].mpi_const,num_integers,num_addresses,num_datatypes,&native_combiner);
  }
  if (combiner) {
    if (native_combiner == local_a1[ISC_COMBINER_NAMED].mpi_const) {
        *combiner = MPI_COMBINER_NAMED;
    } else if (native_combiner == local_a1[ISC_COMBINER_DUP].mpi_const) {
        *combiner = MPI_COMBINER_DUP;
    } else if (native_combiner == local_a1[ISC_COMBINER_CONTIGUOUS].mpi_const) {
        *combiner = ISC_COMBINER_CONTIGUOUS;
    } else if (native_combiner == local_a1[ISC_COMBINER_VECTOR].mpi_const) {
        *combiner = MPI_COMBINER_VECTOR;
    } else if (native_combiner == local_a1[ISC_COMBINER_HVECTOR_INTEGER].mpi_const) {
        *combiner = MPI_COMBINER_HVECTOR_INTEGER;
    } else if (native_combiner == local_a1[ISC_COMBINER_HVECTOR].mpi_const) {
        *combiner = MPI_COMBINER_HVECTOR;
    } else if (native_combiner == local_a1[ISC_COMBINER_INDEXED].mpi_const) {
        *combiner = MPI_COMBINER_INDEXED;
    } else if (native_combiner == local_a1[ISC_COMBINER_HINDEXED_INTEGER].mpi_const) {
        *combiner = MPI_COMBINER_HINDEXED_INTEGER;
    } else if (native_combiner == local_a1[ISC_COMBINER_HINDEXED].mpi_const) {
        *combiner = MPI_COMBINER_HINDEXED;
    } else if (native_combiner == local_a1[ISC_COMBINER_INDEXED_BLOCK].mpi_const) {
        *combiner = MPI_COMBINER_INDEXED_BLOCK;
    } else if (native_combiner == local_a1[ISC_COMBINER_STRUCT_INTEGER].mpi_const) {
        *combiner = MPI_COMBINER_STRUCT_INTEGER;
    } else if (native_combiner == local_a1[ISC_COMBINER_STRUCT].mpi_const) {
        *combiner = MPI_COMBINER_STRUCT;
    } else if (native_combiner == local_a1[ISC_COMBINER_SUBARRAY].mpi_const) {
        *combiner = MPI_COMBINER_SUBARRAY;
    } else if (native_combiner == local_a1[ISC_COMBINER_DARRAY].mpi_const) {
        *combiner = MPI_COMBINER_DARRAY;
    } else if (native_combiner == local_a1[ISC_COMBINER_F90_REAL].mpi_const) {
        *combiner = MPI_COMBINER_F90_REAL;
    } else if (native_combiner == local_a1[ISC_COMBINER_F90_COMPLEX].mpi_const) {
        *combiner = MPI_COMBINER_F90_COMPLEX;
    } else if (native_combiner == local_a1[ISC_COMBINER_F90_INTEGER].mpi_const) {
        *combiner = MPI_COMBINER_F90_INTEGER;
    } else if (native_combiner == local_a1[ISC_COMBINER_RESIZED].mpi_const) {
        *combiner = MPI_COMBINER_RESIZED;
    }
  }
  return mpi_return;
}
