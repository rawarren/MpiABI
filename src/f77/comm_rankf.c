
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_rank
 */

#include <_mpi.h>

#ifdef __GNUC__
/*
void MPI_COMM_RANK() __attribute__ ((weak, alias("iscf_comm_rank")));
void mpi_comm_rank() __attribute__ ((weak, alias("iscf_comm_rank")));
void mpi_comm_rank_() __attribute__ ((weak, alias("iscf_comm_rank")));
void mpi_comm_rank__() __attribute__ ((weak, alias("iscf_comm_rank")));
*/
void MPI_COMM_RANK() __attribute__ ((weak, alias ("iscf_comm_rank")));
void mpi_comm_rank() __attribute__ ((weak, alias ("iscf_comm_rank")));
void mpi_comm_rank_() __attribute__ ((weak, alias ("iscf_comm_rank")));
void mpi_comm_rank__() __attribute__ ((weak, alias ("iscf_comm_rank")));

#endif

void iscf_comm_rank(int *comm, int *rank, int *ierr)
{
    *ierr = MPI_Comm_rank (*comm, rank);
}

