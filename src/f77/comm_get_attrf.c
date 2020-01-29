
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_get_attr
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_GET_ATTR() __attribute__ ((weak, alias("iscf_comm_get_attr")));
void mpi_comm_get_attr() __attribute__ ((weak, alias("iscf_comm_get_attr")));
void mpi_comm_get_attr_() __attribute__ ((weak, alias("iscf_comm_get_attr")));
void mpi_comm_get_attr__() __attribute__ ((weak, alias("iscf_comm_get_attr")));
#endif

void iscf_comm_get_attr(int *comm, int *comm_keyval, void *attribute_val, int *flag, int *ierr)
{
    *ierr = MPI_Comm_get_attr (*comm, *comm_keyval, attribute_val, flag);
}
