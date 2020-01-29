
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_group
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_GROUP() __attribute__ ((weak, alias("iscf_comm_group")));
void mpi_comm_group() __attribute__ ((weak, alias("iscf_comm_group")));
void mpi_comm_group_() __attribute__ ((weak, alias("iscf_comm_group")));
void mpi_comm_group__() __attribute__ ((weak, alias("iscf_comm_group")));
#endif

void iscf_comm_group(int *comm, int *group, int *ierr)
{
    *ierr = MPI_Comm_group (*comm, group);
}
