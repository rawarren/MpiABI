
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_create
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_CREATE() __attribute__ ((weak, alias("iscf_comm_create")));
void mpi_comm_create() __attribute__ ((weak, alias("iscf_comm_create")));
void mpi_comm_create_() __attribute__ ((weak, alias("iscf_comm_create")));
void mpi_comm_create__() __attribute__ ((weak, alias("iscf_comm_create")));
#endif

void iscf_comm_create(int *comm, int *group, int *newcomm, int *ierr)
{
    *ierr = MPI_Comm_create (*comm, *group, newcomm);
}
