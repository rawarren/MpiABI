
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Win_get_attr
 */

#include <_mpi.h>

static int _isc_proc_null = MPI_PROC_NULL;

int
MPI_Win_get_attr (MPI_Win win, int win_keyval, void *attribute_val, int *flag)
{
    static void *address=0;
    int mpi_return;
    api_use_ints *local_a1=active_miscs->api_declared;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Win_get_attr")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Win_get_attr",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    if (active_wins->use_ptrs) { api_use_ptrs *local_a0=active_wins->api_declared;
	int (*VendorMPI_Win_get_attr)(void *,int win_keyval,void *attribute_val, int *flag) = address;
	mpi_return = (*VendorMPI_Win_get_attr)(local_a0[win].mpi_const,local_a1[win_keyval].mpi_const,attribute_val,flag);
    } else { api_use_ints *local_a0=active_wins->api_declared;
	int (*VendorMPI_Win_get_attr)(int,int win_keyval,void *attribute_val, int *flag) = address;
	mpi_return = (*VendorMPI_Win_get_attr)(local_a0[win].mpi_const,local_a1[win_keyval].mpi_const,attribute_val,flag);
    }
    if (*flag) {
	int *vval = (int *)attribute_val;
	int proc_null_check = *vval;
	if (proc_null_check == local_a1[ISC_PROC_NULL_].mpi_const) {
	    _isc_proc_null = local_a1[ISC_PROC_NULL_].self;
	    *vval = _isc_proc_null;
	}
	else if (win_keyval == ISC_WIN_CREATE_FLAVOR) {
	    int **flavor = (int **)attribute_val;
	    if (*flavor[0] == local_a1[MPI_WIN_FLAVOR_CREATE].mpi_const) {
		*flavor[0] = MPI_WIN_FLAVOR_CREATE;
	    }
	    else if (*flavor[0] == local_a1[MPI_WIN_FLAVOR_ALLOCATE].mpi_const) {
		*flavor[0] = MPI_WIN_FLAVOR_ALLOCATE;
	    }
	    else if (*flavor[0] == local_a1[MPI_WIN_FLAVOR_DYNAMIC].mpi_const) {
		*flavor[0] = MPI_WIN_FLAVOR_DYNAMIC;
	    }
	}
	else if (win_keyval == ISC_WIN_MODEL) {
	    int **model = (int **)attribute_val;
	    if (*model[0] == local_a1[MPI_WIN_SEPARATE].mpi_const) {
		*model[0] = MPI_WIN_SEPARATE;
	    }
	    else if (*model[0] == local_a1[MPI_WIN_UNIFIED].mpi_const) {
		*model[0] = MPI_WIN_UNIFIED;
	    }
	}
    }

    return mpi_return;
}
