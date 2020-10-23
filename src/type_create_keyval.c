
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_create_keyval
 */

#include <_mpi.h>

/* We add intercept functions for the copy and delete functions
 * which allow us to translate the MPI_Datatype input arguments into our own ABI version
 * that will actually be used for the user callback.
 */
int ISC_Typeptr_copy_intercept(void *native_datatype, int native_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int *flag)
{
	api_use_ptrs *local_a0 = active_datatypes->api_declared;
	api_use_ints *local_a1 = active_miscs->api_declared;
	keyvalpair_t *saved_callback = NULL;
	int i,k, abi_datatype = 0;
	int abi_keyval = -1;
	int result = 0;
	/* we first try to match the native_keyval to our own internal index */
	for(i=0; i < active_datatypes->how_many; i++) {
		if (local_a0[i].mpi_const == native_datatype) {
			abi_datatype = i;
			for (k=predefined_misc_count; k < active_miscs->how_many; k++) {
				if (local_a1[k].mpi_const == native_keyval) {
					abi_keyval = k;
					locate_saved_copy_callback(abi_keyval, abi_datatype, DATATYPE_CALLBACK, &saved_callback);
					if (saved_callback)
						goto invoke_callback;
				}
			}
		}
	}

invoke_callback:
	/* If we locate the callback info, we can translate the MPI_Type for the actual callback */
	if (saved_callback) {
		int (*actual_callback)(int, int, void *, void *, void *, int *) = saved_callback->ftn_pointer;
		result = actual_callback(abi_datatype, abi_keyval, extra_state, attribute_val_in, attribute_val_out, flag);
		return result;
	}
	return 0;	
}

int ISC_Typeint_copy_intercept(int native_datatype, int native_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int *flag)
{
	api_use_ints *local_a0 = active_datatypes->api_declared;
	api_use_ints *local_a1 = active_miscs->api_declared;
	keyvalpair_t *saved_callback = NULL;
	int i,k, abi_datatype = 0;
	int abi_keyval = -1;
	int result = 0;
	/* we first try to match the native_keyval to our own internal index */
	for(i=0; i < active_datatypes->how_many; i++) {
		if (local_a0[i].mpi_const == native_datatype) {
			abi_datatype = i;
			for (k=predefined_misc_count; k < active_miscs->how_many; k++) {
				if (local_a1[k].mpi_const == native_keyval) {
					abi_keyval = k;
					locate_saved_copy_callback(abi_keyval, abi_datatype, DATATYPE_CALLBACK, &saved_callback);
					if (saved_callback)
						goto invoke_callback;
				}
			}
		}
	}

invoke_callback:
	/* If we locate the callback info, we can translate the MPI_Type for the actual callback */
	if (saved_callback) {
		int (*actual_callback)(int, int, void *, void *, void *, int *) = saved_callback->ftn_pointer;
		result = actual_callback(i, abi_keyval, extra_state, attribute_val_in, attribute_val_out, flag);
		return result;
	}
	return 0;
}

int ISC_Typeptr_delete_intercept(void *native_datatype, int native_keyval, void *attribute_val, void *extra_state)
{
	api_use_ptrs *local_a0 = active_datatypes->api_declared;
	api_use_ints *local_a1 = active_miscs->api_declared;
	keyvalpair_t *saved_callback = NULL;
	int i,k, abi_datatype = 0;
	int abi_keyval = -1;
	int result = 0;
	/* we first try to match the native_keyval to our own internal index */
	for(i=0; i < active_datatypes->how_many; i++) {
		if (local_a0[i].mpi_const == native_datatype) {
			abi_datatype = i;
			for (k=predefined_misc_count; k < active_miscs->how_many; k++) {
				if (local_a1[k].mpi_const == native_keyval) {
					abi_keyval = k;
					locate_saved_delete_callback(abi_keyval, abi_datatype, DATATYPE_CALLBACK, &saved_callback);
					if (saved_callback)
						goto invoke_callback;
				}
			}
		}
	}

invoke_callback:
	/* If we locate the callback info, we can translate the MPI_Type for the actual callback */
	if (saved_callback) {
		int (*actual_callback)(int, int, void *, void *) = saved_callback->ftn_pointer;
		result = actual_callback(abi_datatype, abi_keyval, attribute_val, extra_state);
		return result;
	}
	return 0;	
}

int ISC_Typeint_delete_intercept(int native_datatype, int native_keyval, void *attribute_val, void *extra_state)
{
	api_use_ints *local_a0 = active_datatypes->api_declared;
	api_use_ints *local_a1 = active_miscs->api_declared;
	keyvalpair_t *saved_callback = NULL;
	int i,k, abi_datatype = 0;
	int abi_keyval = -1;
	int result = 0;
	/* we first try to match the native_keyval to our own internal index */
	for(i=0; i < active_datatypes->how_many; i++) {
		if (local_a0[i].mpi_const == native_datatype) {
			abi_datatype = i;
			for (k=predefined_misc_count; k < active_miscs->how_many; k++) {
				if (local_a1[k].mpi_const == native_keyval) {
					abi_keyval = k;
					locate_saved_delete_callback(abi_keyval, abi_datatype, DATATYPE_CALLBACK, &saved_callback);
					if (saved_callback)
						goto invoke_callback;
				}
			}
		}
	}

invoke_callback:
	/* If we locate the callback info, we can translate the MPI_Type for the actual callback */
	if (saved_callback) {
		int (*actual_callback)(int, int, void *, void *) = saved_callback->ftn_pointer;
		result = actual_callback(i, abi_keyval, attribute_val, extra_state);
		return result;
	}
	return 0;
}


