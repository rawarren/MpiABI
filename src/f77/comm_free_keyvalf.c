
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_free_keyval
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_FREE_KEYVAL() __attribute__ ((weak, alias("iscf_comm_free_keyval")));
void mpi_comm_free_keyval() __attribute__ ((weak, alias("iscf_comm_free_keyval")));
void mpi_comm_free_keyval_() __attribute__ ((weak, alias("iscf_comm_free_keyval")));
void mpi_comm_free_keyval__() __attribute__ ((weak, alias("iscf_comm_free_keyval")));
#endif

void iscf_comm_free_keyval(int *comm_keyval, int *ierr)
{
    *ierr = MPI_Comm_free_keyval (comm_keyval);
}
