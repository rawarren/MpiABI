
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Probe
 */

#include <_mpi.h>

int
MPI_Probe (int source, int tag, MPI_Comm comm, MPI_Status *status)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Probe")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Probe",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (active_comms->use_ptrs) {
    api_use_ptrs *local_a0= active_comms->api_declared;

    int (*VendorMPI_Probe)(int source,int tag,void *, MPI_Status *status) = address;
    mpi_return = (*VendorMPI_Probe)(ANYSRC(source),ANYTAG(tag),local_a0[comm].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,status->reserved,(int *)status);
  } else {
    api_use_ints *local_a0= active_comms->api_declared;

    int (*VendorMPI_Probe)(int source,int tag,int, MPI_Status *status) = address;
    mpi_return = (*VendorMPI_Probe)(ANYSRC(source),ANYTAG(tag),local_a0[comm].mpi_const,SIGNORE(status));
    if (status != MPI_STATUS_IGNORE) native_status_to_isc(1,status->reserved,(int *)status);
  }
  return mpi_return;
}
