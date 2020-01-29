
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_get_name
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_GET_NAME() __attribute__ ((weak, alias("iscf_comm_get_name")));
void mpi_comm_get_name() __attribute__ ((weak, alias("iscf_comm_get_name")));
void mpi_comm_get_name_() __attribute__ ((weak, alias("iscf_comm_get_name")));
void mpi_comm_get_name__() __attribute__ ((weak, alias("iscf_comm_get_name")));
#endif

void iscf_comm_get_name(int *comm, char *comm_name, int *resultlen, int *ierr)
{
    *ierr = MPI_Comm_get_name (*comm, comm_name, resultlen);
}
