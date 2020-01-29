
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_delete_attr
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_DELETE_ATTR() __attribute__ ((weak, alias("iscf_comm_delete_attr")));
void mpi_comm_delete_attr() __attribute__ ((weak, alias("iscf_comm_delete_attr")));
void mpi_comm_delete_attr_() __attribute__ ((weak, alias("iscf_comm_delete_attr")));
void mpi_comm_delete_attr__() __attribute__ ((weak, alias("iscf_comm_delete_attr")));
#endif

void iscf_comm_delete_attr(int *comm, int *comm_keyval, int *ierr)
{
    *ierr = MPI_Comm_delete_attr (*comm, *comm_keyval);
}
