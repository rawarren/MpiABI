
/*
  Overview::
  This file, along with it's partner "iscmpi_constants.h", will be used
  to capture the contents of the vendor declarations typically found
  in their "mpi.h" file. These declarations encompass the MPI constants
  defined by the MPI-1 and 2 standards and used by MPI programmers.
  Examples of such constants are MPI_COMM_WORLD and MPI_INT which
  define respectively a communicator comprised of all application
  processes, and an MPI datatype which has the size of a
  'C' integer.   

  We'll compile this file utilizing the vendor "mpi.h" include file
  in order to create a dynamically loadable shared library, e.g.

  cc -g -DAPI_USES_POINTERS -fPIC -shared -IVENDOR_MPI/include\
   iscmpi_mapping.c -o isc_mapping_vendormpi.so

  Note that compilation also specifies whether the MPI implementation
  uses pointers.  The default is to use integers for things such
  as MPI_Comm or MPI_Datatype.  One should verify the implementation
  by searching for the typedef which is normally included in mpi.h.
  Here are two examples:

  OpenMPI defines MPI_Datatype as:
    typedef struct ompi_datatype_t *MPI_Datatype;

  whereas MPICH-1 and MPICH-2 both define it as follows:
    typedef int MPI_Datatype;

  The former would require the -DAPI_USES_POINTERS definition
  to perform correctly, while the latter *must avoid* defining
  this compilation variable.

  **********
  ** NOTE **
  **********
  ROMIO is a free package from Argonne labs which implements
  much of the the MPI-IO standard, which layers on top of MPI.
  Because of this, ROMIO is a very common add package. 
  Both versions of MPICH use integers for the majority of their
  user visable objects but ROMIO is defined in terms of a
  structure pointer for it's base MPI_File object.  Because of
  this, we default the MPI_File object to be a pointer API
  unless one defines -DINTEGER_FILE_TYPE

  We look one key define which is set in the MPICH
  based implementations, MPICH_NAME if it exists, will
  have a value of either 1 or 2 depending one which
  version we compile against ;-)

  **********
  ** USE  **
  **********

  Ultimately, the MPI_Init function in libiscmpi opens the mapping
  library with dlopen by referencing the name "isc_mapping.so".
  As a result, the installation process needs to create a symbolic
  link in the directory containg libiscmpi.so to then mapping library
  we've created here, e.g.

  cd $libdir; ln -s <some-path>/isc_mapping_vendormpi.so ./isc_mapping.so

*/

#ifndef _ISCMPI_MAPPING
#define _ISCMPI_MAPPING

#include <stdio.h>

#include "iscmpi_constants.h"	/* This typically enumerates the ISC_xxx
				 * constants as well as supplying typedefs
				 * for "api_use_ints" and "api_use_ptrs".
				 * the predefined_xxx_count falls out
				 * from the enum structures ;-) */

#include "mpi.h"		/* IMPORTANT!!!
				 * This needs to be the vendor MPI.H */

#ifndef NULL
#define NULL (void *)0
#endif

/* Suggested improvement by Alan Billing is to embed the vendor
 * library name in the mapping library.  This puts the burden
 * of determining the default naming on the person who is porting
 * to a new platform.  We propose the default to be::
 */
#ifndef VENDOR_MPI_SO
#define VENDOR_MPI_SO "libmpi.so"
#endif

#if defined(MPICH_NAME)
#  if MPICH_NAME > 1
/* I guess MPICH2 is pretty complete... */

#  else
/* MPICH-1 doesn't auto include MPI-IO */
#    include "mpio.h"
#    define USE_REQUEST_POINTER 1
#    define USE_INFO_POINTER 1

/* Nor does it define a bunch of datatypes */
#    define MPI_INTEGER1 MPI_DATATYPE_NULL
#    define MPI_INTEGER2 MPI_DATATYPE_NULL
#    define MPI_INTEGER4 MPI_DATATYPE_NULL
#    define MPI_INTEGER8 MPI_DATATYPE_NULL
#    define MPI_INTEGER16 MPI_DATATYPE_NULL
#    define MPI_REAL4 MPI_DATATYPE_NULL
#    define MPI_REAL8 MPI_DATATYPE_NULL
#    define MPI_REAL16 MPI_DATATYPE_NULL
#    define MPI_COMPLEX8 MPI_DATATYPE_NULL
#    define MPI_COMPLEX16 MPI_DATATYPE_NULL
#    define MPI_COMPLEX32 MPI_DATATYPE_NULL

/* MPICH 1 doesn't support MPI_REPLACE as an OP type */
#    define MPI_REPLACE MPI_OP_NULL

/* MPICH 1 doesn't support RMA stuff */
#    define MPI_WIN_NULL 0

/* Missing error codes */
#    define MPI_ERR_ASSERT MPI_ERR_UNKNOWN 
#    define MPI_ERR_BASE  MPI_ERR_UNKNOWN 
#    define MPI_ERR_DISP  MPI_ERR_UNKNOWN 
#    define MPI_ERR_KEYVAL  MPI_ERR_UNKNOWN
#    define MPI_ERR_LOCKTYPE  MPI_ERR_UNKNOWN 
#    define MPI_ERR_RMA_CONFLICT  MPI_ERR_UNKNOWN 
#    define MPI_ERR_RMA_SYNC  MPI_ERR_UNKNOWN 
#    define MPI_ERR_SIZE  MPI_ERR_UNKNOWN 
#    define MPI_MAX_OBJECT_NAME  MPI_MAX_NAME_STRING

/* MPICH 1 doesn't define these either */
#    define MPI_IN_PLACE 0
#    define MPI_ARGV_NULL 0
#    define MPI_ARGVS_NULL 0
#    define MPI_ERRCODES_IGNORE 0
#  endif
#endif

#if defined(SGI)		/* This needs to be set on the compile line! */

/*   See the maybe_do_lazy_evaluations() function in this file
 *   to see some more detail.
 */
void __resolve_fdtype(int isc_index, int ftnvalue);
void __resolve_ptr_builtin(int isc_index, char *symbol);


/* SGI MPI doesn't support the MPI_REPLACE op */
#    define MPI_REPLACE MPI_OP_NULL
/* There are a couple of datatypes that we reference that SGI doesn't support */
#    define MPI_SIGNED_CHAR MPI_CHAR
#    define MPI_UNSIGNED_LONG_LONG MPI_LONG_LONG

/*
 * A few more constants which we use to fill out the MPI-2 declarations,
 * but which are missing on SGI (but not for SGI_ICE)
 *
 */
#ifndef MPI_ROOT
#    define MPI_ROOT 0
#endif
#ifndef MPI_MAX_OBJECT_NAME
#    define MPI_MAX_OBJECT_NAME MPI_MAX_ERROR_STRING
#endif
#ifndef MPI_MAX_PORT_NAME
#    define MPI_MAX_PORT_NAME MPI_MAX_ERROR_STRING
#endif

#    define LAZY_RESOLVE_1 __resolve_ptr_builtin(ISC_IN_PLACE,"mpi_sgi_inplace")
#    undef MPI_IN_PLACE
#    define MPI_IN_PLACE ((void *)0x007babe)
#    define LAZY_RESOLVE_2 __resolve_ptr_builtin(ISC_STATUS_IGNORE,"mpi_sgi_status_ignore")
#    undef MPI_STATUS_IGNORE
#    define MPI_STATUS_IGNORE ((void *)0x007babe)

#elif defined(HP_MPI)
#    define API_USES_POINTERS 1
/*
 *   FIXME::
 *   HPMPI defines the Fortran types in 'C" by calling MPI_Type_f2c
 *   on the fortran integer value.  I'm not sure how to code
 *   this in a simple way...
 *
 *   See the maybe_do_lazy_evaluations() function in this file
 *   to see some more detail.
 */
void __resolve_fdtype(int isc_index, int ftnvalue);
void __resolve_ptr_builtin(int isc_index, char *symbol);

