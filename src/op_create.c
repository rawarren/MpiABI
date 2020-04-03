
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Op_create
 */

#include <_mpi.h>

typedef struct op_intercept_entry {
    int index;
    MPI_Op op;
    MPI_User_function *abi_ftn;
    MPI_User_function *user_ftn;
} op_intercept_entry_t;

static op_intercept_entry_t *op_intercepts = NULL;
static int active_entries = 0;
static int active_intercept_limit = 16;

/* FIXME!  I'm unsure how to associate a particular MPI_User_function intercept with
   a particular op_create.   For now, I associate a unique function for each MPI_Op_create.
   This is ok for initial testing, but I'm not sure how to dynamically associate a new
   intecept with each new op_create function.

   It would be nice to be able to use "closures" in this approach, but
   our implementation language doesn't support this...

   Note:  The current implementation is restricted to having 16 (MAX) user ops active.
   I haven't allowed the cache to grow, simply because I want to get things working
   in the short term.  If users complain, I can certainly revist the implementation!!
 */

int
isc_datatype_from_ptr(void **native_type)
{
    int i;
    api_use_ptrs *local_a0 = active_datatypes->api_declared;
    for (i=0; i< active_datatypes->how_many; i++) {
	if (local_a0[i].mpi_const == *native_type)
	    return i;
    }
    return 0;
}

static inline void
__user_ftn_use_ptrs(int idx, void *a, void *b, int *len, void **datatype)
{
    int abi_type;
    op_intercept_entry_t *intercept = &op_intercepts[idx];
    abi_type = isc_datatype_from_ptr(datatype);
    (*intercept->user_ftn)(a,b,len,&abi_type);
}
void
ABI_User_ftn_use_ptrs_0( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(0,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_1( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(1,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_2( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(2,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_3( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(3,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_4( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(4,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_5( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(5,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_6( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(6,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_7( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(7,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_8( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(8,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_9( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(9,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_10( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(10,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_11( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(11,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_12( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(12,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_13( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(13,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_14( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(14,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_15( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(15,a,b,len,datatype);
}

/* These are the use_ints versions of the intercept functions */

int
isc_datatype_from_int(int *native_type)
{
    int i;
    api_use_ints *local_a0 = active_datatypes->api_declared;
    for (i=0; i< active_datatypes->how_many; i++) {
	if (local_a0[i].mpi_const == *native_type)
	    return i;
    }
    return 0;
}

static inline void
__user_ftn_use_ints(int idx, void *a, void *b, int *len, int *datatype)
{
    int abi_type;
    op_intercept_entry_t *intercept = &op_intercepts[idx];
    abi_type = isc_datatype_from_int(datatype);
    (*intercept->user_ftn)(a,b,len,&abi_type);
}
void
ABI_User_ftn_use_ints_0( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(0,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_1( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(1,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_2( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(2,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_3( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(3,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_4( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(4,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_5( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(5,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_6( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(6,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_7( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(7,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_8( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(8,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_9( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(9,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_10( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(10,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_11( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(11,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_12( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(12,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_13( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(13,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_14( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(14,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_15( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(15,a,b,len,datatype);
}


static MPI_User_function *
next_abi_ftn(int use_ptrs, int active_entries)
{
    switch(active_entries) {
    case 0:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_0;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_0;
	break;
    case 1:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_1;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_1;
	break;
    case 2:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_2;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_2;
	break;
    case 3:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_3;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_3;
	break;
    case 4:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_4;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_4;
	break;
    case 5:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_5;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_5;
	break;
    case 6:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_6;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_6;
	break;
    case 7:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_7;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_7;
	break;
    case 8:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_8;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_8;
	break;
    case 9:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_9;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_9;
       break;
    case 10:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_10;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_10;
	break;
    case 11:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_11;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_11;
	break;
    case 12:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_12;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_12;
	break;
    case 13:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_13;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_13;
	break;
    case 14:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_14;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_14;
	break;
    case 15:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_15;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_15;
	break;
    default:
	puts("Exceeded the new op limit!");
    }
    return NULL;
}


static op_intercept_entry_t *
add_ABI_userftn_intercept(ISC_Op op, MPI_User_function *user_ftn, int use_ptrs )
{
    op_intercept_entry_t *new_intercept = NULL;
    if (op_intercepts == NULL) 
	op_intercepts = (op_intercept_entry_t *)calloc(active_intercept_limit, sizeof(op_intercept_entry_t));
    if (op_intercepts) {
	int next = 0;
	while(op_intercepts[next].op != 0) {
	    next++;
	    if (next == active_intercept_limit)
		return NULL;
	}
	new_intercept = &op_intercepts[next];
	new_intercept->op = op;
	new_intercept->abi_ftn = next_abi_ftn(use_ptrs, active_entries);
	new_intercept->user_ftn = user_ftn;
	new_intercept->index = next;
	active_entries++;
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

int maybe_free_ABI_usrftn_intercept(MPI_Op op)
{
    int i, found = 0;
    for(i = 0; i<active_intercept_limit; i++) {
	if (op_intercepts[i].op == op) {
	    found = 1;
	    op_intercepts[i].op = 0;
	    op_intercepts[i].index = -1;
	    /* NOTE:  We don't delete the user_ftn entry
	     * because some async operations may not have
	     * completed prior to the op_free call!
	     */
	    active_entries--;	    
	    return found;
	}
    }
    return found;
}


int
MPI_Op_create (MPI_User_function *function, int commute, MPI_Op *op)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Op_create")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Op_create",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *op = new_index(active_ops);
  if (active_ops->use_ptrs) { api_use_ptrs *local_a0=active_ops->api_declared;
    int (*VendorMPI_Op_create)(MPI_User_function *function,int commute,void **) = address;
    op_intercept_entry_t *intercept = add_ABI_userftn_intercept(*op, function, 1);
    mpi_return = (*VendorMPI_Op_create)(intercept->abi_ftn, commute,&local_a0[*op].mpi_const);
  } else { api_use_ints *local_a0=active_ops->api_declared;
    int (*VendorMPI_Op_create)(MPI_User_function *function,int commute,int *) = address;
    op_intercept_entry_t *intercept = add_ABI_userftn_intercept(*op, function, 0);
    mpi_return = (*VendorMPI_Op_create)(intercept->abi_ftn,commute,&local_a0[*op].mpi_const);
  }
  return mpi_return;
}
