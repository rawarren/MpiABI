
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_excl
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_EXCL() __attribute__ ((weak, alias("iscf_group_excl")));
void mpi_group_excl() __attribute__ ((weak, alias("iscf_group_excl")));
void mpi_group_excl_() __attribute__ ((weak, alias("iscf_group_excl")));
void mpi_group_excl__() __attribute__ ((weak, alias("iscf_group_excl")));
#endif

void iscf_group_excl(int *group, int *n, int *ranks, int *newgroup, int *ierr)
{
    *ierr = MPI_Group_excl (*group, *n, ranks, newgroup);
}
