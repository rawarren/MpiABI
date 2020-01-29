
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_free
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_FREE() __attribute__ ((weak, alias("iscf_comm_free")));
void mpi_comm_free() __attribute__ ((weak, alias("iscf_comm_free")));
void mpi_comm_free_() __attribute__ ((weak, alias("iscf_comm_free")));
void mpi_comm_free__() __attribute__ ((weak, alias("iscf_comm_free")));
#endif

void iscf_comm_free(int *comm, int *ierr)
{
    *ierr = MPI_Comm_free (comm);
}
