
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_intersection
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_INTERSECTION() __attribute__ ((weak, alias("iscf_group_intersection")));
void mpi_group_intersection() __attribute__ ((weak, alias("iscf_group_intersection")));
void mpi_group_intersection_() __attribute__ ((weak, alias("iscf_group_intersection")));
void mpi_group_intersection__() __attribute__ ((weak, alias("iscf_group_intersection")));
#endif

void iscf_group_intersection(int *group1, int *group2, int *newgroup, int *ierr)
{
    *ierr = MPI_Group_intersection (*group1, *group2, newgroup);
}