#    define LAZY_RESOLVE_1 __resolve_fdtype(ISC_INTEGER,MPIF_INTEGER)
#    undef MPI_INTEGER
#    define MPI_INTEGER MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_2 __resolve_fdtype(ISC_REAL,MPIF_REAL)
#    undef MPI_REAL
#    define MPI_REAL MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_3 __resolve_fdtype(ISC_DOUBLE_PRECISION,MPIF_DOUBLE_PRECISION)
#    undef MPI_DOUBLE_PRECISION
#    define MPI_DOUBLE_PRECISION MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_4 __resolve_fdtype(ISC_COMPLEX,MPIF_COMPLEX)
#    undef MPI_COMPLEX
#    define MPI_COMPLEX MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_5 __resolve_fdtype(ISC_LOGICAL,MPIF_LOGICAL)
#    undef MPI_LOGICAL
#    define MPI_LOGICAL MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_6 __resolve_fdtype(ISC_CHARACTER,MPIF_CHARACTER)
#    undef MPI_CHARACTER
#    define MPI_CHARACTER MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_7 __resolve_fdtype(ISC_DOUBLE_COMPLEX,MPIF_DOUBLE_COMPLEX)
#    undef MPI_DOUBLE_COMPLEX
#    define MPI_DOUBLE_COMPLEX MPI_DATATYPE_NULL
/*
 *   The following aren't defined for 'C' in the HP mpi header.
 *   The values supplied below come from the mpif.h file (Ugh!)
 */
#    define LAZY_RESOLVE_8 __resolve_fdtype(ISC_INTEGER1,28)
#    define MPI_INTEGER1 MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_9 __resolve_fdtype(ISC_INTEGER2,29)
#    define MPI_INTEGER2 MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_10 __resolve_fdtype(ISC_INTEGER4,30)
#    define MPI_INTEGER4 MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_11 __resolve_fdtype(ISC_INTEGER8,36)
#    define MPI_INTEGER8 MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_12 __resolve_fdtype(ISC_REAL4,31)
#    define MPI_REAL4 MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_13 __resolve_fdtype(ISC_REAL8,32)
#    define MPI_REAL8 MPI_DATATYPE_NULL
#    define LAZY_RESOLVE_14 __resolve_fdtype(ISC_REAL16,37)
#    define MPI_REAL16 MPI_DATATYPE_NULL

/*
 *   Handling of MPI_BOTTOM and MPI_IN_PLACE
 *   CAUTION WITH THESE!!!
 */
#    undef MPI_BOTTOM
#    define MPI_BOTTOM ((void *)0)
#    define LAZY_RESOLVE_15 __resolve_ptr_builtin(ISC_IN_PLACE,"hpmp_f_mpi_in_place")
#    undef MPI_IN_PLACE
#    define MPI_IN_PLACE ((void *)0x007babe)

#elif defined(OPENMPI)
extern void __resolve_fdtype(int , int);
#    define API_USES_POINTERS 1
#    define LAZY_RESOLVE_1 __resolve_fdtype(ISC_REAL16,0)
#endif

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *  Declarations below the #ifdef API_USES_POINTERS
 *  use pointers to the MPI base objects
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */
#ifdef API_USES_POINTERS
#define UNDEFINED_PTR ((void *)0) /* Just in case we need it... */
/*
 +++++++++++++++++
 * COMMUNICATORS
 +++++++++++++++++
 */
api_use_ptrs comm_builtins[] = {
    {ISC_COMM_NULL,"MPI_COMM_NULL", MPI_COMM_NULL},
    {ISC_COMM_WORLD,"MPI_COMM_WORLD",MPI_COMM_WORLD},
    {ISC_COMM_SELF,"MPI_COMM_SELF",MPI_COMM_SELF}
};

isc_const isc_builtin_comms = { 1, /* Use pointers */
			predefined_comm_count,
			predefined_comm_count,
			predefined_comm_count,
			comm_builtins,
			NULL
};

/*
 +++++++++++++++++
 * GROUPS
 +++++++++++++++++
 */
api_use_ptrs group_builtins[] = {
    {ISC_GROUP_NULL,"MPI_GROUP_NULL", MPI_GROUP_NULL},
    {ISC_GROUP_EMPTY,"MPI_GROUP_EMPTY",MPI_GROUP_EMPTY}
};

isc_const isc_builtin_groups = { 1, /* Use pointers */
			predefined_group_count,
			predefined_group_count,
			predefined_group_count,
			group_builtins,
			NULL
};

/*
 +++++++++++++++++
 * REQUESTS
 +++++++++++++++++
 */
api_use_ptrs request_builtins[] = {
  {ISC_REQUEST_NULL,"MPI_REQUEST_NULL", MPI_REQUEST_NULL}
};

isc_const isc_builtin_requests = { 1, /* Use pointers */
			predefined_request_count,
			predefined_request_count,
			predefined_request_count,
			request_builtins, 
			NULL
};

/*
 +++++++++++++++++
 * OPS
 +++++++++++++++++
 */
api_use_ptrs op_builtins[] = {
    {ISC_OP_NULL,"MPI_OP_NULL",MPI_OP_NULL},
    {ISC_MAX,"MPI_MAX",MPI_MAX},
    {ISC_MIN,"MPI_MIN",MPI_MIN},
    {ISC_SUM,"MPI_SUM",MPI_SUM},
    {ISC_PROD,"MPI_PROD",MPI_PROD},
    {ISC_LAND,"MPI_LAND",MPI_LAND},
    {ISC_BAND,"MPI_BAND",MPI_BAND},
    {ISC_LOR,"MPI_LOR",MPI_LOR},
    {ISC_BOR,"MPI_BOR",MPI_BOR},
    {ISC_LXOR,"MPI_LXOR",MPI_LXOR},
    {ISC_BXOR,"MPI_BXOR",MPI_BXOR},
    {ISC_MAXLOC,"MPI_MAXLOC",MPI_MAXLOC},
    {ISC_MINLOC,"MPI_MINLOC",MPI_MINLOC},
    {ISC_REPLACE,"MPI_REPLACE",MPI_REPLACE}
};

isc_const isc_builtin_ops = { 1, /* Use pointers */
			predefined_op_count,
			predefined_op_count,
			predefined_op_count,
			op_builtins,
			NULL
};

/*
 +++++++++++++++++
 * DATATYPES
 +++++++++++++++++
 */

#ifndef MPI_REAL16  /* CAUTION:: Unsupported on some platforms */	
#define MPI_REAL16 UNDEFINED_PTR
#endif

