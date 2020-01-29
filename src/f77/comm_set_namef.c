
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_set_name
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_SET_NAME() __attribute__ ((weak, alias("iscf_comm_set_name")));
void mpi_comm_set_name() __attribute__ ((weak, alias("iscf_comm_set_name")));
void mpi_comm_set_name_() __attribute__ ((weak, alias("iscf_comm_set_name")));
void mpi_comm_set_name__() __attribute__ ((weak, alias("iscf_comm_set_name")));
#endif

void iscf_comm_set_name(int *comm,  char *comm_name, int *ierr)
{
    *ierr = MPI_Comm_set_name (*comm, comm_name);
}
