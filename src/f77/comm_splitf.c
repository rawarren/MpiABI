
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_split
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_SPLIT() __attribute__ ((weak, alias("iscf_comm_split")));
void mpi_comm_split() __attribute__ ((weak, alias("iscf_comm_split")));
void mpi_comm_split_() __attribute__ ((weak, alias("iscf_comm_split")));
void mpi_comm_split__() __attribute__ ((weak, alias("iscf_comm_split")));
#endif

void iscf_comm_split(int *comm, int *color, int *key, int *newcomm, int *ierr)
{
    *ierr = MPI_Comm_split (*comm, *color, *key, newcomm);
}
