
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_remote_group
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_REMOTE_GROUP() __attribute__ ((weak, alias("iscf_comm_remote_group")));
void mpi_comm_remote_group() __attribute__ ((weak, alias("iscf_comm_remote_group")));
void mpi_comm_remote_group_() __attribute__ ((weak, alias("iscf_comm_remote_group")));
void mpi_comm_remote_group__() __attribute__ ((weak, alias("iscf_comm_remote_group")));
#endif

void iscf_comm_remote_group(int *comm, int *group, int *ierr)
{
    *ierr = MPI_Comm_remote_group (*comm, group);
}
