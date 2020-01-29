
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_union
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_UNION() __attribute__ ((weak, alias("iscf_group_union")));
void mpi_group_union() __attribute__ ((weak, alias("iscf_group_union")));
void mpi_group_union_() __attribute__ ((weak, alias("iscf_group_union")));
void mpi_group_union__() __attribute__ ((weak, alias("iscf_group_union")));
#endif

void iscf_group_union(int *group1, int *group2, int *newgroup, int *ierr)
{
    *ierr = MPI_Group_union (*group1, *group2, newgroup);
}