api_use_ptrs dtype_builtins[] = {
    {ISC_DATATYPE_NULL,"MPI_DATATYPE_NULL", MPI_DATATYPE_NULL},
    {ISC_CHAR,"MPI_CHAR",MPI_CHAR},
    {ISC_SHORT,"MPI_SHORT",MPI_SHORT},
    {ISC_INT,"MPI_INT",MPI_INT},
    {ISC_LONG,"MPI_LONG",MPI_LONG},
    {ISC_SIGNED_CHAR, "MPI_SIGNED_CHAR" , MPI_SIGNED_CHAR},
    {ISC_UNSIGNED_CHAR,"MPI_UNSIGNED_CHAR",MPI_UNSIGNED_CHAR},
    {ISC_UNSIGNED_SHORT,"MPI_UNSIGNED_SHORT",MPI_UNSIGNED_SHORT},
    {ISC_UNSIGNED,"MPI_UNSIGNED",MPI_UNSIGNED},
    {ISC_UNSIGNED_LONG,"MPI_UNSIGNED_LONG",MPI_UNSIGNED_LONG},
    {ISC_FLOAT,"MPI_FLOAT",MPI_FLOAT},
    {ISC_DOUBLE,"MPI_DOUBLE",MPI_DOUBLE},
    {ISC_LONG_DOUBLE,"MPI_LONG_DOUBLE",MPI_LONG_DOUBLE},
    {ISC_LONG_LONG,"MPI_LONG_LONG",MPI_LONG_LONG},
    {ISC_LONG_LONG_INT,"MPI_LONG_LONG_INT",MPI_LONG_LONG_INT},
    {ISC_UNSIGNED_LONG_LONG,"MPI_UNSIGNED_LONG_LONG",MPI_UNSIGNED_LONG_LONG},
    {ISC_INTEGER,"MPI_INTEGER",MPI_INTEGER},
    {ISC_REAL,"MPI_REAL",MPI_REAL},
    {ISC_DOUBLE_PRECISION,"MPI_DOUBLE_PRECISION",MPI_DOUBLE_PRECISION},
    {ISC_COMPLEX,"MPI_COMPLEX",MPI_COMPLEX},
    {ISC_DOUBLE_COMPLEX,"MPI_DOUBLE_COMPLEX",MPI_DOUBLE_COMPLEX},
    {ISC_LOGICAL,"MPI_LOGICAL",MPI_LOGICAL},
    {ISC_CHARACTER,"MPI_CHARACTER",MPI_CHARACTER},
    {ISC_INTEGER1,"MPI_INTEGER1",MPI_INTEGER1},
    {ISC_INTEGER2,"MPI_INTEGER2",MPI_INTEGER2},
    {ISC_INTEGER4,"MPI_INTEGER4",MPI_INTEGER4},
    {ISC_INTEGER8,"MPI_INTEGER8",MPI_INTEGER8},
    {ISC_REAL4,"MPI_REAL4",MPI_REAL4},
    {ISC_REAL8,"MPI_REAL8",MPI_REAL8},
    {ISC_REAL16,"MPI_REAL16",MPI_REAL16},
    {ISC_BYTE,"MPI_BYTE",MPI_BYTE},
    {ISC_PACKED,"MPI_PACKED",MPI_PACKED},
    {ISC_UB,"MPI_UB",MPI_UB},
    {ISC_LB,"MPI_LB",MPI_LB},
    {ISC_FLOAT_INT,"MPI_FLOAT_INT",MPI_FLOAT_INT},
    {ISC_DOUBLE_INT,"MPI_DOUBLE_INT",MPI_DOUBLE_INT},
    {ISC_LONG_INT,"MPI_LONG_INT",MPI_LONG_INT},
    {ISC_2INT,"MPI_2INT",MPI_2INT},
    {ISC_SHORT_INT,"MPI_SHORT_INT",MPI_SHORT_INT},
    {ISC_LONG_DOUBLE_INT,"MPI_LONG_DOUBLE_INT",MPI_LONG_DOUBLE_INT},
    {ISC_2REAL,"MPI_2REAL",MPI_2REAL},
    {ISC_2DOUBLE_PRECISION,"MPI_2DOUBLE_PRECISION",MPI_2DOUBLE_PRECISION},
    {ISC_2INTEGER,"MPI_2INTEGER",MPI_2INTEGER},
    {ISC_COMPLEX8,"MPI_COMPLEX8",MPI_COMPLEX8},
    {ISC_COMPLEX16,"MPI_COMPLEX16",MPI_COMPLEX16},
    {ISC_COMPLEX32,"MPI_COMPLEX32",MPI_COMPLEX32},
    {ISC_COUNT,"MPI_COUNT",MPI_COUNT},
    {ISC_WCHAR,"MPI_WCHAR",MPI_WCHAR},
    {ISC_C_BOOL,"MPI_C_BOOL", MPI_C_BOOL},
    {ISC_C_FLOAT_COMPLEX, "MPI_C_FLOAT_COMPLEX", MPI_C_FLOAT_COMPLEX},
    {ISC_C_DOUBLE_COMPLEX,"MPI_C_DOUBLE_COMPLEX",MPI_C_DOUBLE_COMPLEX},
    {ISC_C_LONG_DOUBLE_COMPLEX,"MPI_C_LONG_DOUBLE_COMPLEX", MPI_C_LONG_DOUBLE_COMPLEX}
};


isc_const isc_builtin_dtypes = { 1, /* Use pointers */
			predefined_datatype_count,
			predefined_datatype_count,
			predefined_datatype_count,
			dtype_builtins,
			NULL
};

/*
 +++++++++++++++++
 * ERROR HANDLERS
 +++++++++++++++++
 */
api_use_ptrs errhandler_builtins[] = {
    {ISC_ERRHANDLER_NULL,"MPI_ERRHANDLER_NULL", MPI_ERRHANDLER_NULL},
    {ISC_ERRORS_ARE_FATAL,"MPI_ERRORS_ARE_FATAL",MPI_ERRORS_ARE_FATAL},
    {ISC_ERRORS_RETURN,"MPI_ERRORS_RETURN",MPI_ERRORS_RETURN}
};

isc_const isc_builtin_errhandler = { 1, /* Use pointers */
			predefined_errhandler_count,
			predefined_errhandler_count,
			predefined_errhandler_count,
			errhandler_builtins,
			NULL
};

/*
 +++++++++++++++++
 * INFO objects
 +++++++++++++++++
 */
api_use_ptrs info_builtins[] = {
    {ISC_INFO_NULL,"MPI_INFO_NULL", MPI_INFO_NULL}
};

isc_const isc_builtin_info = { 1, /* Use pointers */
			predefined_info_count,
			predefined_info_count,
			predefined_info_count,
		        info_builtins,
			NULL
};

/*
 +++++++++++++++++
 * WIN objects
 +++++++++++++++++
 */
api_use_ptrs win_builtins[] = {
    {ISC_WIN_NULL,"MPI_WIN_NULL", MPI_WIN_NULL}
};

isc_const isc_builtin_win = { 1, /* Use pointers */
			predefined_win_count,
			predefined_win_count,
			predefined_win_count,
			win_builtins, 
			NULL
};

/*
 +++++++++++++++++
 * Message objects
 +++++++++++++++++
 */
api_use_ptrs msg_builtins[] = {
  {ISC_MESSAGE_NULL_,"MPI_MESSAGE_NULL", MPI_MESSAGE_NULL},
  {ISC_MESSAGE_NO_PROC_, "MPI_MESSAGE_NO_PROC", MPI_MESSAGE_NO_PROC}
};

isc_const isc_builtin_msgs = {1, /* Use pointers */
			predefined_msg_count,
			predefined_msg_count,
			predefined_msg_count,
       	                msg_builtins,
                        NULL
};

#ifndef INTEGER_FILE_TYPE	
/* The default is to use pointers */
/*
 +++++++++++++++++
 * FILE objects
 +++++++++++++++++
 */
api_use_ptrs file_builtins[] = {
    {ISC_FILE_NULL,"MPI_FILE_NULL", MPI_FILE_NULL}
};

isc_const isc_builtin_file = { 1, /* Use pointers */
			predefined_file_count,
			predefined_file_count,
			predefined_file_count,
			file_builtins,
			NULL
};
#else
/* User overode the default by defining -DINTEGER_FILE_TYPE
 * VERY WEIRD!!! (but we need to cover the possibility) */
/*
 -----------------
 * FILE objects
 -----------------
 */
api_use_ints file_builtins[] = {
    {ISC_FILE_NULL,"MPI_FILE_NULL", MPI_FILE_NULL}
};

isc_const isc_builtin_file = { 0, /* Use integers */
			predefined_file_count,
			predefined_file_count,
			predefined_file_count,
			file_builtins,
			NULL
};

#endif

/* Gives a view of the API type for communicators */
int api_native_comms_are_integers() { return 0; }
/* ------------------------------------------------------------
 *  Declarations below the #else
 *  use integers to describe the MPI base object
 *-------------------------------------------------------------
 */
#else  /* !API_USES_POINTERS */

/* Gives a view of the API type for communicators */
int api_native_comms_are_integers() { return 1; }

/*
 -----------------
 * COMMUNICATORS
 -----------------
 */
api_use_ints comm_builtins[] = {
    {ISC_COMM_NULL,"MPI_COMM_NULL", MPI_COMM_NULL},
    {ISC_COMM_WORLD,"MPI_COMM_WORLD",MPI_COMM_WORLD},
    {ISC_COMM_SELF,"MPI_COMM_SELF",MPI_COMM_SELF}
};

