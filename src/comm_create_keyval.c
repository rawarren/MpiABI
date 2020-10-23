
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_create_keyval
 */

#include <_mpi.h>

/* We add intercept functions for the copy and delete functions
 * which allow us to translate the MPI_Comm input arguments into our own ABI version
 * that will actually be used for the user callback.
 */
int ISC_Commptr_copy_intercept(void *native_comm, int native_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int *flag)
{
	api_use_ptrs *local_a0 = active_comms->api_declared;
	api_use_ints *local_a1 = active_miscs->api_declared;
	keyvalpair_t *saved_callback = NULL;
	int i,k, abi_comm = 0;
	int abi_keyval = -1;
	int result = 0;

	for(k=0; k < active_comms->how_many; k++) {
		if (local_a0[k].mpi_const == native_comm) {
			abi_comm = k;
			for (i=predefined_misc_count; i < active_miscs->how_many; i++) {
				if (local_a1[i].mpi_const == native_keyval) {
					abi_keyval = i;
					locate_saved_copy_callback(abi_keyval, abi_comm, COMM_CALLBACK, &saved_callback);
					if (saved_callback)
						goto invoke_callback;
				}
			}
		}
	}

invoke_callback:
	/* If we locate the callback info, we can translate the MPI_Comm for the actual callback */
	if (saved_callback) {
		int (*actual_callback)(int, int, void *, void *, void *, int *) = saved_callback->ftn_pointer;
		result = actual_callback(abi_comm, abi_keyval, extra_state, attribute_val_in, attribute_val_out, flag);
		return result;
	}
	return 0;
}

int ISC_Commint_copy_intercept(int native_comm, int native_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int *flag)
{
	api_use_ints *local_a0 = active_comms->api_declared;
	api_use_ints *local_a1 = active_miscs->api_declared;
	keyvalpair_t *saved_callback = NULL;
	int i, k, abi_comm = 0;
	int abi_keyval = 0;
	int result = 0;
	/* we first try to match the native_keyval to our own internal index */
	for(k=0; k < active_comms->how_many; k++) {
		if (local_a0[k].mpi_const == native_comm) {
			abi_comm = k;
			for (i=predefined_misc_count; i < active_miscs->how_many; i++) {
				if (local_a1[i].mpi_const == native_keyval) {
					abi_keyval = i;
					locate_saved_copy_callback(abi_keyval, abi_comm, COMM_CALLBACK, &saved_callback);
					if (saved_callback)
						goto invoke_callback;
				}
			}
		}
	}

invoke_callback:
	/* If we locate the callback info, we can translate the MPI_Comm for the actual callback */
	if (saved_callback) {
		int (*actual_callback)(int, int, void *, void *, void *, int *) = saved_callback->ftn_pointer;
		result = actual_callback(abi_comm, abi_keyval, extra_state, attribute_val_in, attribute_val_out, flag);
		return result;
	}

	return 0;
}

int ISC_Commptr_delete_intercept(void *native_comm, int native_keyval, void *attribute_val, void *extra_state)
{
	api_use_ptrs *local_a0 = active_comms->api_declared;
	api_use_ints *local_a1 = active_miscs->api_declared;
	keyvalpair_t *saved_callback = NULL;
	int i,k, abi_comm = 0;
	int abi_keyval = -1;
	int result = 0;
	/* we first try to match the native_keyval to our own internal index */
	for(k=0; k < active_comms->how_many; k++) {
		if (local_a0[k].mpi_const == native_comm) {
			abi_comm = k;
			for (i=predefined_misc_count; i < active_miscs->how_many; i++) {
				if (local_a1[i].mpi_const == native_keyval) {
					abi_keyval = i;
					locate_saved_delete_callback(abi_keyval, abi_comm, COMM_CALLBACK, &saved_callback);
					if (saved_callback)
						goto invoke_callback;
				}
			}
		}
	}

invoke_callback:
	/* If we locate the callback info, we can translate the MPI_Comm for the actual callback */
	if (saved_callback) {
		int (*actual_callback)(int, int, void *, void *) = saved_callback->ftn_pointer;
		for(i=0; i < active_comms->how_many; i++) {
			if (local_a0[i].mpi_const == native_comm) {
				abi_comm = i;
				result = actual_callback(abi_comm, abi_keyval, attribute_val, extra_state);
				return result;
			}
		}
	}
	return 0;

}

