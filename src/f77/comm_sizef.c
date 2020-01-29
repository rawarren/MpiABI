
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_size
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_SIZE() __attribute__ ((weak, alias("iscf_comm_size")));
void mpi_comm_size() __attribute__ ((weak, alias("iscf_comm_size")));
void mpi_comm_size_() __attribute__ ((weak, alias("iscf_comm_size")));
void mpi_comm_size__() __attribute__ ((weak, alias("iscf_comm_size")));
#endif

void iscf_comm_size(int *comm, int *size, int *ierr)
{
    *ierr = MPI_Comm_size (*comm, size);
}
