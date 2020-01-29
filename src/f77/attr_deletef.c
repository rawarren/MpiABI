
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Attr_delete
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ATTR_DELETE() __attribute__ ((weak, alias("iscf_attr_delete")));
void mpi_attr_delete() __attribute__ ((weak, alias("iscf_attr_delete")));
void mpi_attr_delete_() __attribute__ ((weak, alias("iscf_attr_delete")));
void mpi_attr_delete__() __attribute__ ((weak, alias("iscf_attr_delete")));
#endif

void iscf_attr_delete(int *comm, int *keyval, int *ierr)
{
    *ierr = MPI_Attr_delete (*comm, *keyval);
}
