
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_join
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_JOIN() __attribute__ ((weak, alias("iscf_comm_join")));
void mpi_comm_join() __attribute__ ((weak, alias("iscf_comm_join")));
void mpi_comm_join_() __attribute__ ((weak, alias("iscf_comm_join")));
void mpi_comm_join__() __attribute__ ((weak, alias("iscf_comm_join")));
#endif

void iscf_comm_join(int *fd, int *intercomm, int *ierr)
{
    *ierr = MPI_Comm_join (*fd, intercomm);
}
