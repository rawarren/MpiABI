
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_range_excl
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_RANGE_EXCL() __attribute__ ((weak, alias("iscf_group_range_excl")));
void mpi_group_range_excl() __attribute__ ((weak, alias("iscf_group_range_excl")));
void mpi_group_range_excl_() __attribute__ ((weak, alias("iscf_group_range_excl")));
void mpi_group_range_excl__() __attribute__ ((weak, alias("iscf_group_range_excl")));
#endif

void iscf_group_range_excl(int *group, int *n, int ranges[][3], int *newgroup, int *ierr)
{
  *ierr = MPI_Group_range_excl (*group, *n, ranges, newgroup);
}
