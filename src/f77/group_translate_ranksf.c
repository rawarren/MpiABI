
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_translate_ranks
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_TRANSLATE_RANKS() __attribute__ ((weak, alias("iscf_group_translate_ranks")));
void mpi_group_translate_ranks() __attribute__ ((weak, alias("iscf_group_translate_ranks")));
void mpi_group_translate_ranks_() __attribute__ ((weak, alias("iscf_group_translate_ranks")));
void mpi_group_translate_ranks__() __attribute__ ((weak, alias("iscf_group_translate_ranks")));
#endif

void iscf_group_translate_ranks(int *group1, int *n, int *ranks1, int *group2, int *ranks2, int *ierr)
{
    *ierr = MPI_Group_translate_ranks (*group1, *n, ranks1, *group2, ranks2);
}
