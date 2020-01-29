
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_get_parent
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_GET_PARENT() __attribute__ ((weak, alias("iscf_comm_get_parent")));
void mpi_comm_get_parent() __attribute__ ((weak, alias("iscf_comm_get_parent")));
void mpi_comm_get_parent_() __attribute__ ((weak, alias("iscf_comm_get_parent")));
void mpi_comm_get_parent__() __attribute__ ((weak, alias("iscf_comm_get_parent")));
#endif

void iscf_comm_get_parent(int *parent, int *ierr)
{
    *ierr = MPI_Comm_get_parent (parent);
}
