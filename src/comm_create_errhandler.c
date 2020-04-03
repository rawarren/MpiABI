
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_create_errhandler
 */

#include <_mpi.h>


typedef struct eh_intercept_entry {
    int index;
    MPI_Errhandler eh;
    MPI_Comm_errhandler_fn *abi_ftn;
    MPI_Comm_errhandler_fn *user_ftn;
} eh_intercept_entry_t;

static eh_intercept_entry_t *eh_intercepts = NULL;
static int active_win_entries = 0;
static int active_comm_entries = 0;
static int active_intercept_limit = 16;


int
isc_increment_active_win_entries()
{
    active_win_entries++;
    return active_win_entries;
}

int
isc_decrement_active_win_entries()
{
    active_win_entries--;
    return active_win_entries;
}

int
isc_error_from_int(int *native_err)
{
    int i;
    api_use_ints *local_a0 = active_errcodes->api_declared;
    for (i=0; i< active_errcodes->how_many; i++) {
	if (local_a0[i].mpi_const == *native_err)
	    return i;
    }
    return 0;
    
}

/* Errhandler use_ptrs */
int
isc_comm_from_ptr(void **native_comm)
{
    int i;
    api_use_ptrs *local_a0 = active_comms->api_declared;
    for (i=0; i< active_comms->how_many; i++) {
	if (local_a0[i].mpi_const == *native_comm)
	    return i;
    }
    return 0;
}

void
__errhandler_ftn_use_ptrs(int idx, void ** comm, int *err)
{
    int abi_comm;
    int abi_error;
    eh_intercept_entry_t *intercept = &eh_intercepts[idx];
    abi_comm = isc_comm_from_ptr(comm);
    abi_error = isc_error_from_int(err);
    (*intercept->user_ftn)(&abi_comm, &abi_error);
}

