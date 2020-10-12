
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
static int active_intercept_limit = 64;

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
void
ABI_User_ftn_use_ptrs_16( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(16,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_17( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(17,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_18( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(18,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_19( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(19,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_20( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(20,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_21( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(21,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_22( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(22,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_23( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(23,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_24( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(24,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_25( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(25,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_26( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(26,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_27( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(27,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_28( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(28,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_29( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(29,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_30( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(30,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_31( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(31,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_32( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(32,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_33( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(33,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_34( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(34,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_35( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(35,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_36( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(36,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_37( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(37,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_38( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(38,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_39( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(39,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_40( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(40,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_41( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(41,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_42( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(42,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_43( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(43,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_44( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(44,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_45( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(45,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_46( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(46,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_47( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(47,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_48( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(48,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_49( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(49,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_50( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(50,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_51( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(51,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_52( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(52,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_53( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(53,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_54( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(54,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_55( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(55,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_56( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(56,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_57( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(57,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_58( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(58,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_59( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(59,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_60( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(60,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_61( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(61,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_62( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(62,a,b,len,datatype);
}
void
ABI_User_ftn_use_ptrs_63( void *a, void *b, int *len, void **datatype)
{
    return __user_ftn_use_ptrs(63,a,b,len,datatype);
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
void
ABI_User_ftn_use_ints_16( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(16,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_17( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(17,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_18( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(18,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_19( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(19,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_20( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(20,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_21( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(21,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_22( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(22,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_23( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(23,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_24( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(24,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_25( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(25,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_26( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(26,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_27( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(27,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_28( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(28,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_29( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(29,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_30( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(30,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_31( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(31,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_32( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(32,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_33( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(33,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_34( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(34,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_35( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(35,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_36( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(36,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_37( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(37,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_38( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(38,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_39( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(39,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_40( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(40,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_41( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(41,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_42( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(42,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_43( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(43,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_44( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(44,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_45( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(45,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_46( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(46,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_47( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(47,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_48( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(48,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_49( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(49,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_50( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(50,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_51( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(51,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_52( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(52,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_53( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(53,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_54( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(54,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_55( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(55,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_56( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(56,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_57( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(57,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_58( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(58,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_59( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(59,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_60( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(60,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_61( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(61,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_62( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(62,a,b,len,datatype);
}
void
ABI_User_ftn_use_ints_63( void *a, void *b, int *len, int *datatype)
{
    return __user_ftn_use_ints(63,a,b,len,datatype);
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
    case 16:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_16;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_16;
	break;
    case 17:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_17;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_17;
	break;
    case 18:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_18;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_18;
	break;
    case 19:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_19;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_19;
	break;
    case 20:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_20;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_20;
	break;
    case 21:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_21;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_21;
	break;
    case 22:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_22;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_22;
	break;
    case 23:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_23;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_23;
	break;
    case 24:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_24;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_24;
	break;
    case 25:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_25;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_25;
       break;
    case 26:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_26;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_26;
	break;
    case 27:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_27;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_27;
	break;
    case 28:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_28;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_28;
	break;
    case 29:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_29;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_29;
	break;
    case 30:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_30;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_30;
	break;
    case 31:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_31;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_31;
	break;
    case 32:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_32;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_32;
	break;
    case 33:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_33;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_33;
	break;
    case 34:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_34;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_34;
	break;
    case 35:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_35;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_35;
	break;
    case 36:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_36;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_36;
	break;
    case 37:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_37;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_37;
	break;
    case 38:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_38;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_38;
	break;
    case 39:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_39;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_39;
	break;
    case 40:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_40;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_40;
	break;
    case 41:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_41;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_41;
	break;
    case 42:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_42;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_42;
       break;
    case 43:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_43;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_43;
	break;
    case 44:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_44;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_44;
	break;
    case 45:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_45;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_45;
	break;
    case 46:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_46;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_46;
	break;
    case 47:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_47;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_47;
	break;
    case 48:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_48;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_48;
	break;
    case 49:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_49;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_49;
	break;
    case 50:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_50;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_50;
	break;
    case 51:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_51;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_51;
	break;
    case 52:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_52;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_52;
	break;
    case 53:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_53;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_53;
	break;
    case 54:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_54;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_54;
	break;
    case 55:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_55;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_55;
	break;
    case 56:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_56;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_56;
	break;
    case 57:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_57;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_57;
	break;
    case 58:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_58;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_58;
       break;
    case 59:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_59;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_59;
	break;
    case 60:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_60;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_60;
	break;
    case 61:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_61;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_61;
	break;
    case 62:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_62;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_62;
	break;
    case 63:
	if (use_ptrs)
	    return (MPI_User_function *)ABI_User_ftn_use_ptrs_63;
	else return (MPI_User_function *)ABI_User_ftn_use_ints_63;
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
		new_intercept->abi_ftn = next_abi_ftn(use_ptrs, next);
		new_intercept->user_ftn = user_ftn;
		new_intercept->index = next;
		if (next == active_entries)
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
	    if (i == active_entries)
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
