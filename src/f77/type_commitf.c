
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_commit
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_COMMIT() __attribute__ ((weak, alias("iscf_type_commit")));
void mpi_type_commit() __attribute__ ((weak, alias("iscf_type_commit")));
void mpi_type_commit_() __attribute__ ((weak, alias("iscf_type_commit")));
void mpi_type_commit__() __attribute__ ((weak, alias("iscf_type_commit")));
#endif

void iscf_type_commit(int *type, int *ierr)
{
    *ierr = MPI_Type_commit (type);
}
