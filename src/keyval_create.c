
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Keyval_create
 */

#include <_mpi.h>

int
MPI_Keyval_create (MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void *extra_state)
{
	return ISC_Comm_create_keyval(copy_fn, delete_fn, keyval, extra_state);
}
