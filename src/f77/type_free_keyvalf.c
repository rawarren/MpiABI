
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_free_keyval
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_FREE_KEYVAL() __attribute__ ((weak, alias("iscf_type_free_keyval")));
void mpi_type_free_keyval() __attribute__ ((weak, alias("iscf_type_free_keyval")));
void mpi_type_free_keyval_() __attribute__ ((weak, alias("iscf_type_free_keyval")));
void mpi_type_free_keyval__() __attribute__ ((weak, alias("iscf_type_free_keyval")));
#endif

void iscf_type_free_keyval(int *type_keyval, int *ierr)
{
    *ierr = MPI_Type_free_keyval (type_keyval);
}
