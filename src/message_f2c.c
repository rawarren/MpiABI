
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_f2c
 */

#include <_mpi.h>

MPI_Message
MPI_Message_f2c (MPI_Fint msg)
{
#if 1
  return (MPI_Message) msg;
#else
  static void *address=0;
  MPI_Message mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Message_f2c")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Message_f2c",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  MPI_Message (*VendorMPI_Message_f2c) (MPI_Fint msg) = address;
  mpi_return = (*VendorMPI_Message_f2c)(msg);
  return mpi_return;
#endif
}