static void
ABI_Errhandler_ftn_use_ptrs_0( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(0, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_1( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(1, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_2( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(2, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_3( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(3, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_4( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(4, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_5( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(5, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_6( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(6, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_7( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(7, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_8( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(8, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_9( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(9, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_10( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(10, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_11( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(11, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_12( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(12, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_13( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(13, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_14( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(14, comm, err);
}
static void
ABI_Errhandler_ftn_use_ptrs_15( void ** comm, int *err)
{
    return __errhandler_ftn_use_ptrs(15, comm, err);
}

/* Errhandler use_ints */

int
isc_comm_from_int(int *native_comm)
{
    int i;
    api_use_ints *local_a0 = active_comms->api_declared;
    for (i=0; i< active_comms->how_many; i++) {
	if (local_a0[i].mpi_const == *native_comm)
	    return i;
    }
    return 0;
}

static void
__errhandler_ftn_use_ints( int idx, int *comm, int *err)
{
    int abi_comm;
    int abi_error;
    eh_intercept_entry_t *intercept = &eh_intercepts[idx];
    abi_comm = isc_comm_from_int(comm);
    abi_error = isc_error_from_int(err);
    (*intercept->user_ftn)(&abi_comm, &abi_error);
}

static void
ABI_Errhandler_ftn_use_ints_0( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(0, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_1( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(1, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_2( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(2, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_3( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(3, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_4( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(4, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_5( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(5, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_6( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(6, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_7( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(7, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_8( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(8, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_9( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(9, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_10( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(10, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_11( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(11, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_12( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(12, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_13( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(13, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_14( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(14, comm, err);
}
static void
ABI_Errhandler_ftn_use_ints_15( int * comm, int *err)
{
    return __errhandler_ftn_use_ints(15, comm, err);
}


static MPI_Comm_errhandler_fn *
next_abi_ftn(int use_ptrs, int active_entries)
{
    switch(active_entries) {
    case 0:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_0;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_0;
	break;
    case 1:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_1;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_1;
	break;
    case 2:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_2;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_2;
	break;
    case 3:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_3;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_3;
	break;
    case 4:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_4;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_4;
	break;
    case 5:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_5;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_5;
	break;
    case 6:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_6;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_6;
	break;
    case 7:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_7;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_7;
	break;
    case 8:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_8;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_8;
	break;
    case 9:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_9;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_9;
       break;
    case 10:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_10;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_10;
	break;
    case 11:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_11;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_11;
	break;
    case 12:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_12;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_12;
	break;
    case 13:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_13;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_13;
	break;
    case 14:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_14;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_14;
	break;
    case 15:
	if (use_ptrs)
	    return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ptrs_15;
	else return (MPI_Comm_errhandler_fn *)ABI_Errhandler_ftn_use_ints_15;
	break;
    default:
	puts("Exceeded the new op limit!");
    }
    return NULL;
}


static eh_intercept_entry_t *
add_ABI_comm_userftn_intercept(MPI_Errhandler eh, MPI_Comm_errhandler_fn *user_ftn, int use_ptrs )
{
    eh_intercept_entry_t *new_intercept = NULL;
    if (eh_intercepts == NULL) 
	eh_intercepts = (eh_intercept_entry_t *)calloc(active_intercept_limit, sizeof(eh_intercept_entry_t));
    if (eh_intercepts) {
	int next = 0;
	while(eh_intercepts[next].eh != 0) {
	    next++;
	    if (next == active_intercept_limit)
		return NULL;
	}
	new_intercept = &eh_intercepts[next];
	new_intercept->eh = eh;
	new_intercept->abi_ftn = next_abi_ftn(use_ptrs, active_comm_entries);
	new_intercept->user_ftn = user_ftn;
	new_intercept->index = next;
	active_comm_entries++;
	return new_intercept;
    }
    return NULL;
}

/* Fixme!
 * The following free function should probably create a free list
 * rather than freeing the op_intercept_entry_t.  The problem is
 * that we can not guarantee the order of freeing stuff and we
 * have a limit to the number of intercept functions... so
 * simply decrementing the active_entry count isn't sufficient!
 */
extern int maybe_free_win_errhandler_intercept(MPI_Errhandler eh);

int maybe_free_errhandler_intercept(MPI_Errhandler eh)
{
    int i, found = 0;
    if (active_win_entries)
	found = maybe_free_win_errhandler_intercept(eh);
	
    if (!found) {
	for(i = 0; i<active_intercept_limit; i++) {
	    if (eh_intercepts[i].eh == eh) {
		found = 1;
		eh_intercepts[i].eh = 0;
		eh_intercepts[i].index = -1;
		/* NOTE:  We don't delete the user_ftn entry
		 * because some async operations may not have
		 * completed prior to the op_free call!
		 */
		active_comm_entries--;
		return found;
	    }
	}
    }
    return found;
}




int
MPI_Comm_create_errhandler (MPI_Comm_errhandler_fn *function, MPI_Errhandler *errhandler)
{
    static void *address=0;
    int mpi_return;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Comm_create_errhandler")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_create_errhandler",SYM_MISSING_TRAILER);
	    return -1;
	}
    }

    *errhandler = new_index(active_errhandlers);
    if (active_errhandlers->use_ptrs) { api_use_ptrs *local_a0=active_errhandlers->api_declared;
     int (*VendorMPI_Comm_create_errhandler)(MPI_Comm_errhandler_fn *function,void **) = address;
     eh_intercept_entry_t *intercept = add_ABI_comm_userftn_intercept(*errhandler,function, 1);
     mpi_return = (*VendorMPI_Comm_create_errhandler)(intercept->abi_ftn,&local_a0[*errhandler].mpi_const);
    } else { api_use_ints *local_a0=active_errhandlers->api_declared;
     int (*VendorMPI_Comm_create_errhandler)(MPI_Comm_errhandler_fn *function,int *) = address;
     eh_intercept_entry_t *intercept = add_ABI_comm_userftn_intercept(*errhandler,function, 0);
     mpi_return = (*VendorMPI_Comm_create_errhandler)(intercept->abi_ftn,&local_a0[*errhandler].mpi_const);
    }
    return mpi_return;
}
