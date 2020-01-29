
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Group_size
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GROUP_SIZE() __attribute__ ((weak, alias("iscf_group_size")));
void mpi_group_size() __attribute__ ((weak, alias("iscf_group_size")));
void mpi_group_size_() __attribute__ ((weak, alias("iscf_group_size")));
void mpi_group_size__() __attribute__ ((weak, alias("iscf_group_size")));
#endif

void iscf_group_size(int *group, int *size, int *ierr)
{
    *ierr = MPI_Group_size (*group, size);
}
