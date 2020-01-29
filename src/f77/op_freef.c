
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Op_free
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_OP_FREE() __attribute__ ((weak, alias("iscf_op_free")));
void mpi_op_free() __attribute__ ((weak, alias("iscf_op_free")));
void mpi_op_free_() __attribute__ ((weak, alias("iscf_op_free")));
void mpi_op_free__() __attribute__ ((weak, alias("iscf_op_free")));
#endif

void iscf_op_free(int *op, int *ierr)
{
    *ierr = MPI_Op_free (op);
}
