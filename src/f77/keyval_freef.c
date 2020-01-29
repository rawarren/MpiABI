
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Keyval_free
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_KEYVAL_FREE() __attribute__ ((weak, alias("iscf_keyval_free")));
void mpi_keyval_free() __attribute__ ((weak, alias("iscf_keyval_free")));
void mpi_keyval_free_() __attribute__ ((weak, alias("iscf_keyval_free")));
void mpi_keyval_free__() __attribute__ ((weak, alias("iscf_keyval_free")));
#endif

void iscf_keyval_free(int *keyval, int *ierr)
{
    *ierr = MPI_Keyval_free (keyval);
}