isc_const isc_builtin_comms = { 0, 	/* use_integers */
			predefined_comm_count,
			predefined_comm_count,
			predefined_comm_count,
			comm_builtins,
			NULL
};

/*
 -----------------
 * GROUPS
 -----------------
 */
api_use_ints group_builtins[] = {
    {ISC_GROUP_NULL,"MPI_GROUP_NULL", MPI_GROUP_NULL},
    {ISC_GROUP_EMPTY,"MPI_GROUP_EMPTY",MPI_GROUP_EMPTY}
};

isc_const isc_builtin_groups = { 0, /* Use integers */
			predefined_group_count,
			predefined_group_count,
			predefined_group_count,
			group_builtins, 
			NULL
};

/*
 -----------------
 * REQUESTS
 -----------------
 */
api_use_ints request_builtins[] = {
  {ISC_REQUEST_NULL,"MPI_REQUEST_NULL", MPI_REQUEST_NULL}
};

isc_const isc_builtin_requests = { 0, /* Use integers */
			predefined_request_count,
			predefined_request_count,
			predefined_request_count,
			request_builtins,
			NULL
};

/*
 -----------------
 * OPS
 -----------------
 */
api_use_ints op_builtins[] = {
    {ISC_OP_NULL,"MPI_OP_NULL",MPI_OP_NULL},
    {ISC_MAX,"MPI_MAX",MPI_MAX},
    {ISC_MIN,"MPI_MIN",MPI_MIN},
    {ISC_SUM,"MPI_SUM",MPI_SUM},
    {ISC_PROD,"MPI_PROD",MPI_PROD},
    {ISC_LAND,"MPI_LAND",MPI_LAND},
    {ISC_BAND,"MPI_BAND",MPI_BAND},
    {ISC_LOR,"MPI_LOR",MPI_LOR},
    {ISC_BOR,"MPI_BOR",MPI_BOR},
    {ISC_LXOR,"MPI_LXOR",MPI_LXOR},
    {ISC_BXOR,"MPI_BXOR",MPI_BXOR},
    {ISC_MAXLOC,"MPI_MAXLOC",MPI_MAXLOC},
    {ISC_MINLOC,"MPI_MINLOC",MPI_MINLOC},
    {ISC_REPLACE,"MPI_REPLACE",MPI_REPLACE}
};

isc_const isc_builtin_ops = { 0, /* Use integers */
			predefined_op_count,
			predefined_op_count,
			predefined_op_count,
			op_builtins,
			NULL
};

/*
 -----------------
 * DATATYPES
 -----------------
 */

api_use_ints dtype_builtins[] = {
    {ISC_DATATYPE_NULL,"MPI_DATATYPE_NULL", MPI_DATATYPE_NULL},
    {ISC_CHAR,"MPI_CHAR",MPI_CHAR},
    {ISC_SHORT,"MPI_SHORT",MPI_SHORT},
    {ISC_INT,"MPI_INT",MPI_INT},
    {ISC_LONG,"MPI_LONG",MPI_LONG},
    {ISC_SIGNED_CHAR, "MPI_SIGNED_CHAR" , MPI_SIGNED_CHAR},
    {ISC_UNSIGNED_CHAR,"MPI_UNSIGNED_CHAR",MPI_UNSIGNED_CHAR},
    {ISC_UNSIGNED_SHORT,"MPI_UNSIGNED_SHORT",MPI_UNSIGNED_SHORT},
    {ISC_UNSIGNED,"MPI_UNSIGNED",MPI_UNSIGNED},
    {ISC_UNSIGNED_LONG,"MPI_UNSIGNED_LONG",MPI_UNSIGNED_LONG},
    {ISC_FLOAT,"MPI_FLOAT",MPI_FLOAT},
    {ISC_DOUBLE,"MPI_DOUBLE",MPI_DOUBLE},
    {ISC_LONG_DOUBLE,"MPI_LONG_DOUBLE",MPI_LONG_DOUBLE},
    {ISC_LONG_LONG,"MPI_LONG_LONG",MPI_LONG_LONG},
    {ISC_LONG_LONG_INT,"MPI_LONG_LONG_INT",MPI_LONG_LONG_INT},
    {ISC_UNSIGNED_LONG_LONG,"MPI_UNSIGNED_LONG_LONG",MPI_UNSIGNED_LONG_LONG},
    {ISC_INTEGER,"MPI_INTEGER",MPI_INTEGER},
    {ISC_REAL,"MPI_REAL",MPI_REAL},
    {ISC_DOUBLE_PRECISION,"MPI_DOUBLE_PRECISION",MPI_DOUBLE_PRECISION},
    {ISC_COMPLEX,"MPI_COMPLEX",MPI_COMPLEX},
    {ISC_DOUBLE_COMPLEX,"MPI_DOUBLE_COMPLEX",MPI_DOUBLE_COMPLEX},
    {ISC_LOGICAL,"MPI_LOGICAL",MPI_LOGICAL},
    {ISC_CHARACTER,"MPI_CHARACTER",MPI_CHARACTER},
    {ISC_INTEGER1,"MPI_INTEGER1",MPI_INTEGER1},
    {ISC_INTEGER2,"MPI_INTEGER2",MPI_INTEGER2},
    {ISC_INTEGER4,"MPI_INTEGER4",MPI_INTEGER4},
    {ISC_INTEGER8,"MPI_INTEGER8",MPI_INTEGER8},
    {ISC_REAL4,"MPI_REAL4",MPI_REAL4},
    {ISC_REAL8,"MPI_REAL8",MPI_REAL8},
    {ISC_REAL16,"MPI_REAL16",MPI_REAL16},
    {ISC_BYTE,"MPI_BYTE",MPI_BYTE},
    {ISC_PACKED,"MPI_PACKED",MPI_PACKED},
    {ISC_UB,"MPI_UB",MPI_UB},
    {ISC_LB,"MPI_LB",MPI_LB},
    {ISC_FLOAT_INT,"MPI_FLOAT_INT",MPI_FLOAT_INT},
    {ISC_DOUBLE_INT,"MPI_DOUBLE_INT",MPI_DOUBLE_INT},
    {ISC_LONG_INT,"MPI_LONG_INT",MPI_LONG_INT},
    {ISC_2INT,"MPI_2INT",MPI_2INT},
    {ISC_SHORT_INT,"MPI_SHORT_INT",MPI_SHORT_INT},
    {ISC_LONG_DOUBLE_INT,"MPI_LONG_DOUBLE_INT",MPI_LONG_DOUBLE_INT},
    {ISC_2REAL,"MPI_2REAL",MPI_2REAL},
    {ISC_2DOUBLE_PRECISION,"MPI_2DOUBLE_PRECISION",MPI_2DOUBLE_PRECISION},
    {ISC_2INTEGER,"MPI_2INTEGER",MPI_2INTEGER},
    {ISC_COMPLEX8,"MPI_COMPLEX8",MPI_COMPLEX8},
    {ISC_COMPLEX16,"MPI_COMPLEX16",MPI_COMPLEX16},
    {ISC_COMPLEX32,"MPI_COMPLEX32",MPI_COMPLEX32},
    {ISC_COUNT,"MPI_COUNT",MPI_COUNT},
    {ISC_WCHAR,"MPI_WCHAR",MPI_WCHAR},
    {ISC_C_BOOL,"MPI_C_BOOL", MPI_C_BOOL},
    {ISC_C_FLOAT_COMPLEX, "MPI_C_FLOAT_COMPLEX", MPI_C_FLOAT_COMPLEX},
    {ISC_C_DOUBLE_COMPLEX,"MPI_C_DOUBLE_COMPLEX",MPI_C_DOUBLE_COMPLEX},
    {ISC_C_LONG_DOUBLE_COMPLEX,"MPI_C_LONG_DOUBLE_COMPLEX", MPI_C_LONG_DOUBLE_COMPLEX}
};

