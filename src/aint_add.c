
#include <_mpi.h>

MPI_Aint
MPI_Aint_add(MPI_Aint base, MPI_Aint disp)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Aint_add")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Aint_add",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  MPI_Aint (*VendorMPI_Aint_add)(MPI_Aint,MPI_Aint) = address;
  return (*VendorMPI_Aint_add)(base,disp);
}

MPI_Aint
MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Aint_diff")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Aint_diff",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  MPI_Aint (*VendorMPI_Aint_diff)(MPI_Aint,MPI_Aint) = address;
  return (*VendorMPI_Aint_diff)(addr1,addr2);
}
