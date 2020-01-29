
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_rank
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_RANK() __attribute__ ((weak, alias("iscf_group_rank")));
void mpi_group_rank() __attribute__ ((weak, alias("iscf_group_rank")));
void mpi_group_rank_() __attribute__ ((weak, alias("iscf_group_rank")));
void mpi_group_rank__() __attribute__ ((weak, alias("iscf_group_rank")));
#endif

void iscf_group_rank(int *group, int *rank, int *ierr)
{
    *ierr = MPI_Group_rank (*group, rank);
}