int
MPI_Type_create_keyval (MPI_Type_copy_attr_function *type_copy_attr_fn, MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state)
{
  static void *address=0;
  int mpi_return;
#if 1
  api_use_ints *local_a0 = active_miscs->api_declared;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_create_keyval")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_create_keyval",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Type_create_keyval) (MPI_Type_copy_attr_function *, MPI_Type_delete_attr_function *, int *, void *) = address;

  *type_keyval = new_index(active_miscs);

  if (type_copy_attr_fn != MPI_NULL_COPY_FN) {
	  save_user_copy_callback(type_copy_attr_fn,*type_keyval, active_datatypes->use_ptrs, DATATYPE_CALLBACK);
	  if (type_delete_attr_fn != MPI_NULL_DELETE_FN) {
		  /* non-NULL copy and delete ftns */
		  save_user_delete_callback(type_delete_attr_fn,*type_keyval, active_datatypes->use_ptrs, DATATYPE_CALLBACK);
		  if (active_datatypes->use_ptrs) 
			  mpi_return = (*VendorMPI_Type_create_keyval)(ISC_Typeptr_copy_intercept,ISC_Typeptr_delete_intercept,
														   &local_a0[*type_keyval].mpi_const,extra_state);
		  else mpi_return = (*VendorMPI_Type_create_keyval)(ISC_Typeint_copy_intercept,ISC_Typeint_delete_intercept,
															&local_a0[*type_keyval].mpi_const,extra_state);
	  }
	  else {
		  /* non-NULL copy; NULL delete */
		  if (active_datatypes->use_ptrs) 
			  mpi_return = (*VendorMPI_Type_create_keyval)(ISC_Typeptr_copy_intercept,NULLDELFN(type_delete_attr_fn),
														   &local_a0[*type_keyval].mpi_const,extra_state);
		  else 
			  mpi_return = (*VendorMPI_Type_create_keyval)(ISC_Typeint_copy_intercept,NULLDELFN(type_delete_attr_fn),
														   &local_a0[*type_keyval].mpi_const,extra_state);
	  }
  }
  else if (type_delete_attr_fn != MPI_NULL_DELETE_FN) {
	  /* NULL copy ftn */
	  save_user_delete_callback(type_delete_attr_fn,*type_keyval, active_datatypes->use_ptrs, DATATYPE_CALLBACK);
	  if (active_datatypes->use_ptrs)
		  mpi_return = (*VendorMPI_Type_create_keyval)(NULLCOPYFN(type_copy_attr_fn),ISC_Typeptr_delete_intercept,
													   &local_a0[*type_keyval].mpi_const,extra_state);
	  else 
		  mpi_return = (*VendorMPI_Type_create_keyval)(NULLCOPYFN(type_copy_attr_fn),ISC_Typeint_delete_intercept,
													   &local_a0[*type_keyval].mpi_const,extra_state);
  }
  else 
	  mpi_return = (*VendorMPI_Type_create_keyval)(NULLCOPYFN(type_copy_attr_fn),NULLDELFN(type_delete_attr_fn),
												   &local_a0[*type_keyval].mpi_const,extra_state);
#else
  int native_keyval=0;

  api_use_ints *local_a0 = NULL;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Type_create_keyval")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Type_create_keyval",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  
  int (*VendorMPI_Type_create_keyval) (MPI_Type_copy_attr_function *, MPI_Type_delete_attr_function *, int *, void *) = address;
  mpi_return = (*VendorMPI_Type_create_keyval)(NULLTYPCOPYFN(type_copy_attr_fn),NULLTYPDELFN(type_delete_attr_fn),&native_keyval,extra_state);
  if (mpi_return == 0) {
    *type_keyval = new_index(active_miscs);
    local_a0 = active_miscs->api_declared; /* CAUTION: This reference needs to be here because 'new_index' may reallocate storage!! */
    local_a0[*type_keyval].mpi_const = native_keyval;
    if (type_copy_attr_fn != MPI_NULL_COPY_FN) {
      save_user_copy_callback(type_copy_attr_fn,*type_keyval,DATATYPE_CALLBACK);
    }
    if (type_delete_attr_fn != MPI_NULL_DELETE_FN) {
      save_user_delete_callback(type_delete_attr_fn,*type_keyval,DATATYPE_CALLBACK);
    }
  }
#endif
  return mpi_return;
}
