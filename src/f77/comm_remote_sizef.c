
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_remote_size
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_REMOTE_SIZE() __attribute__ ((weak, alias("iscf_comm_remote_size")));
void mpi_comm_remote_size() __attribute__ ((weak, alias("iscf_comm_remote_size")));
void mpi_comm_remote_size_() __attribute__ ((weak, alias("iscf_comm_remote_size")));
void mpi_comm_remote_size__() __attribute__ ((weak, alias("iscf_comm_remote_size")));
#endif

void iscf_comm_remote_size(int *comm, int *size, int *ierr)
{
    *ierr = MPI_Comm_remote_size (*comm, size);
}