isc_const isc_builtin_dtypes = { 0, /* Use integers */
			predefined_datatype_count,
			predefined_datatype_count,
			predefined_datatype_count,
			dtype_builtins,
			NULL
};

/*
 -----------------
 * ERROR HANDLERS
 -----------------
 */
api_use_ints errhandler_builtins[] = {
    {ISC_ERRHANDLER_NULL,"MPI_ERRHANDLER_NULL", MPI_ERRHANDLER_NULL},
    {ISC_ERRORS_ARE_FATAL,"MPI_ERRORS_ARE_FATAL",MPI_ERRORS_ARE_FATAL},
    {ISC_ERRORS_RETURN,"MPI_ERRORS_RETURN",MPI_ERRORS_RETURN}
};

isc_const isc_builtin_errhandler = { 0, /* Use integers */
			predefined_errhandler_count,
			predefined_errhandler_count,
			predefined_errhandler_count,
			errhandler_builtins, 
			NULL
};

/*
 -----------------
 * INFO objects
 -----------------
 */
api_use_ints info_builtins[] = {
    {ISC_INFO_NULL,"MPI_INFO_NULL", MPI_INFO_NULL}
};

isc_const isc_builtin_info = { 0, /* Use integers */
			predefined_info_count,
			predefined_info_count,
			predefined_info_count,
			info_builtins,
			NULL
};

/*
 -----------------
 * WIN objects
 -----------------
 */
api_use_ints win_builtins[] = {
    {ISC_WIN_NULL,"MPI_WIN_NULL", MPI_WIN_NULL}
};

isc_const isc_builtin_win = { 0, /* Use integers */
			predefined_win_count,
			predefined_win_count,
			predefined_win_count,
			info_builtins,
			NULL
};

/*
 +++++++++++++++++
 * Message objects
 +++++++++++++++++
 */
api_use_ints msg_builtins[] = {
  {ISC_MESSAGE_NULL_,"MPI_MESSAGE_NULL", MPI_MESSAGE_NULL},
  {ISC_MESSAGE_NO_PROC_, "MPI_MESSAGE_NO_PROC", MPI_MESSAGE_NO_PROC}
};

isc_const isc_builtin_msgs = {0, /* Use integers */
			predefined_msg_count,
			predefined_msg_count,
			predefined_msg_count,
       	                msg_builtins,
                        NULL
};

#ifndef INTEGER_FILE_TYPE	
/* The default is to use pointers */
/*
 +++++++++++++++++
 * FILE objects
 +++++++++++++++++
 */
api_use_ptrs file_builtins[] = {
    {ISC_FILE_NULL,"MPI_FILE_NULL", MPI_FILE_NULL}
};

isc_const isc_builtin_file = { 1, /* Use pointers */
			predefined_file_count,
			predefined_file_count,
			predefined_file_count,
			file_builtins,
			NULL
};
#else
/* User overode the default by defining -DINTEGER_FILE_TYPE */
/*
 -----------------
 * FILE objects
 -----------------
 */
api_use_ints file_builtins[] = {
    {ISC_FILE_NULL,"MPI_FILE_NULL", MPI_FILE_NULL}
};

isc_const isc_builtin_file = { 0, /* Use integers */
			predefined_file_count,
			predefined_file_count,
			predefined_file_count,
			file_builtins,
			NULL
};

#endif

#endif

/* ------------------------------------------------------------
 *  Declarations below this point are common to both API styles,
 *  e.g. error codes are always integer values!
 *-------------------------------------------------------------
 */

/*
 ******************
 * ERROR_CODES
 ******************
 */
api_use_ints errcode_builtins[] = {
    {ISC_SUCCESS,"MPI_SUCCESS",MPI_SUCCESS},         
    {ISC_ERR_BUFFER,"MPI_ERR_BUFFER",MPI_ERR_BUFFER},      
    {ISC_ERR_COUNT,"MPI_ERR_COUNT",MPI_ERR_COUNT},       
    {ISC_ERR_TYPE,"MPI_ERR_TYPE",MPI_ERR_TYPE},        
    {ISC_ERR_TAG,"MPI_ERR_TAG",MPI_ERR_TAG},         
    {ISC_ERR_COMM,"MPI_ERR_COMM",MPI_ERR_COMM},        
    {ISC_ERR_RANK,"MPI_ERR_RANK",MPI_ERR_RANK},        
    {ISC_ERR_ROOT,"MPI_ERR_ROOT",MPI_ERR_ROOT},        
    {ISC_ERR_GROUP,"MPI_ERR_GROUP",MPI_ERR_GROUP},       
    {ISC_ERR_OP,"MPI_ERR_OP",MPI_ERR_OP},          
    {ISC_ERR_TOPOLOGY,"MPI_ERR_TOPOLOGY",MPI_ERR_TOPOLOGY},    
    {ISC_ERR_DIMS,"MPI_ERR_DIMS",MPI_ERR_DIMS},        
    {ISC_ERR_ARG,"MPI_ERR_ARG",MPI_ERR_ARG},         
    {ISC_ERR_UNKNOWN,"MPI_ERR_UNKNOWN",MPI_ERR_UNKNOWN},     
    {ISC_ERR_TRUNCATE,"MPI_ERR_TRUNCATE",MPI_ERR_TRUNCATE},    
    {ISC_ERR_OTHER,"MPI_ERR_OTHER",MPI_ERR_OTHER},       
    {ISC_ERR_INTERN,"MPI_ERR_INTERN",MPI_ERR_INTERN},      
    {ISC_ERR_IN_STATUS,"MPI_ERR_IN_STATUS",MPI_ERR_IN_STATUS},   
    {ISC_ERR_PENDING,"MPI_ERR_PENDING",MPI_ERR_PENDING},     
    {ISC_ERR_REQUEST,"MPI_ERR_REQUEST",MPI_ERR_REQUEST},     
    {ISC_ERR_ACCESS,"MPI_ERR_ACCESS",MPI_ERR_ACCESS},      
    {ISC_ERR_AMODE,"MPI_ERR_AMODE",MPI_ERR_AMODE},       
    {ISC_ERR_BAD_FILE,"MPI_ERR_BAD_FILE",MPI_ERR_BAD_FILE},    
    {ISC_ERR_CONVERSION,"MPI_ERR_CONVERSION",MPI_ERR_CONVERSION},  
    {ISC_ERR_DUP_DATAREP,"MPI_ERR_DUP_DATAREP",MPI_ERR_DUP_DATAREP}, 
    {ISC_ERR_FILE_EXISTS,"MPI_ERR_FILE_EXISTS",MPI_ERR_FILE_EXISTS}, 
    {ISC_ERR_FILE_IN_USE,"MPI_ERR_FILE_IN_USE",MPI_ERR_FILE_IN_USE}, 
    {ISC_ERR_FILE,"MPI_ERR_FILE",MPI_ERR_FILE},        
    {ISC_ERR_INFO,"MPI_ERR_INFO",MPI_ERR_INFO},        
    {ISC_ERR_INFO_KEY,"MPI_ERR_INFO_KEY",MPI_ERR_INFO_KEY},    
    {ISC_ERR_INFO_VALUE,"MPI_ERR_INFO_VALUE",MPI_ERR_INFO_VALUE},  
    {ISC_ERR_INFO_NOKEY,"MPI_ERR_INFO_NOKEY",MPI_ERR_INFO_NOKEY},  
    {ISC_ERR_IO,"MPI_ERR_IO",MPI_ERR_IO},          
    {ISC_ERR_NAME,"MPI_ERR_NAME",MPI_ERR_NAME},        
    {ISC_ERR_NO_MEM,"MPI_ERR_NO_MEM",MPI_ERR_NO_MEM},      
    {ISC_ERR_NOT_SAME,"MPI_ERR_NOT_SAME",MPI_ERR_NOT_SAME},    
    {ISC_ERR_NO_SPACE,"MPI_ERR_NO_SPACE",MPI_ERR_NO_SPACE},    
    {ISC_ERR_NO_SUCH_FILE,"MPI_ERR_NO_SUCH_FILE",MPI_ERR_NO_SUCH_FILE},
    {ISC_ERR_PORT,"MPI_ERR_PORT",MPI_ERR_PORT},        
    {ISC_ERR_QUOTA,"MPI_ERR_QUOTA",MPI_ERR_QUOTA},       
    {ISC_ERR_READ_ONLY,"MPI_ERR_READ_ONLY",MPI_ERR_READ_ONLY},   
    {ISC_ERR_SERVICE,"MPI_ERR_SERVICE",MPI_ERR_SERVICE},     
    {ISC_ERR_SPAWN,"MPI_ERR_SPAWN",MPI_ERR_SPAWN},       
    {ISC_ERR_UNSUPPORTED_DATAREP,"MPI_ERR_UNSUPPORTED_DATAREP",MPI_ERR_UNSUPPORTED_DATAREP},
    {ISC_ERR_UNSUPPORTED_OPERATION,"MPI_ERR_UNSUPPORTED_OPERATION",MPI_ERR_UNSUPPORTED_OPERATION},
    {ISC_ERR_WIN,"MPI_ERR_WIN",MPI_ERR_WIN},         
    {ISC_ERR_BASE,"MPI_ERR_BASE",MPI_ERR_BASE},        
    {ISC_ERR_LOCKTYPE,"MPI_ERR_LOCKTYPE",MPI_ERR_LOCKTYPE},    
    {ISC_ERR_KEYVAL,"MPI_ERR_KEYVAL",MPI_ERR_KEYVAL},      
    {ISC_ERR_RMA_CONFLICT,"MPI_ERR_RMA_CONFLICT",MPI_ERR_RMA_CONFLICT},
    {ISC_ERR_RMA_SYNC,"MPI_ERR_RMA_SYNC",MPI_ERR_RMA_SYNC},    
    {ISC_ERR_SIZE,"MPI_ERR_SIZE",MPI_ERR_SIZE},        
    {ISC_ERR_DISP,"MPI_ERR_DISP",MPI_ERR_DISP},        
    {ISC_ERR_ASSERT,"MPI_ERR_ASSERT",MPI_ERR_ASSERT},      
    {ISC_ERR_LASTCODE,"MPI_ERR_LASTCODE",MPI_ERR_LASTCODE},
};

