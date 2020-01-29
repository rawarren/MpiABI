
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_set_attr
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_SET_ATTR() __attribute__ ((weak, alias("iscf_comm_set_attr")));
void mpi_comm_set_attr() __attribute__ ((weak, alias("iscf_comm_set_attr")));
void mpi_comm_set_attr_() __attribute__ ((weak, alias("iscf_comm_set_attr")));
void mpi_comm_set_attr__() __attribute__ ((weak, alias("iscf_comm_set_attr")));
#endif

void iscf_comm_set_attr(int *comm, int *comm_keyval,  void *attribute_val, int *ierr)
{
    *ierr = MPI_Comm_set_attr (*comm, *comm_keyval, attribute_val);
}
