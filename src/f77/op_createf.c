
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Op_create
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_OP_CREATE() __attribute__ ((weak, alias("iscf_op_create")));
void mpi_op_create() __attribute__ ((weak, alias("iscf_op_create")));
void mpi_op_create_() __attribute__ ((weak, alias("iscf_op_create")));
void mpi_op_create__() __attribute__ ((weak, alias("iscf_op_create")));
#endif

void iscf_op_create(void *function, int *commute, int *op, int *ierr)
{
  *ierr = MPI_Op_create ((MPI_User_function *)function, *commute, op);
}
