
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_compare
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_COMPARE() __attribute__ ((weak, alias("iscf_group_compare")));
void mpi_group_compare() __attribute__ ((weak, alias("iscf_group_compare")));
void mpi_group_compare_() __attribute__ ((weak, alias("iscf_group_compare")));
void mpi_group_compare__() __attribute__ ((weak, alias("iscf_group_compare")));
#endif

void iscf_group_compare(int *group1, int *group2, int *result, int *ierr)
{
    *ierr = MPI_Group_compare (*group1, *group2, result);
}
