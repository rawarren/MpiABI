
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Intercomm_create
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_INTERCOMM_CREATE() __attribute__ ((weak, alias("iscf_intercomm_create")));
void mpi_intercomm_create() __attribute__ ((weak, alias("iscf_intercomm_create")));
void mpi_intercomm_create_() __attribute__ ((weak, alias("iscf_intercomm_create")));
void mpi_intercomm_create__() __attribute__ ((weak, alias("iscf_intercomm_create")));
#endif

void iscf_intercomm_create(int *local_comm, int *local_leader, int *bridge_comm, int *remote_leader, int *tag, int *newintercomm, int *ierr)
{
    *ierr = MPI_Intercomm_create (*local_comm, *local_leader, *bridge_comm, *remote_leader, *tag, newintercomm);
}