isc_const isc_builtin_errcodes = { 0, /* Use integers */
			predefined_error_count,
			predefined_error_count,
			predefined_error_count,
			errcode_builtins,
			NULL
};

api_use_ints amodebitfield_builtins[] = {
    {0, NULL, 0},
    {ISC_MODE_CREATE,"MPI_MODE_CREATE",MPI_MODE_CREATE},
    {ISC_MODE_RDONLY,"MPI_MODE_RDONLY",MPI_MODE_RDONLY},
    {ISC_MODE_WRONLY,"MPI_MODE_WRONLY",MPI_MODE_WRONLY},
    {ISC_MODE_RDWR,"MPI_MODE_RDWR",MPI_MODE_RDWR},
    {ISC_MODE_DELETE_ON_CLOSE,"MPI_MODE_DELETE_ON_CLOSE",MPI_MODE_DELETE_ON_CLOSE},
    {ISC_MODE_UNIQUE_OPEN,"MPI_MODE_UNIQUE_OPEN",MPI_MODE_UNIQUE_OPEN},
    {ISC_MODE_EXCL,"MPI_MODE_EXCL",MPI_MODE_EXCL},
    {ISC_MODE_APPEND,"MPI_MODE_APPEND",MPI_MODE_APPEND},
    {ISC_MODE_SEQUENTIAL,"MPI_MODE_SEQUENTIAL",MPI_MODE_SEQUENTIAL},
};

isc_const isc_builtin_amodebitfield = { 0, /* Use integers */
			prefined_amodebitfield_count,
			prefined_amodebitfield_count,
			prefined_amodebitfield_count,
			amodebitfield_builtins,
			NULL
};

api_use_ints winassertbitfield_builtins[] = {
    {0, NULL, 0},
    {ISC_MODE_NOCHECK,"MPI_MODE_NOCHECK",MPI_MODE_NOCHECK},
    {ISC_MODE_NOPRECEDE,"MPI_MODE_NOPRECEDE",MPI_MODE_NOPRECEDE},
    {ISC_MODE_NOPUT,"MPI_MODE_NOPUT",MPI_MODE_NOPUT},
    {ISC_MODE_NOSTORE,"MPI_MODE_NOSTORE",MPI_MODE_NOSTORE},
    {ISC_MODE_NOSUCCEED,"MPI_MODE_NOSUCCEED",MPI_MODE_NOSUCCEED},
};

isc_const isc_builtin_winassertbitfield = { 0, /* Use integers */
			predefined_winassertbitfield_count,
			predefined_winassertbitfield_count,
			predefined_winassertbitfield_count,
			winassertbitfield_builtins,
			NULL
};

/*
 ******************
 * MISC
 ******************
 */
api_use_ints misc_builtins[] = {
    {ISC_PROC_NULL,"MPI_PROC_NULL",MPI_PROC_NULL},
    {ISC_ANY_SOURCE,"MPI_ANY_SOURCE", MPI_ANY_SOURCE},
    {ISC_ANY_TAG,"MPI_ANY_TAG",MPI_ANY_TAG},
    {ISC_ROOT,"MPI_ROOT",MPI_ROOT},
    {ISC_UNDEFINED,"MPI_UNDEFINED",MPI_UNDEFINED},
    {ISC_KEYVAL_INVALID,"MPI_KEYVAL_INVALID",MPI_KEYVAL_INVALID},
    {ISC_TAG_UB,"MPI_TAG_UB",MPI_TAG_UB},
    {ISC_HOST,"MPI_HOST",MPI_HOST},
    {ISC_IO,"MPI_IO",MPI_IO},
    {ISC_WTIME_IS_GLOBAL,"MPI_WTIME_IS_GLOBAL",MPI_WTIME_IS_GLOBAL},
    {ISC_ORDER_C,"MPI_ORDER_C",MPI_ORDER_C},
    {ISC_ORDER_FORTRAN,"MPI_ORDER_FORTRAN",MPI_ORDER_FORTRAN},
    {ISC_DISTRIBUTE_BLOCK,"MPI_DISTRIBUTE_BLOCK",MPI_DISTRIBUTE_BLOCK},
    {ISC_DISTRIBUTE_CYCLIC,"MPI_DISTRIBUTE_CYCLIC",MPI_DISTRIBUTE_CYCLIC},
    {ISC_DISTRIBUTE_NONE,"MPI_DISTRIBUTE_NONE",MPI_DISTRIBUTE_NONE},
    {ISC_DISTRIBUTE_DFLT_DARG,"MPI_DISTRIBUTE_DFLT_DARG",MPI_DISTRIBUTE_DFLT_DARG},
    {ISC_CART,"MPI_CART",MPI_CART},
    {ISC_GRAPH,"MPI_GRAPH",MPI_GRAPH},
    {ISC_COMBINER_NAMED,"MPI_COMBINER_NAMED",MPI_COMBINER_NAMED},
    {ISC_COMBINER_DUP,"MPI_COMBINER_DUP",MPI_COMBINER_DUP},
    {ISC_COMBINER_CONTIGUOUS,"MPI_COMBINER_CONTIGUOUS",MPI_COMBINER_CONTIGUOUS},
    {ISC_COMBINER_VECTOR,"MPI_COMBINER_VECTOR",MPI_COMBINER_VECTOR},
    {ISC_COMBINER_HVECTOR_INTEGER,"MPI_COMBINER_HVECTOR_INTEGER",MPI_COMBINER_HVECTOR_INTEGER},
    {ISC_COMBINER_HVECTOR,"MPI_COMBINER_HVECTOR",MPI_COMBINER_HVECTOR},
    {ISC_COMBINER_INDEXED,"MPI_COMBINER_INDEXED",MPI_COMBINER_INDEXED},
    {ISC_COMBINER_HINDEXED_INTEGER,"MPI_COMBINER_HINDEXED_INTEGER",MPI_COMBINER_HINDEXED_INTEGER},
    {ISC_COMBINER_HINDEXED,"MPI_COMBINER_HINDEXED",MPI_COMBINER_HINDEXED},
    {ISC_COMBINER_INDEXED_BLOCK,"MPI_COMBINER_INDEXED_BLOCK",MPI_COMBINER_INDEXED_BLOCK},
    {ISC_COMBINER_STRUCT_INTEGER,"MPI_COMBINER_STRUCT_INTEGER",MPI_COMBINER_STRUCT_INTEGER},
    {ISC_COMBINER_STRUCT,"MPI_COMBINER_STRUCT",MPI_COMBINER_STRUCT},
    {ISC_COMBINER_SUBARRAY,"MPI_COMBINER_SUBARRAY",MPI_COMBINER_SUBARRAY},
    {ISC_COMBINER_DARRAY,"MPI_COMBINER_DARRAY",MPI_COMBINER_DARRAY},
    {ISC_COMBINER_F90_REAL,"MPI_COMBINER_F90_REAL",MPI_COMBINER_F90_REAL},
    {ISC_COMBINER_F90_COMPLEX,"MPI_COMBINER_F90_COMPLEX",MPI_COMBINER_F90_COMPLEX},
    {ISC_COMBINER_F90_INTEGER,"MPI_COMBINER_F90_INTEGER",MPI_COMBINER_F90_INTEGER},
    {ISC_COMBINER_RESIZED,"MPI_COMBINER_RESIZED",MPI_COMBINER_RESIZED},
    {ISC_APPNUM,"MPI_APPNUM",MPI_APPNUM},
    {ISC_LASTUSEDCODE,"MPI_LASTUSEDCODE",MPI_LASTUSEDCODE},
    {ISC_UNIVERSE_SIZE,"MPI_UNIVERSE_SIZE",MPI_UNIVERSE_SIZE},
    {ISC_WIN_BASE,"MPI_WIN_BASE",MPI_WIN_BASE},
    {ISC_WIN_SIZE,"MPI_WIN_SIZE",MPI_WIN_SIZE},
    {ISC_WIN_DISP_UNIT,"MPI_WIN_DISP_UNIT",MPI_WIN_DISP_UNIT},
    {ISC_DISPLACEMENT_CURRENT,"MPI_DISPLACEMENT_CURRENT",MPI_DISPLACEMENT_CURRENT},
    {ISC_LOCK_EXCLUSIVE,"MPI_LOCK_EXCLUSIVE",MPI_LOCK_EXCLUSIVE},
    {ISC_LOCK_SHARED,"MPI_LOCK_SHARED",MPI_LOCK_SHARED},
    {ISC_SEEK_SET,"MPI_SEEK_SET",MPI_SEEK_SET},
    {ISC_SEEK_CUR,"MPI_SEEK_CUR",MPI_SEEK_CUR},
    {ISC_SEEK_END,"MPI_SEEK_END",MPI_SEEK_END}
};

