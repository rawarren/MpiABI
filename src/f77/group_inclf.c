
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_incl
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_INCL() __attribute__ ((weak, alias("iscf_group_incl")));
void mpi_group_incl() __attribute__ ((weak, alias("iscf_group_incl")));
void mpi_group_incl_() __attribute__ ((weak, alias("iscf_group_incl")));
void mpi_group_incl__() __attribute__ ((weak, alias("iscf_group_incl")));
#endif

void iscf_group_incl(int *group, int *n, int *ranks, int *newgroup, int *ierr)
{
    *ierr = MPI_Group_incl (*group, *n, ranks, newgroup);
}
