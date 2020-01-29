
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_free
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_FREE() __attribute__ ((weak, alias("iscf_group_free")));
void mpi_group_free() __attribute__ ((weak, alias("iscf_group_free")));
void mpi_group_free_() __attribute__ ((weak, alias("iscf_group_free")));
void mpi_group_free__() __attribute__ ((weak, alias("iscf_group_free")));
#endif

void iscf_group_free(int *group, int *ierr)
{
    *ierr = MPI_Group_free (group);
}