isc_const isc_builtin_miscs = { 0, /* Use integers */
			predefined_misc_count,
			predefined_misc_count,
			predefined_misc_count,
			misc_builtins,
			NULL
};

/*
 +++++++++++++++++
 * MISC_POINTERS
 +++++++++++++++++
 */
api_use_ptrs ptr_builtins[] = {
    {null_addr,"NULL_ADDR",0},	/* unused */
    {ISC_BOTTOM,"MPI_BOTTOM",MPI_BOTTOM},
    {ISC_IN_PLACE,"MPI_IN_PLACE",MPI_IN_PLACE},
    {ISC_ARGV_NULL,"MPI_ARGV_NULL",MPI_ARGV_NULL},
    {ISC_ARGVS_NULL,"MPI_ARGVS_NULL",MPI_ARGVS_NULL},
    {ISC_ERRCODES_IGNORE,"MPI_ERRCODES_IGNORE",MPI_ERRCODES_IGNORE},
    {ISC_STATUS_IGNORE,"MPI_STATUS_IGNORE",MPI_STATUS_IGNORE},
    {ISC_NULL_COPY_FN,"MPI_NULL_COPY_FN",MPI_COMM_NULL_COPY_FN},
    {ISC_NULL_DELETE_FN,"MPI_NULL_DELETE_FN",MPI_COMM_NULL_DELETE_FN}
};

isc_const isc_builtin_addr = { 1, /* Use pointers */
			predefined_ptr_count,
			predefined_ptr_count,
			predefined_ptr_count,
			ptr_builtins,
			NULL
};

/* Handling of the MPI_Status object
 * We shouldn't care about the contents or structure of
 * the native object, but the size is important since we
 * need to copy the contents when we're dealing with arrays
 * of status objects.
 *
 * Our definition of ISC_Status is defined to be as large
 * as the largest MPI that we currently support (8 integers)
 * or 32 bytes in length.
 *
 * Here are the known sizes:
 *    HPMPI = 32 bytes
 *    MPICH1.2 = 16 bytes
 *    MPICH2.0 = 20 bytes
 *    OMPI = 20 bytes
 *    SGI = 24 bytes
 *
 * By making our version of an MPI_Status object
 * as large (or larger) than the native implementation,
 * we can avoid copying the contents until we're actually
 * dealing with an array of status objects.
 * At that point we need the underlying size so that we
 * can pack and unpack the real data.
 *
 * We provide callback routines to copy from the native
 * MPI_Status object into the ISC version which has the
 * following typedef: (note that this should be identical
 * to the version supplied in mpi2isc.h)
 */
#include <string.h>

typedef struct { 
	int MPI_SOURCE;
	int MPI_TAG;
	int MPI_ERROR;
        int reserved[8];
} ISC_Status;


char *
get_vendor_mpilib(void)
{
  static char *vendor_library = VENDOR_MPI_SO;
  return vendor_library;
}

extern int ISC_Error_class(int, int *);
extern int ISC_Error_string(int, char *, int *);