int ISC_Commint_delete_intercept(int native_comm, int native_keyval, void *attribute_val, void *extra_state)
{
	api_use_ints *local_a0 = active_comms->api_declared;
	api_use_ints *local_a1 = active_miscs->api_declared;
	keyvalpair_t *saved_callback = NULL;
	int i,k, abi_comm = 0;
	int abi_keyval = -1;
	int result = 0;
	/* we first try to match the native_keyval to our own internal index */
	for(k=0; k < active_comms->how_many; k++) {
		if (local_a0[k].mpi_const == native_comm) {
			abi_comm = k;
			for (i=predefined_misc_count; i < active_miscs->how_many; i++) {
				if (local_a1[i].mpi_const == native_keyval) {
					abi_keyval = i;
					locate_saved_delete_callback(abi_keyval, abi_comm, COMM_CALLBACK, &saved_callback);
					if (saved_callback)
						goto invoke_callback;
				}
			}
		}
	}

invoke_callback:
	/* If we locate the callback info, we can translate the MPI_Comm for the actual callback */
	if (saved_callback) {
		int (*actual_callback)(int, int, void *, void *) = saved_callback->ftn_pointer;
		result = actual_callback(abi_comm, abi_keyval, attribute_val, extra_state);
		return result;
	}
	return 0;
}

int
MPI_Comm_create_keyval (MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state)
{
  static void *address=0;
  int mpi_return;

  api_use_ints *local_a0 = active_miscs->api_declared;
  api_use_ptrs *local_a1 = active_addrs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_create_keyval")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_create_keyval",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Comm_create_keyval) (MPI_Comm_copy_attr_function *, MPI_Comm_delete_attr_function *, int *, void *) = address;

  *comm_keyval = new_index(active_miscs);

  if (comm_copy_attr_fn != MPI_NULL_COPY_FN) {
	  save_user_copy_callback(comm_copy_attr_fn,*comm_keyval, active_comms->use_ptrs, COMM_CALLBACK);
	  if (comm_delete_attr_fn != MPI_NULL_DELETE_FN) {
		  /* non-NULL copy and delete ftns */
		  save_user_delete_callback(comm_delete_attr_fn,*comm_keyval, active_comms->use_ptrs, COMM_CALLBACK);
		  if (active_comms->use_ptrs) 
			  mpi_return = (*VendorMPI_Comm_create_keyval)(ISC_Commptr_copy_intercept,ISC_Commptr_delete_intercept,
														   &local_a0[*comm_keyval].mpi_const,extra_state);
		  else mpi_return = (*VendorMPI_Comm_create_keyval)(ISC_Commint_copy_intercept,ISC_Commint_delete_intercept,
															&local_a0[*comm_keyval].mpi_const,extra_state);
	  }
	  else {
		  /* non-NULL copy; NULL delete */
		  if (active_comms->use_ptrs) 
			  mpi_return = (*VendorMPI_Comm_create_keyval)(ISC_Commptr_copy_intercept,NULLDELFN(comm_delete_attr_fn),
														   &local_a0[*comm_keyval].mpi_const,extra_state);
		  else 
			  mpi_return = (*VendorMPI_Comm_create_keyval)(ISC_Commint_copy_intercept,NULLDELFN(comm_delete_attr_fn),
														   &local_a0[*comm_keyval].mpi_const,extra_state);
	  }
  }
  else if (comm_delete_attr_fn != MPI_NULL_DELETE_FN) {
	  /* NULL copy ftn */
	  save_user_delete_callback(comm_delete_attr_fn,*comm_keyval, active_comms->use_ptrs, COMM_CALLBACK);
	  if (active_comms->use_ptrs)
		  mpi_return = (*VendorMPI_Comm_create_keyval)(local_a1[ISC_NULL_COPY_FN].mpi_const,
													   ISC_Commptr_delete_intercept,
													   &local_a0[*comm_keyval].mpi_const,extra_state);
	  else 
		  mpi_return = (*VendorMPI_Comm_create_keyval)(local_a1[ISC_NULL_COPY_FN].mpi_const,
													   ISC_Commint_delete_intercept,
													   &local_a0[*comm_keyval].mpi_const,extra_state);
  }
  else 
	  mpi_return = (*VendorMPI_Comm_create_keyval)(local_a1[ISC_NULL_COPY_FN].mpi_const,local_a1[ISC_NULL_COPY_FN].mpi_const,
												   &local_a0[*comm_keyval].mpi_const,extra_state);
  return mpi_return;
}
