
#ifndef _ISCMPI_CONSTANTS
#define _ISCMPI_CONSTANTS

#if defined(__cplusplus)
extern "C" {
#endif


typedef enum {
	ISC_COMM_NULL = 0,
	ISC_COMM_WORLD,
	ISC_COMM_SELF,
	predefined_comm_count
} _isc_comms;


typedef enum {
	ISC_GROUP_NULL = 0,
	ISC_GROUP_EMPTY,
	predefined_group_count
} _isc_groups;


typedef enum {
        ISC_REQUEST_NULL = 0,
	predefined_request_count
} _isc_requests;

typedef enum {
	ISC_OP_NULL	= 0,
	ISC_MAX,
	ISC_MIN,
	ISC_SUM,
	ISC_PROD,
	ISC_LAND,
	ISC_BAND,
	ISC_LOR,
	ISC_BOR,
	ISC_LXOR,
	ISC_BXOR,
	ISC_MAXLOC,
	ISC_MINLOC,
	ISC_REPLACE,
	ISC_NO_OP,
	predefined_op_count
} _isc_ops;

typedef enum {
	ISC_DATATYPE_NULL = 0,
	ISC_CHAR,		/* 1 */
	ISC_SHORT,		/* 2 */
	ISC_INT,		/* 3 */
	ISC_LONG,		/* 4 */
        ISC_SIGNED_CHAR,	/* 5 */
	ISC_UNSIGNED_CHAR,	/* 6 */
	ISC_UNSIGNED_SHORT,	/* 7 */
	ISC_UNSIGNED,		/* 8 */
	ISC_UNSIGNED_LONG,	/* 9 */
	ISC_FLOAT,		/* 10 */
	ISC_DOUBLE,		/* 11 */
	ISC_LONG_DOUBLE,	/* 12 */
	ISC_LONG_LONG,		/* 13 */
	ISC_LONG_LONG_INT,	/* 14 */
	ISC_UNSIGNED_LONG_LONG,	/* 15 */
	ISC_INTEGER,		/* 16 */
	ISC_REAL,		/* 17 */
	ISC_DOUBLE_PRECISION,	/* 18 */
	ISC_COMPLEX,		/* 19 */
	ISC_DOUBLE_COMPLEX,	/* 20 */
	ISC_LOGICAL,		/* 21 */
	ISC_CHARACTER,		/* 22 */
	ISC_INTEGER1,		/* 23 */
	ISC_INTEGER2,		/* 24 */
	ISC_INTEGER4,		/* 25 */
	ISC_INTEGER8,		/* 26 */
	ISC_REAL4,		/* 27 */
	ISC_REAL8,		/* 28 */
	ISC_REAL16,		/* 29 */
	ISC_BYTE,		/* 30 */
	ISC_PACKED,		/* 31 */
	ISC_UB,			/* 32 */
	ISC_LB,			/* 33 */
	ISC_FLOAT_INT,		/* 34 */
	ISC_DOUBLE_INT,		/* 35 */
	ISC_LONG_INT,		/* 36 */
	ISC_2INT,		/* 37 */
	ISC_SHORT_INT,		/* 38 */
	ISC_LONG_DOUBLE_INT,	/* 39 */
	ISC_2REAL,		/* 40 */
	ISC_2DOUBLE_PRECISION,	/* 41 */
	ISC_2INTEGER,		/* 42 */
	ISC_COMPLEX8,		/* 43 */
	ISC_COMPLEX16,		/* 44 */
	ISC_COMPLEX32,		/* 45 */
        ISC_WCHAR,		/* 46 */
        ISC_C_BOOL,             /* 47 */
        ISC_C_FLOAT_COMPLEX,	/* 48 */
        ISC_C_DOUBLE_COMPLEX,	/* 49 */
        ISC_C_LONG_DOUBLE_COMPLEX, /* 50 */
	ISC_AINT,		/* 51 */
	ISC_OFFSET,		/* 52 */
	ISC_COUNT,		/* 53 */
	ISC_INT8_T,		/* 54 */
	ISC_INT16_T,		/* 55 */
	ISC_INT32_T,		/* 56 */
	ISC_INT64_T,		/* 57 */
	ISC_UINT8_T,		/* 58 */
	ISC_UINT16_T,		/* 59 */
	ISC_UINT32_T,		/* 60 */
	ISC_UINT64_T,		/* 61 */
#if defined(HAVE_MPI_INTEGER16)
	ISC_INTEGER16,		/* 62 */
#endif
	predefined_datatype_count
} _isc_datatypes;



typedef enum {
        ISC_SUCCESS = 0,
	ISC_ERR_BUFFER,
	ISC_ERR_COUNT,
	ISC_ERR_TYPE,
	ISC_ERR_TAG,
	ISC_ERR_COMM,
	ISC_ERR_RANK,
	ISC_ERR_ROOT,
	ISC_ERR_GROUP,
	ISC_ERR_OP,
	ISC_ERR_TOPOLOGY,
	ISC_ERR_DIMS,
	ISC_ERR_ARG,
	ISC_ERR_UNKNOWN,
	ISC_ERR_TRUNCATE,
	ISC_ERR_OTHER,
	ISC_ERR_INTERN,
	ISC_ERR_IN_STATUS,
	ISC_ERR_PENDING,
	ISC_ERR_REQUEST,
	ISC_ERR_ACCESS,
	ISC_ERR_AMODE,
	ISC_ERR_BAD_FILE,
	ISC_ERR_CONVERSION,
	ISC_ERR_DUP_DATAREP,
	ISC_ERR_FILE_EXISTS,
	ISC_ERR_FILE_IN_USE,
	ISC_ERR_FILE,
	ISC_ERR_INFO,
	ISC_ERR_INFO_KEY,
	ISC_ERR_INFO_VALUE,
	ISC_ERR_INFO_NOKEY,
	ISC_ERR_IO,
	ISC_ERR_NAME,
	ISC_ERR_NO_MEM,
	ISC_ERR_NOT_SAME,
	ISC_ERR_NO_SPACE,
	ISC_ERR_NO_SUCH_FILE,
	ISC_ERR_PORT,
	ISC_ERR_QUOTA,
	ISC_ERR_READ_ONLY,
	ISC_ERR_SERVICE,
	ISC_ERR_SPAWN,
	ISC_ERR_UNSUPPORTED_DATAREP,
	ISC_ERR_UNSUPPORTED_OPERATION,
	ISC_ERR_WIN,
	ISC_ERR_BASE,
	ISC_ERR_LOCKTYPE,
	ISC_ERR_KEYVAL,
	ISC_ERR_RMA_CONFLICT,
	ISC_ERR_RMA_SYNC,
	ISC_ERR_SIZE,
	ISC_ERR_DISP,
	ISC_ERR_ASSERT,
	ISC_ERR_RMA_RANGE,
	ISC_ERR_RMA_ATTACH,
	ISC_ERR_RMA_SHARED,
	ISC_ERR_RMA_FLAVOR,
	ISC_ERR_LASTCODE,
	predefined_error_count
} _isc_errors;

typedef enum {
	ISC_ERRHANDLER_NULL = 0,
	ISC_ERRORS_ARE_FATAL,
	ISC_ERRORS_RETURN,
	predefined_errhandler_count
} _isc_error_handlers;

typedef enum {
        ISC_INFO_NULL = 0,
	ISC_INFO_ENV,
	predefined_info_count
} _isc_infos;

typedef enum {
        ISC_WIN_NULL = 0,
	predefined_win_count
} _isc_wins;

typedef enum {
        ISC_FILE_NULL = 0,
	predefined_file_count
} _isc_files;

typedef enum {
        ISC_MESSAGE_NULL_ = 0,
        ISC_MESSAGE_NO_PROC_ = 1,
        predefined_msg_count
} _isc_msgs;

typedef enum {
	ISC_PROC_NULL_= 0,	/* 0 special with trailing underscore */
        ISC_ANY_SOURCE_,	/* 1 special.. */
	ISC_ANY_TAG_,		/* 2 special.. */
	ISC_ROOT_,		/* 3 special.. */
	ISC_UNDEFINED_,		/* 4 special.. */
	ISC_KEYVAL_INVALID_,	/* 5 special.. */
	ISC_TAG_UB,		/* 6 */
	ISC_HOST,		/* 7 */
	ISC_IO,			/* 8 */
	ISC_WTIME_IS_GLOBAL,	/* 9 */
	ISC_ORDER_C,		/* 10 */
	ISC_ORDER_FORTRAN,	/* 11 */
	ISC_DISTRIBUTE_BLOCK,	/* 12 */
	ISC_DISTRIBUTE_CYCLIC,	/* 13 */
	ISC_DISTRIBUTE_NONE,	/* 14 */
	ISC_DISTRIBUTE_DFLT_DARG, /* 15 */
	ISC_CART,		/* 16 */
	ISC_GRAPH,		/* 17 */
	ISC_COMBINER_NAMED,	/* 18 */
	ISC_COMBINER_DUP,	/* 19 */
	ISC_COMBINER_CONTIGUOUS, /* 20 */
	ISC_COMBINER_VECTOR,	/* 21 */
	ISC_COMBINER_HVECTOR_INTEGER, /* 22 */
	ISC_COMBINER_HVECTOR,	/* 23 */
	ISC_COMBINER_INDEXED,	/* 24 */
	ISC_COMBINER_HINDEXED_INTEGER, /* 25 */
	ISC_COMBINER_HINDEXED,	/* 26 */
	ISC_COMBINER_INDEXED_BLOCK, /* 27 */
	ISC_COMBINER_STRUCT_INTEGER, /* 28 */
	ISC_COMBINER_STRUCT,	/* 29 */
	ISC_COMBINER_SUBARRAY,	/* 30 */
	ISC_COMBINER_DARRAY,	/* 31 */
	ISC_COMBINER_F90_REAL,	/* 32 */
	ISC_COMBINER_F90_COMPLEX, /* 33 */
	ISC_COMBINER_F90_INTEGER, /* 34 */
	ISC_COMBINER_RESIZED,	/* 35 */
	ISC_APPNUM,		/* 36 */
        ISC_LASTUSEDCODE,       /* 37 */
	ISC_UNIVERSE_SIZE,	/* 38 */
	ISC_WIN_BASE,		/* 39 */
	ISC_WIN_SIZE,	        /* 40 */
	ISC_WIN_DISP_UNIT,      /* 41 */
        ISC_DISPLACEMENT_CURRENT, /* 42 */
	ISC_LOCK_EXCLUSIVE,	  /* 43 */
	ISC_LOCK_SHARED,	  /* 44 */
	ISC_SEEK_SET,		  /* 45 */
	ISC_SEEK_CUR,             /* 46 */
	ISC_SEEK_END,             /* 47 */
	ISC_COMM_TYPE_SHARED,	  /* 48 */
	ISC_DIST_GRAPH,		  /* 49 */
	/* FLAVORS */
	ISC_WIN_FLAVOR_CREATE,	  /* 50 */
	ISC_WIN_FLAVOR_ALLOCATE,  /* 51 */
	ISC_WIN_FLAVOR_DYNAMIC,	  /* 52 */
	ISC_WIN_FLAVOR_SHARED,	  /* 53 */
	/* MODELS */
	ISC_WIN_SEPARATE,	  /* 54 */
	ISC_WIN_UNIFIED,	  /* 55 */
        ISC_WIN_CREATE_FLAVOR,	  /* 56 */
	ISC_WIN_MODEL,		  /* 57 */
	predefined_misc_count
} _isc_misc;

typedef enum {
  ISC_MODE_UNUSED_ = 0,		   /* bitfields don't allow 0s */
	ISC_MODE_CREATE_,          /* 1 */
	ISC_MODE_RDONLY_,          /* 2 */
	ISC_MODE_WRONLY_,          /* 4 */
	ISC_MODE_RDWR_,	           /* 8 */
	ISC_MODE_DELETE_ON_CLOSE_, /* 16 */
	ISC_MODE_UNIQUE_OPEN_,     /* 32 */
	ISC_MODE_EXCL_,	           /* 64 */
	ISC_MODE_APPEND_,	   /* 128 */
	ISC_MODE_SEQUENTIAL_,	   /* 256 */
        prefined_amodebitfield_count
} _isc_amodebitfield;

#define	ISC_MODE_CREATE            1
#define	ISC_MODE_RDONLY            2
#define	ISC_MODE_WRONLY            4
#define	ISC_MODE_RDWR	           8
#define	ISC_MODE_DELETE_ON_CLOSE   16
#define	ISC_MODE_UNIQUE_OPEN       32
#define	ISC_MODE_EXCL	           64
#define	ISC_MODE_APPEND	           128
#define	ISC_MODE_SEQUENTIAL	   256


typedef enum {
  ISC_MODE_UNUSED__ = 0,	   /* bitfields don't allow 0s */
	ISC_MODE_NOCHECK_,         /* 1 */
	ISC_MODE_NOPRECEDE_,       /* 2 */
	ISC_MODE_NOPUT_,           /* 4 */
	ISC_MODE_NOSTORE_,	   /* 8 */
	ISC_MODE_NOSUCCEED_,	   /* 16 */
        predefined_winassertbitfield_count
} _isc_winassertbitfield;

#define	ISC_MODE_NOCHECK           1
#define	ISC_MODE_NOPRECEDE         2
#define	ISC_MODE_NOPUT             4
#define	ISC_MODE_NOSTORE	   8
#define	ISC_MODE_NOSUCCEED	   16


#define ISC_PROC_NULL  -1
#define ISC_ANY_SOURCE -2
#define ISC_ANY_TAG    -3
#define ISC_ROOT       -4
#define ISC_UNDEFINED  -5
#define ISC_KEYVAL_INVALID -6
#define ISC_MESSAGE_NULL -7
#define ISC_MESSAGE_NO_PROC -8  


typedef enum {
	ISC_IDENT		= 0,
	ISC_CONGRUENT		= 1,
	ISC_SIMILAR		= 2,
	ISC_UNEQUAL		= 3
} _isc_compare;

typedef enum {
        null_addr = 0,
	ISC_BOTTOM = 1,		/* Not to be confused with a NULL pointer */
	ISC_IN_PLACE,
	ISC_ARGV_NULL,
	ISC_ARGVS_NULL,
	ISC_ERRCODES_IGNORE,
	ISC_STATUS_IGNORE,
	ISC_NULL_COPY_FN,
	ISC_NULL_DELETE_FN,
	ISC_UNWEIGHTED,
	ISC_WEIGHTS_EMPTY,
	predefined_ptr_count
} _isc_addr;

#define ISC_STATUSES_IGNORE ISC_STATUS_IGNORE;
#define	ISC_MAX_PROCESSOR_NAME 256
#define	ISC_MAX_ERROR_STRING 512
#define	ISC_MAX_OBJECT_NAME 256
#define	ISC_BSEND_OVERHEAD 256
#define	ISC_MAX_INFO_KEY 256
#define	ISC_MAX_INFO_VAL 256
#define	ISC_MAX_PORT_NAME 256
#define ISC_MAX_DATAREP_STRING 128
#define ISC_MAX_LIBRARY_VERSION_STRING 8192
#define ISC_INT32MASK 0X0FFFFFFFF


/* Thread level definitions are actually common across the supported set 
 * of vendor MPI implmentations... 8-)
 */
typedef enum {
	ISC_THREAD_SINGLE = 0,
	ISC_THREAD_FUNNELED,
	ISC_THREAD_SERIALIZED,
	ISC_THREAD_MULTIPLE,
} _isc_thread;


typedef enum {
  ISC_TYPECLASS_REAL            = 1,
  ISC_TYPECLASS_INTEGER         = 2,
  ISC_TYPECLASS_COMPLEX         = 3
} _isc_typeclass;

typedef struct _api_use_ints {
  int	self;
  char  *MPI_name;
  unsigned int mpi_const;
} api_use_ints;

typedef struct _api_use_ptrs {
  int	self;
  char  *MPI_name;
  void  *mpi_const;
} api_use_ptrs;


#ifndef CALLBACK_TYPES_DEFINED
#define CALLBACK_TYPES_DEFINED 3

typedef enum {
  COMM_CALLBACK=1,
  DATATYPE_CALLBACK=2,
  WIN_CALLBACK=3
} callback_t;

#endif

typedef struct _isc_const {
  int use_ptrs;
  int how_many;
  int limit;
  int permlimit;
  void *api_declared;
  void *freed;
} isc_const;

typedef struct _isc_freelist {
  struct _isc_freelist *next;
  void *element;
} isc_freelist;

extern int *ISC_F_STATUS_IGNORE;
extern int *ISC_F_STATUSES_IGNORE;
extern void *MPIO_libhandle;
extern void *MPI_libhandle;
extern void *ISC_maphandle;
extern isc_const *active_comms;
extern isc_const *active_groups;
extern isc_const *active_requests;
extern isc_const *active_ops;
extern isc_const *active_datatypes;
extern isc_const *active_errhandlers;
extern isc_const *active_infos;
extern isc_const *active_wins;
extern isc_const *active_files;
extern isc_const *active_errcodes;
extern isc_const *active_miscs;
extern isc_const *active_addrs;
extern isc_const *active_msgs;
extern isc_const *active_amodebitfield;
extern isc_const *active_winassertbitfield;


extern int new_index(isc_const *);
extern void expand_store(isc_const *, int);
extern void free_index(isc_const *, int);
extern int get_index(isc_const *, void *);

extern int (*native_status_to_isc_no_error)(int count, int *native_stat, int *isc_stat);
extern int (*native_status_to_isc)(int count, int *native_stat, int *isc_stat);
extern int (*isc_status_to_native)(int count, int *isc_stat, int *native_stat);

extern int (*status_source_setter)(int *isc_stat, int source);
extern int (*status_source_getter)(int *isc_stat, int *source);
extern int (*status_tag_setter)(int *isc_stat, int tag);
extern int (*status_tag_getter)(int *isc_stat, int *tag);
extern int (*status_error_setter)(int *isc_stat, int error);
extern int (*status_error_getter)(int *isc_stat, int *error);

/* Cache these interesting values */
extern int isc_mpi_rank;
extern int isc_mpi_size;


#define SYM_MISSING_PREFIX "Unable to locate the MPI entrypoint"
#define SYM_MISSING_TRAILER "\nDoes your native MPI implementation support this?\n"

#if defined(__cplusplus)
}
#endif

#endif	/* _ISCMPI_CONSTANTS */