int map_errcode_to_isc(int native_err)
{
  switch(native_err)
    {
    case MPI_ERR_BUFFER      : return ISC_ERR_BUFFER;
      break;
    case MPI_ERR_COUNT       : return ISC_ERR_COUNT;
      break;
    case MPI_ERR_TYPE        : return ISC_ERR_TYPE;
      break;
    case MPI_ERR_TAG         : return ISC_ERR_TAG;
      break;
    case MPI_ERR_COMM        : return ISC_ERR_COMM;
      break;
    case MPI_ERR_RANK        : return ISC_ERR_RANK;
      break;
    case MPI_ERR_ROOT        : return ISC_ERR_ROOT;
      break;
    case MPI_ERR_GROUP       : return ISC_ERR_GROUP;
      break;
    case MPI_ERR_OP          : return ISC_ERR_OP;
      break;
    case MPI_ERR_TOPOLOGY   : return ISC_ERR_TOPOLOGY;
      break;
    case MPI_ERR_DIMS       : return ISC_ERR_DIMS;
      break;
    case MPI_ERR_ARG        : return ISC_ERR_ARG;
      break;
    case MPI_ERR_UNKNOWN    : return ISC_ERR_UNKNOWN;
      break;
    case MPI_ERR_TRUNCATE   : return ISC_ERR_TRUNCATE;
      break;
    case MPI_ERR_OTHER      : return ISC_ERR_OTHER;
      break;
    case MPI_ERR_INTERN     : return ISC_ERR_INTERN;
      break;
    case MPI_ERR_IN_STATUS  : return ISC_ERR_IN_STATUS;
      break;
    case MPI_ERR_PENDING    : return ISC_ERR_PENDING;
      break;
    case MPI_ERR_REQUEST    : return ISC_ERR_REQUEST;
      break;
    case MPI_ERR_ACCESS     : return ISC_ERR_ACCESS;
      break;
    case MPI_ERR_AMODE      : return ISC_ERR_AMODE;
      break;
    case MPI_ERR_BAD_FILE   : return ISC_ERR_BAD_FILE;
      break;
    case MPI_ERR_CONVERSION : return ISC_ERR_CONVERSION;
      break;
    case MPI_ERR_DUP_DATAREP: return ISC_ERR_DUP_DATAREP;
      break;
    case MPI_ERR_FILE_EXISTS: return ISC_ERR_FILE_EXISTS;
      break;
    case MPI_ERR_FILE_IN_USE: return ISC_ERR_FILE_IN_USE;
      break;
    case MPI_ERR_FILE       : return ISC_ERR_FILE;
      break;
    case MPI_ERR_INFO       : return ISC_ERR_INFO;
      break;
    case MPI_ERR_INFO_KEY   : return ISC_ERR_INFO_KEY;
      break;
    case MPI_ERR_INFO_VALUE : return ISC_ERR_INFO_VALUE;
      break;
    case MPI_ERR_INFO_NOKEY : return ISC_ERR_INFO_NOKEY;
      break;
    case MPI_ERR_IO         : return ISC_ERR_IO;
      break;
    case MPI_ERR_NAME       : return ISC_ERR_NAME;
      break;
    case MPI_ERR_NO_MEM     : return ISC_ERR_NO_MEM;
      break;
    case MPI_ERR_NOT_SAME   : return ISC_ERR_NOT_SAME;
      break;
    case MPI_ERR_NO_SPACE   : return ISC_ERR_NO_SPACE;
      break;
    case MPI_ERR_NO_SUCH_FILE: return ISC_ERR_NO_SUCH_FILE;
      break;
    case MPI_ERR_PORT       : return ISC_ERR_PORT;
      break;
    case MPI_ERR_QUOTA      : return ISC_ERR_QUOTA;
      break;
    case MPI_ERR_READ_ONLY  : return ISC_ERR_READ_ONLY;
      break;
    case MPI_ERR_SERVICE    : return ISC_ERR_SERVICE;
      break;
    case MPI_ERR_SPAWN      : return ISC_ERR_SPAWN;
      break;
    case MPI_ERR_UNSUPPORTED_DATAREP  : return ISC_ERR_UNSUPPORTED_DATAREP;
      break;
    case MPI_ERR_UNSUPPORTED_OPERATION: return ISC_ERR_UNSUPPORTED_OPERATION;
      break;
    case MPI_ERR_WIN        : return ISC_ERR_WIN;
      break;
    case MPI_ERR_BASE       : return ISC_ERR_BASE;
      break;
    case MPI_ERR_LOCKTYPE   : return ISC_ERR_LOCKTYPE;
      break;
    case MPI_ERR_KEYVAL     : return ISC_ERR_KEYVAL;
      break;
    case MPI_ERR_RMA_CONFLICT: return ISC_ERR_RMA_CONFLICT;
      break;
    case MPI_ERR_RMA_SYNC   : return ISC_ERR_RMA_SYNC;
      break;
    case MPI_ERR_SIZE       : return ISC_ERR_SIZE;
      break;
    case MPI_ERR_DISP       : return ISC_ERR_DISP;
      break;
    case MPI_ERR_ASSERT     : return ISC_ERR_ASSERT;
      break;
    case MPI_ERR_RMA_RANGE : return ISC_ERR_RMA_RANGE;
      break;
    case MPI_ERR_RMA_ATTACH: return ISC_ERR_RMA_ATTACH;
      break;
    case MPI_ERR_RMA_SHARED: return ISC_ERR_RMA_SHARED;
      break;
    case MPI_ERR_RMA_FLAVOR: return ISC_ERR_RMA_FLAVOR;
    default:
      break;
    }
    return ISC_ERR_INTERN;
}
      
int native_mpi_status_size = sizeof(MPI_Status);
int native_mpi_status_to_isc(int count, MPI_Status *nativeStat, ISC_Status *iscStat)
{
  int i,err_status;
  api_use_ints *local_defs = active_errcodes->api_declared;
  for(i=0; i<count; i++) {
    /* Set the ISC values so that user codes have access to valid information
     * We really only count on the fact that the following fields
     * MUST BE DEFINED: MPI_SOURCE, MPI_TAG, and MPI_ERROR.
     * Element count is something that ONLY the native 
     * library knows. 
     */
   
    if (nativeStat[i].MPI_SOURCE == MPI_PROC_NULL)
      iscStat[i].MPI_SOURCE = ISC_PROC_NULL;
    else 
      iscStat[i].MPI_SOURCE = nativeStat[i].MPI_SOURCE; 
    if (nativeStat[i].MPI_TAG == MPI_ANY_TAG)
      iscStat[i].MPI_TAG = ISC_ANY_TAG;
    else
      iscStat[i].MPI_TAG = nativeStat[i].MPI_TAG;

    err_status = nativeStat[i].MPI_ERROR;
    if (err_status > 0) {
      int errlen;
      char ErrorMsg[MPI_MAX_ERROR_STRING];
      int rc = ISC_Error_string(err_status, ErrorMsg, &errlen);
      printf("MPI error: %s\n", ErrorMsg);
      iscStat[i].MPI_ERROR = map_errcode_to_isc(err_status);
    } 
#if 0
    else {
      iscStat[i].MPI_ERROR = ISC_SUCCESS;
    }
#endif
    memcpy(iscStat[i].reserved,&nativeStat[i], sizeof(MPI_Status));
  }
  return count;
}

void (*get_fortran_dtype)(int isc_index, int ftnvalue);
void (*get_mpi_constant)(int isc_index, char *symbol);

void
register_callback_1(void *address)
{
  get_fortran_dtype = (void (*)(int, int))address;
}

void
register_callback_2(void *address)
{
  get_mpi_constant = (void (*)(int, char *))address;
}



#if defined(LAZY_RESOLVE_1)

void
maybe_do_lazy_evaluations()
{
  LAZY_RESOLVE_1;
#ifdef LAZY_RESOLVE_2
  LAZY_RESOLVE_2;
#endif
#ifdef LAZY_RESOLVE_3
  LAZY_RESOLVE_3;
#endif
#ifdef LAZY_RESOLVE_4
  LAZY_RESOLVE_4;
#endif
#ifdef LAZY_RESOLVE_5
  LAZY_RESOLVE_5;
#endif
#ifdef LAZY_RESOLVE_6
  LAZY_RESOLVE_6;
#endif
#ifdef LAZY_RESOLVE_7
  LAZY_RESOLVE_7;
#endif
#ifdef LAZY_RESOLVE_8
  LAZY_RESOLVE_8;
#endif
#ifdef LAZY_RESOLVE_9
  LAZY_RESOLVE_9;
#endif
#ifdef LAZY_RESOLVE_10
  LAZY_RESOLVE_10;
#endif
#ifdef LAZY_RESOLVE_11
  LAZY_RESOLVE_11;
#endif
#ifdef LAZY_RESOLVE_12
  LAZY_RESOLVE_12;
#endif
#ifdef LAZY_RESOLVE_13
  LAZY_RESOLVE_13;
#endif
#ifdef LAZY_RESOLVE_14
  LAZY_RESOLVE_14;
#endif
#ifdef LAZY_RESOLVE_15
  LAZY_RESOLVE_15;
#endif
#ifdef LAZY_RESOLVE_16
  LAZY_RESOLVE_16;
#endif
#ifdef LAZY_RESOLVE_17
  LAZY_RESOLVE_17;
#endif
#ifdef LAZY_RESOLVE_18
  LAZY_RESOLVE_18;
#endif
#ifdef LAZY_RESOLVE_19
  LAZY_RESOLVE_19;
#endif
#ifdef LAZY_RESOLVE_20
  LAZY_RESOLVE_20;
#endif

  return;
}
#endif

#endif


#ifdef RAWTESTING
#include <stdio.h>

int main(int argc, char **argv)
{

  int i;
  for(i=0; i<30; i++) {
    printf("%2d -> %2d,%s\n",i,dtype_builtins[i].self, dtype_builtins[i].MPI_name);
  }
  return 0;
}

#endif
