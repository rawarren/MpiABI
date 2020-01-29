
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_range_incl
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_RANGE_INCL() __attribute__ ((weak, alias("iscf_group_range_incl")));
void mpi_group_range_incl() __attribute__ ((weak, alias("iscf_group_range_incl")));
void mpi_group_range_incl_() __attribute__ ((weak, alias("iscf_group_range_incl")));
void mpi_group_range_incl__() __attribute__ ((weak, alias("iscf_group_range_incl")));
#endif

void iscf_group_range_incl(int *group, int *n, int ranges[][3], int *newgroup, int *ierr)
{
  *ierr = MPI_Group_range_incl (*group, *n, ranges, newgroup);
}
