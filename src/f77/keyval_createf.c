
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Keyval_create
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_KEYVAL_CREATE() __attribute__ ((weak, alias("iscf_keyval_create")));
void mpi_keyval_create() __attribute__ ((weak, alias("iscf_keyval_create")));
void mpi_keyval_create_() __attribute__ ((weak, alias("iscf_keyval_create")));
void mpi_keyval_create__() __attribute__ ((weak, alias("iscf_keyval_create")));
#endif

void iscf_keyval_create(void *copy_fn, void *delete_fn, int *keyval,  void *extra_state, int *ierr)
{
  *ierr = MPI_Keyval_create ((MPI_Copy_function *)copy_fn, (MPI_Delete_function *)delete_fn, keyval, extra_state);
}
