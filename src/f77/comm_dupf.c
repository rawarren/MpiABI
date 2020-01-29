
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_dup
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_DUP() __attribute__ ((weak, alias("iscf_comm_dup")));
void mpi_comm_dup() __attribute__ ((weak, alias("iscf_comm_dup")));
void mpi_comm_dup_() __attribute__ ((weak, alias("iscf_comm_dup")));
void mpi_comm_dup__() __attribute__ ((weak, alias("iscf_comm_dup")));
#endif

void iscf_comm_dup(int *comm, int *newcomm, int *ierr)
{
    *ierr = MPI_Comm_dup (*comm, newcomm);
}
