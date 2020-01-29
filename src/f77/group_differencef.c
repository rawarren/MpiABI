
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_difference
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_DIFFERENCE() __attribute__ ((weak, alias("iscf_group_difference")));
void mpi_group_difference() __attribute__ ((weak, alias("iscf_group_difference")));
void mpi_group_difference_() __attribute__ ((weak, alias("iscf_group_difference")));
void mpi_group_difference__() __attribute__ ((weak, alias("iscf_group_difference")));
#endif

void iscf_group_difference(int *group1, int *group2, int *newgroup, int *ierr)
{
    *ierr = MPI_Group_difference (*group1, *group2, newgroup);
}
