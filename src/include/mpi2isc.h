#ifndef MPI2ISC_H
#define MPI2ISC_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "iscmpi_constants.h"

extern void _record_ftn_entry(char *ftn);
extern int _next_history_index;
#define FTN_ENTER() _record_ftn_entry(__FUNCTION__)

/* Our own typedefs */
typedef long                 ISC_Aint;
typedef long long            ISC_Offset;
typedef unsigned long long   ISC_Count;
typedef unsigned int         ISC_Request;
typedef unsigned int         ISC_Group;
typedef unsigned int         ISC_Comm;
typedef unsigned int         ISC_Errhandler;
typedef unsigned int         ISC_Op;
typedef unsigned int         ISC_Datatype;
typedef unsigned int         ISC_Win;
typedef unsigned int         ISC_Message;
typedef unsigned int         ISC_File;
typedef unsigned int         ISC_Info;
typedef int                  ISC_Fint;

/* Borrowed From MPICH to deal with fortran character arrays/ strings */
#ifdef USE_FORT_STR_LEN_SIZET
#define FORT_SIZE_INT size_t
#else
#define FORT_SIZE_INT int
#endif

#ifdef USE_FORT_MIXED_STR_LEN
#define FORT_MIXED_LEN_DECL   , FORT_SIZE_INT
#define FORT_END_LEN_DECL
#define FORT_MIXED_LEN(a)     , FORT_SIZE_INT a
#define FORT_END_LEN(a)
#else
#define FORT_MIXED_LEN_DECL
#define FORT_END_LEN_DECL     , FORT_SIZE_INT
#define FORT_MIXED_LEN(a)
#define FORT_END_LEN(a)       , FORT_SIZE_INT a
#endif


/* Hopefully this is large enough. See notes in iscmpi_mapping.c */
#define MAX_MPI_STATUS_SIZE 8
typedef struct { 
    int MPI_SOURCE;
    int MPI_TAG;
    int MPI_ERROR;
    int reserved[MAX_MPI_STATUS_SIZE];
} ISC_Status;

typedef int ISC_Copy_function(ISC_Comm, int, void *, void *, void *, int *);
typedef int ISC_Delete_function(ISC_Comm, int, void *, void *);
typedef void ISC_Handler_function(ISC_Comm *, int *, ...);
typedef void ISC_User_function(void *, void *, int *, ISC_Datatype *); 

typedef void (ISC_Comm_errhandler_fn)(ISC_Comm *, int *, ...);
typedef void (ISC_File_errhandler_fn)(ISC_File *, int *, ...);
typedef void (ISC_Win_errhandler_fn)(ISC_Win *, int *, ...);

typedef int (ISC_Grequest_cancel_function)(void *, int); 
typedef int (ISC_Grequest_free_function)(void *); 
typedef int (ISC_Grequest_query_function)(void *, ISC_Status *); 
typedef int (ISC_Datarep_conversion_function)(void *, ISC_Datatype, int, void *, ISC_Offset, void *);
typedef int (ISC_Datarep_extent_function)(ISC_Datatype , ISC_Aint *, void *);

#define MPI_CONVERSION_FN_NULL ISC_CONVERSION_FN_NULL
#define ISC_CONVERSION_FN_NULL ((ISC_Datarep_conversion_function *)0)

typedef int (ISC_Comm_copy_attr_function)(ISC_Comm, int, void *, void *, void *, int *);
typedef int (ISC_Comm_delete_attr_function)(ISC_Comm, int, void *, void *);

typedef int (ISC_Type_copy_attr_function)(ISC_Datatype, int, void *, void *, void *, int *);
typedef int (ISC_Type_delete_attr_function)(ISC_Datatype, int, void *, void *);

typedef int (ISC_Win_copy_attr_function)(ISC_Win, int, void *, void *, void *, int *);
typedef int (ISC_Win_delete_attr_function)(ISC_Win, int, void *, void *);

typedef int (ISC_WIN_DUP_FN)(ISC_Win, int, void *, void *, void *, int *);

#define MPI_WIN_DUP_FN Isc_dup_function
// #define MPI_COMM_DUP_FN Isc_dup_function
// #define MPI_TYPE_DUP_FN Isc_dup_function


/* The order of this structure needs to match the list of variables
 * defined int the fortran common block /mpi_fortran_bottom/
 * see mpif-common.h
 */
typedef struct {
  int bottom;
  int in_place;
  int argv_null;
  int argvs_null;
  int errcodes_ignore;
  int status_ignore;
  int statuses_ignore;
} f_common_t;


#define MPI_F_STATUS_IGNORE  (int *)ISC_F_STATUS_IGNORE
#define MPI_F_STATUSES_IGNORE    (int *)ISC_F_STATUSES_IGNORE

/* These are always identical */
#define MPI_STATUS_IGNORE    (ISC_Status *)ISC_STATUS_IGNORE
#define MPI_STATUSES_IGNORE  (ISC_Status *)ISC_STATUS_IGNORE

#define MPI_Offset               ISC_Offset
#define MPI_Count                ISC_Count
#define MPI_Aint                 ISC_Aint
#define MPI_Request              ISC_Request
#define MPI_Group                ISC_Group
#define MPI_Comm                 ISC_Comm
#define MPI_Errhandler           ISC_Errhandler
#define MPI_Op                   ISC_Op
#define MPI_Datatype             ISC_Datatype
#define MPI_Win                  ISC_Win
#define MPI_Message              ISC_Message
#define MPI_File                 ISC_File
#define MPI_Info                 ISC_Info
#define MPI_Fint                 ISC_Fint
#define MPI_Status               ISC_Status
#define MPI_User_function        ISC_User_function
#define MPI_Copy_function        ISC_Copy_function
#define MPI_Delete_function      ISC_Delete_function
#define MPI_Handler_function     ISC_Handler_function

/* Communicators */
#define MPI_COMM_NULL            ISC_COMM_NULL
#define MPI_COMM_WORLD           ISC_COMM_WORLD
#define MPI_COMM_SELF            ISC_COMM_SELF

/* Groups */
#define MPI_GROUP_NULL           ISC_GROUP_NULL
#define MPI_GROUP_EMPTY          ISC_GROUP_EMPTY

/* Requests */
#define MPI_REQUEST_NULL         ISC_REQUEST_NULL

/* Messages */
#define MPI_MESSAGE_NULL         ISC_MESSAGE_NULL
#define MPI_MESSAGE_NO_PROC      ISC_MESSAGE_NO_PROC

/* OPs */
#define MPI_MAX                  ISC_MAX    
#define MPI_MIN                  ISC_MIN    
#define MPI_SUM                  ISC_SUM    
#define MPI_PROD                 ISC_PROD   
#define MPI_LAND                 ISC_LAND   
#define MPI_BAND                 ISC_BAND   
#define MPI_LOR                  ISC_LOR    
#define MPI_BOR                  ISC_BOR    
#define MPI_LXOR                 ISC_LXOR   
#define MPI_BXOR                 ISC_BXOR   
#define MPI_MINLOC               ISC_MINLOC 
#define MPI_MAXLOC               ISC_MAXLOC 
#define MPI_REPLACE              ISC_REPLACE
#define MPI_NO_OP                ISC_NO_OP
#define MPI_OP_NULL              ISC_OP_NULL              

/* Datatypes */
#define MPI_DATATYPE_NULL        ISC_DATATYPE_NULL
#define MPI_CHAR                 ISC_CHAR
#define MPI_SIGNED_CHAR          ISC_SIGNED_CHAR
#define MPI_UNSIGNED_CHAR        ISC_UNSIGNED_CHAR
#define MPI_BYTE                 ISC_BYTE
#define MPI_WCHAR                ISC_WCHAR
#define MPI_SHORT                ISC_SHORT
#define MPI_UNSIGNED_SHORT       ISC_UNSIGNED_SHORT
#define MPI_INT                  ISC_INT
#define MPI_UNSIGNED             ISC_UNSIGNED
#define MPI_LONG                 ISC_LONG
#define MPI_UNSIGNED_LONG        ISC_UNSIGNED_LONG
#define MPI_FLOAT                ISC_FLOAT
#define MPI_DOUBLE               ISC_DOUBLE
#define MPI_LONG_DOUBLE          ISC_LONG_DOUBLE
#define MPI_LONG_LONG_INT        ISC_LONG_LONG_INT
#define MPI_UNSIGNED_LONG_LONG   ISC_UNSIGNED_LONG_LONG
#define MPI_LONG_LONG            ISC_LONG_LONG
#define MPI_PACKED               ISC_PACKED
#define MPI_TYPE_LB              ISC_TYPE_LB
#define MPI_TYPE_UB              ISC_TYPE_UB
#define MPI_FLOAT_INT            ISC_FLOAT_INT
#define MPI_DOUBLE_INT           ISC_DOUBLE_INT
#define MPI_LONG_INT             ISC_LONG_INT
#define MPI_SHORT_INT            ISC_SHORT_INT
#define MPI_2INT                 ISC_2INT
#define MPI_LONG_DOUBLE_INT      ISC_LONG_DOUBLE_INT
#define MPI_COMPLEX              ISC_COMPLEX
#define MPI_DOUBLE_COMPLEX       ISC_DOUBLE_COMPLEX
#define MPI_LOGICAL              ISC_LOGICAL
#define MPI_REAL                 ISC_REAL
#define MPI_DOUBLE_PRECISION     ISC_DOUBLE_PRECISION
#define MPI_INTEGER              ISC_INTEGER
#define MPI_2INTEGER             ISC_2INTEGER
#define MPI_2COMPLEX             ISC_2COMPLEX
#define MPI_2DOUBLE_COMPLEX      ISC_2DOUBLE_COMPLEX
#define MPI_2REAL                ISC_2REAL
#define MPI_2DOUBLE_PRECISION    ISC_2DOUBLE_PRECISION
#define MPI_CHARACTER            ISC_CHARACTER
#define MPI_REAL4                ISC_REAL4
#define MPI_REAL8                ISC_REAL8
#define MPI_REAL16               ISC_REAL16
#define MPI_COMPLEX8             ISC_COMPLEX8
#define MPI_COMPLEX16            ISC_COMPLEX16
#define MPI_COMPLEX32            ISC_COMPLEX32
#define MPI_INTEGER1             ISC_INTEGER1
#define MPI_INTEGER2             ISC_INTEGER2
#define MPI_INTEGER4             ISC_INTEGER4
#define MPI_INTEGER8             ISC_INTEGER8
/* 
 * No support yet for 16 byte ints
#define MPI_INTEGER16            ISC_INTEGER16
 */
#define MPI_INTEGER16            ISC_DATATYPE_NULL
#define MPI_LOGICAL1             ISC_DATATYPE_NULL
#define MPI_LOGICAL2             ISC_DATATYPE_NULL
#define MPI_LOGICAL4             ISC_DATATYPE_NULL
#define MPI_LOGICAL8             ISC_DATATYPE_NULL
#define MPI_REAL2                ISC_DATATYPE_NULL
#define MPI_COMPLEX4             ISC_DATATYPE_NULL
/* No support yet for CXX types */
#define MPI_CXX_BOOL             ISC_DATATYPE_NULL
#define MPI_CXX_FLOAT_COMPLEX    ISC_DATATYPE_NULL
#define MPI_CXX_DOUBLE_COMPLEX   ISC_DATATYPE_NULL
#define MPI_CXX_LONG_DOUBLE_COMPLEX ISC_DATATYPE_NULL
/* C99 datatypes */
#define MPI_C_BOOL               ISC_C_BOOL  
#define MPI_C_FLOAT_COMPLEX      ISC_C_FLOAT_COMPLEX
#define MPI_C_COMPLEX            MPI_C_FLOAT_COMPLEX
#define MPI_C_DOUBLE_COMPLEX     ISC_C_DOUBLE_COMPLEX
#define MPI_C_LONG_DOUBLE_COMPLEX ISC_C_LONG_DOUBLE_COMPLEX
/* Address/Offset types  */
#define MPI_AINT                 ISC_AINT
#define MPI_OFFSET               ISC_OFFSET
#define MPI_COUNT                ISC_COUNT
/* C99 style ints (with size) */
#define MPI_INT8_T               ISC_INT8_T
#define MPI_INT16_T              ISC_INT16_T
#define MPI_INT32_T              ISC_INT32_T
#define MPI_INT64_T              ISC_INT64_T
#define MPI_UINT8_T              ISC_UINT8_T
#define MPI_UINT16_T             ISC_UINT16_T
#define MPI_UINT32_T             ISC_UINT32_T
#define MPI_UINT64_T             ISC_UINT64_T

/* Old MPI usage (lb and ub, maybe deprecated? */
#define MPI_LB                   ISC_LB
#define MPI_UB                   ISC_UB

/* Error values */
#define MPI_SUCCESS              ISC_SUCCESS             
#define MPI_ERR_BUFFER           ISC_ERR_BUFFER          
#define MPI_ERR_COUNT            ISC_ERR_COUNT           
#define MPI_ERR_TYPE             ISC_ERR_TYPE            
#define MPI_ERR_TAG              ISC_ERR_TAG             
#define MPI_ERR_COMM             ISC_ERR_COMM            
#define MPI_ERR_RANK             ISC_ERR_RANK            
#define MPI_ERR_ROOT             ISC_ERR_ROOT            
#define MPI_ERR_GROUP            ISC_ERR_GROUP           
#define MPI_ERR_OP               ISC_ERR_OP              
#define MPI_ERR_TOPOLOGY         ISC_ERR_TOPOLOGY        
#define MPI_ERR_DIMS             ISC_ERR_DIMS            
#define MPI_ERR_ARG              ISC_ERR_ARG             
#define MPI_ERR_UNKNOWN          ISC_ERR_UNKNOWN         
#define MPI_ERR_TRUNCATE         ISC_ERR_TRUNCATE        
#define MPI_ERR_OTHER            ISC_ERR_OTHER           
#define MPI_ERR_INTERN           ISC_ERR_INTERN          
#define MPI_ERR_IN_STATUS        ISC_ERR_IN_STATUS       
#define MPI_ERR_PENDING          ISC_ERR_PENDING         
#define MPI_ERR_REQUEST          ISC_ERR_REQUEST         
#define MPI_ERR_ACCESS           ISC_ERR_ACCESS
#define MPI_ERR_AMODE            ISC_ERR_AMODE
#define MPI_ERR_BAD_FILE         ISC_ERR_BAD_FILE
#define MPI_ERR_CONVERSION       ISC_ERR_CONVERSION
#define MPI_ERR_DUP_DATAREP      ISC_ERR_DUP_DATAREP
#define MPI_ERR_FILE_EXISTS      ISC_ERR_FILE_EXISTS
#define MPI_ERR_FILE_IN_USE      ISC_ERR_FILE_IN_USE
#define MPI_ERR_FILE             ISC_ERR_FILE
#define MPI_ERR_INFO             ISC_ERR_INFO
#define MPI_ERR_INFO_KEY         ISC_ERR_INFO_KEY
#define MPI_ERR_INFO_VALUE       ISC_ERR_INFO_VALUE
#define MPI_ERR_INFO_NOKEY       ISC_ERR_INFO_NOKEY
#define MPI_ERR_IO               ISC_ERR_IO
#define MPI_ERR_NAME             ISC_ERR_NAME
#define MPI_ERR_NO_MEM           ISC_ERR_NO_MEM
#define MPI_ERR_NOT_SAME         ISC_ERR_NOT_SAME
#define MPI_ERR_NO_SPACE         ISC_ERR_NO_SPACE
#define MPI_ERR_NO_SUCH_FILE     ISC_ERR_NO_SUCH_FILE
#define MPI_ERR_PORT             ISC_ERR_PORT
#define MPI_ERR_QUOTA            ISC_ERR_QUOTA
#define MPI_ERR_READ_ONLY        ISC_ERR_READ_ONLY
#define MPI_ERR_SERVICE          ISC_ERR_SERVICE
#define MPI_ERR_SPAWN            ISC_ERR_SPAWN
#define MPI_ERR_UNSUPPORTED_DATAREP ISC_ERR_UNSUPPORTED_DATAREP
#define MPI_ERR_UNSUPPORTED_OPERATION ISC_ERR_UNSUPPORTED_OPERATION
#define MPI_ERR_WIN              ISC_ERR_WIN             
#define MPI_ERR_BASE             ISC_ERR_BASE            
#define MPI_ERR_LOCKTYPE         ISC_ERR_LOCKTYPE
#define MPI_ERR_KEYVAL           ISC_ERR_KEYVAL
#define MPI_ERR_RMA_CONFLICT     ISC_ERR_RMA_CONFLICT
#define MPI_ERR_RMA_SYNC         ISC_ERR_RMA_SYNC
#define MPI_ERR_SIZE             ISC_ERR_SIZE
#define MPI_ERR_DISP             ISC_ERR_DISP
#define MPI_ERR_ASSERT           ISC_ERR_ASSERT          
#define MPI_ERR_RMA_RANGE        ISC_ERR_RMA_RANGE
#define MPI_ERR_RMA_ATTACH       ISC_ERR_RMA_ATTACH
#define MPI_ERR_RMA_SHARED       ISC_ERR_RMA_SHARED
#define MPI_ERR_RMA_FLAVOR       ISC_ERR_RMA_FLAVOR
#define MPI_ERR_LASTCODE         ISC_ERR_LASTCODE        

/* Error handlers */
#define MPI_ERRHANDLER_NULL      ISC_ERRHANDLER_NULL
#define MPI_ERRORS_ARE_FATAL     ISC_ERRORS_ARE_FATAL
#define MPI_ERRORS_RETURN        ISC_ERRORS_RETURN

/* Info objects */
#define MPI_INFO_NULL            ISC_INFO_NULL
#define MPI_INFO_ENV             ISC_INFO_ENV

/* Window objects */
#define MPI_WIN_NULL             ISC_WIN_NULL

/* File objects */
#define MPI_FILE_NULL            ISC_FILE_NULL

/* Misc */
#define MPI_ANY_SOURCE           ISC_ANY_SOURCE
#define MPI_PROC_NULL            ISC_PROC_NULL
#define MPI_ROOT                 ISC_ROOT
#define MPI_ANY_TAG              ISC_ANY_TAG
#define MPI_MAX_PROCESSOR_NAME   ISC_MAX_PROCESSOR_NAME
#define MPI_MAX_ERROR_STRING     ISC_MAX_ERROR_STRING
#define MPI_MAX_OBJECT_NAME      ISC_MAX_OBJECT_NAME
#define MPI_MAX_DATAREP_STRING   ISC_MAX_DATAREP_STRING
#define MPI_MAX_LIBRARY_VERSION_STRING ISC_MAX_LIBRARY_VERSION_STRING
#define MPI_UNDEFINED            ISC_UNDEFINED
#define MPI_CART                 ISC_CART
#define MPI_GRAPH                ISC_GRAPH
#define MPI_KEYVAL_INVALID       ISC_KEYVAL_INVALID
#define MPI_BSEND_OVERHEAD       ISC_BSEND_OVERHEAD
#define MPI_MAX_INFO_KEY         ISC_MAX_INFO_KEY
#define MPI_MAX_INFO_VAL         ISC_MAX_INFO_VAL
#define MPI_MAX_PORT_NAME        ISC_MAX_PORT_NAME
#define MPI_MODE_CREATE          ISC_MODE_CREATE
#define MPI_MODE_RDONLY          ISC_MODE_RDONLY
#define MPI_MODE_WRONLY          ISC_MODE_WRONLY
#define MPI_MODE_RDWR            ISC_MODE_RDWR
#define MPI_MODE_DELETE_ON_CLOSE ISC_MODE_DELETE_ON_CLOSE
#define MPI_MODE_UNIQUE_OPEN     ISC_MODE_UNIQUE_OPEN
#define MPI_MODE_EXCL            ISC_MODE_EXCL
#define MPI_MODE_APPEND          ISC_MODE_APPEND
#define MPI_MODE_SEQUENTIAL      ISC_MODE_SEQUENTIAL
#define MPI_MODE_NOCHECK         ISC_MODE_NOCHECK
#define MPI_MODE_NOPRECEDE       ISC_MODE_NOPRECEDE
#define MPI_MODE_NOPUT           ISC_MODE_NOPUT
#define MPI_MODE_NOSTORE         ISC_MODE_NOSTORE
#define MPI_MODE_NOSUCCEED       ISC_MODE_NOSUCCEED
#define MPI_SEEK_SET             ISC_SEEK_SET
#define MPI_SEEK_CUR             ISC_SEEK_CUR
#define MPI_SEEK_END             ISC_SEEK_END
#define MPI_COMM_TYPE_SHARED     ISC_COMM_TYPE_SHARED
#define MPI_DIST_GRAPH           ISC_DIST_GRAPH
#define MPI_WIN_FLAVOR_CREATE    ISC_WIN_FLAVOR_CREATE
#define MPI_WIN_FLAVOR_ALLOCATE  ISC_WIN_FLAVOR_ALLOCATE
#define MPI_WIN_FLAVOR_DYNAMIC   ISC_WIN_FLAVOR_DYNAMIC
#define MPI_WIN_FLAVOR_SHARED    ISC_WIN_FLAVOR_SHARED
#define MPI_WIN_SEPARATE         ISC_WIN_SEPARATE
#define MPI_WIN_UNIFIED          ISC_WIN_UNIFIED
#define MPI_ORDER_C              ISC_ORDER_C
#define MPI_ORDER_FORTRAN        ISC_ORDER_FORTRAN
#define MPI_DISTRIBUTE_BLOCK     ISC_DISTRIBUTE_BLOCK
#define MPI_DISTRIBUTE_CYCLIC    ISC_DISTRIBUTE_CYCLIC
#define MPI_DISTRIBUTE_NONE      ISC_DISTRIBUTE_NONE
#define MPI_DISTRIBUTE_DFLT_DARG ISC_DISTRIBUTE_DFLT_DARG
#define MPI_IDENT                ISC_IDENT
#define MPI_CONGRUENT            ISC_CONGRUENT
#define MPI_SIMILAR              ISC_SIMILAR
#define MPI_UNEQUAL              ISC_UNEQUAL  
#define MPI_TAG_UB               ISC_TAG_UB
#define MPI_HOST                 ISC_HOST
#define MPI_IO                   ISC_IO
#define MPI_WTIME_IS_GLOBAL      ISC_WTIME_IS_GLOBAL
#define MPI_LOCK_EXCLUSIVE       ISC_LOCK_EXCLUSIVE
#define MPI_LOCK_SHARED          ISC_LOCK_SHARED

#define MPI_COMBINER_NAMED   ISC_COMBINER_NAMED
#define MPI_COMBINER_DUP     ISC_COMBINER_DUP
#define MPI_COMBINER_CONTIGUOUS  ISC_COMBINER_CONTIGUOUS
#define MPI_COMBINER_VECTOR  ISC_COMBINER_VECTOR
#define MPI_COMBINER_HVECTOR_INTEGER ISC_COMBINER_HVECTOR_INTEGER
#define MPI_COMBINER_HVECTOR     ISC_COMBINER_HVECTOR
#define MPI_COMBINER_INDEXED     ISC_COMBINER_INDEXED
#define MPI_COMBINER_HINDEXED_INTEGER ISC_COMBINER_HINDEXED_INTEGER
#define MPI_COMBINER_HINDEXED    ISC_COMBINER_HINDEXED
#define MPI_COMBINER_INDEXED_BLOCK ISC_COMBINER_INDEXED_BLOCK
#define MPI_COMBINER_STRUCT_INTEGER ISC_COMBINER_STRUCT_INTEGER
#define MPI_COMBINER_STRUCT  ISC_COMBINER_STRUCT
#define MPI_COMBINER_SUBARRAY    ISC_COMBINER_SUBARRAY
#define MPI_COMBINER_DARRAY  ISC_COMBINER_DARRAY
#define MPI_COMBINER_F90_REAL    ISC_COMBINER_F90_REAL
#define MPI_COMBINER_F90_COMPLEX ISC_COMBINER_F90_COMPLEX
#define MPI_COMBINER_F90_INTEGER ISC_COMBINER_F90_INTEGER
#define MPI_COMBINER_RESIZED     ISC_COMBINER_RESIZED
#define MPI_COMBINER_HINDEXED_BLOCK ISC_COMBINER_HINDEXED_BLOCK
#define MPI_APPNUM               ISC_APPNUM
#define MPI_LASTUSEDCODE         ISC_LASTUSEDCODE
#define MPI_UNIVERSE_SIZE        ISC_UNIVERSE_SIZE
#define MPI_WIN_BASE             ISC_WIN_BASE
#define MPI_WIN_SIZE             ISC_WIN_SIZE
#define MPI_WIN_DISP_UNIT        ISC_WIN_DISP_UNIT
#define MPI_WIN_CREATE_FLAVOR    ISC_WIN_CREATE_FLAVOR
#define MPI_WIN_MODEL            ISC_WIN_MODEL
#define MPI_DISPLACEMENT_CURRENT ISC_DISPLACEMENT_CURRENT


/* Additional MISC */
#define MPI_BOTTOM               ((void *)ISC_BOTTOM)
#define MPI_IN_PLACE             ((void *)ISC_IN_PLACE)
#define MPI_ARGV_NULL            ((char **)ISC_ARGV_NULL)
#define MPI_ARGVS_NULL           ((char ***)ISC_ARGVS_NULL)
#define MPI_ERRCODES_IGNORE      ((int *)ISC_ERRCODES_IGNORE)
#define MPI_UNWEIGHTED           ((int *)ISC_UNWEIGHTED)
#define MPI_WEIGHTS_EMPTY        ((int *)ISC_WEIGHTS_EMPTY)

#define MPI_TYPECLASS_REAL       ISC_TYPECLASS_REAL
#define MPI_TYPECLASS_INTEGER    ISC_TYPECLASS_INTEGER
#define MPI_TYPECLASS_COMPLEX    ISC_TYPECLASS_COMPLEX

  /* SPECIAL HACK */
#define MPIO_Request MPI_Request
#define MPIO_Wait ISC_Wait
#define MPIO_Test ISC_Test

#define MPI_Send ISC_Send
#define MPI_Recv ISC_Recv
#define MPI_Get_count ISC_Get_count
#define MPI_Bsend ISC_Bsend
#define MPI_Ssend ISC_Ssend
#define MPI_Rsend ISC_Rsend
#define MPI_Buffer_attach ISC_Buffer_attach
#define MPI_Buffer_detach ISC_Buffer_detach
#define MPI_Isend ISC_Isend
#define MPI_Ibsend ISC_Ibsend
#define MPI_Issend ISC_Issend
#define MPI_Irsend ISC_Irsend
#define MPI_Irecv ISC_Irecv
#define MPI_Wait ISC_Wait
#define MPI_Test ISC_Test
#define MPI_Request_get_status ISC_Request_get_status
#define MPI_Request_free ISC_Request_free
#define MPI_Waitany ISC_Waitany
#define MPI_Testany ISC_Testany
#define MPI_Waitall ISC_Waitall
#define MPI_Testall ISC_Testall
#define MPI_Waitsome ISC_Waitsome
#define MPI_Testsome ISC_Testsome
#define MPI_Iprobe ISC_Iprobe
#define MPI_Probe ISC_Probe
#define MPI_Cancel ISC_Cancel
#define MPI_Test_cancelled ISC_Test_cancelled
#define MPI_Send_init ISC_Send_init
#define MPI_Bsend_init ISC_Bsend_init
#define MPI_Ssend_init ISC_Ssend_init
#define MPI_Rsend_init ISC_Rsend_init
#define MPI_Recv_init ISC_Recv_init
#define MPI_Start ISC_Start
#define MPI_Startall ISC_Startall
#define MPI_Sendrecv ISC_Sendrecv
#define MPI_Sendrecv_replace ISC_Sendrecv_replace
#define MPI_Type_contiguous ISC_Type_contiguous
#define MPI_Type_vector ISC_Type_vector
#define MPI_Type_hvector ISC_Type_hvector
#define MPI_Type_indexed ISC_Type_indexed
#define MPI_Type_hindexed ISC_Type_hindexed
#define MPI_Type_create_indexed_block ISC_Type_create_indexed_block
#define MPI_Type_create_hindexed_block ISC_Type_create_hindexed_block  
#define MPI_Type_create_hvector ISC_Type_create_hvector
#define MPI_Type_create_resized ISC_Type_create_resized
#define MPI_Type_struct ISC_Type_struct
#define MPI_Address ISC_Address
#define MPI_Type_extent ISC_Type_extent
#define MPI_Type_get_extent ISC_Type_get_extent
#define MPI_Type_get_extent_x ISC_Type_get_extent_x
#define MPI_Type_get_true_extent ISC_Type_get_true_extent
#define MPI_Type_get_true_extent_x ISC_Type_get_true_extent_x
#define MPI_Type_create_f90_real ISC_Type_create_f90_real
#define MPI_Type_create_f90_integer ISC_Type_create_f90_integer
#define MPI_Type_create_f90_complex ISC_Type_create_f90_complex
#define MPI_Type_size ISC_Type_size
#define MPI_Type_size_x ISC_Type_size_x
#define MPI_Type_lb ISC_Type_lb
#define MPI_Type_ub ISC_Type_ub
#define MPI_Type_commit ISC_Type_commit
#define MPI_Type_free ISC_Type_free
#define MPI_Get_elements ISC_Get_elements
#define MPI_Get_elements_x ISC_Get_elements_x
#define MPI_Pack ISC_Pack
#define MPI_Unpack ISC_Unpack
#define MPI_Pack_size ISC_Pack_size
#define MPI_Pack_external_size ISC_Pack_external_size
#define MPI_Barrier ISC_Barrier
#define MPI_Bcast ISC_Bcast
#define MPI_Gather ISC_Gather
#define MPI_Gatherv ISC_Gatherv
#define MPI_Scatter ISC_Scatter
#define MPI_Scatterv ISC_Scatterv
#define MPI_Allgather ISC_Allgather
#define MPI_Allgatherv ISC_Allgatherv
#define MPI_Alltoall ISC_Alltoall
#define MPI_Alltoallv ISC_Alltoallv
#define MPI_Reduce ISC_Reduce
#define MPI_Reduce_local ISC_Reduce_local
#define MPI_Op_create ISC_Op_create
#define MPI_Op_free ISC_Op_free
#define MPI_Op_commutative ISC_Op_commutative
#define MPI_Allreduce ISC_Allreduce
#define MPI_Reduce_scatter ISC_Reduce_scatter
#define MPI_Reduce_scatter_block ISC_Reduce_scatter_block
#define MPI_Scan ISC_Scan
#define MPI_Group_size ISC_Group_size
#define MPI_Group_rank ISC_Group_rank
#define MPI_Group_translate_ranks  ISC_Group_translate_ranks 
#define MPI_Group_compare ISC_Group_compare
#define MPI_Comm_group ISC_Comm_group
#define MPI_Group_union ISC_Group_union
#define MPI_Group_intersection ISC_Group_intersection
#define MPI_Group_difference ISC_Group_difference
#define MPI_Group_incl ISC_Group_incl
#define MPI_Group_excl ISC_Group_excl
#define MPI_Group_range_incl ISC_Group_range_incl
#define MPI_Group_range_excl ISC_Group_range_excl
#define MPI_Group_free ISC_Group_free
#define MPI_Comm_size ISC_Comm_size
#define MPI_Comm_rank ISC_Comm_rank
#define MPI_Comm_compare ISC_Comm_compare
#define MPI_Comm_dup ISC_Comm_dup
#define MPI_Comm_dup_with_info ISC_Comm_dup_with_info
#define MPI_Comm_create_group ISC_Comm_create_group
#define MPI_Comm_create ISC_Comm_create
#define MPI_Comm_idup ISC_Comm_idup
#define MPI_Comm_split_type ISC_Comm_split_type
#define MPI_Comm_split ISC_Comm_split
#define MPI_Comm_free ISC_Comm_free
#define MPI_Comm_test_inter ISC_Comm_test_inter
#define MPI_Comm_remote_size ISC_Comm_remote_size
#define MPI_Comm_remote_group ISC_Comm_remote_group
#define MPI_Intercomm_create ISC_Intercomm_create
#define MPI_Intercomm_merge ISC_Intercomm_merge
#define MPI_Keyval_create ISC_Keyval_create
#define MPI_Keyval_free ISC_Keyval_free
#define MPI_Attr_put ISC_Attr_put
#define MPI_Attr_get ISC_Attr_get
#define MPI_Attr_delete ISC_Attr_delete
#define MPI_Topo_test ISC_Topo_test
#define MPI_Cart_create ISC_Cart_create
#define MPI_Dims_create ISC_Dims_create
#define MPI_Graph_create ISC_Graph_create
#define MPI_Graphdims_get ISC_Graphdims_get
#define MPI_Graph_get ISC_Graph_get
#define MPI_Cartdim_get ISC_Cartdim_get
#define MPI_Cart_get ISC_Cart_get
#define MPI_Cart_rank ISC_Cart_rank
#define MPI_Cart_coords ISC_Cart_coords
#define MPI_Graph_neighbors_count ISC_Graph_neighbors_count
#define MPI_Graph_neighbors ISC_Graph_neighbors
#define MPI_Cart_shift ISC_Cart_shift
#define MPI_Cart_sub ISC_Cart_sub
#define MPI_Cart_map ISC_Cart_map
#define MPI_Graph_map ISC_Graph_map
#define MPI_Get_processor_name ISC_Get_processor_name
#define MPI_Get_version ISC_Get_version
#define MPI_Get_library_version ISC_Get_library_version
#define MPI_Errhandler_create ISC_Errhandler_create
#define MPI_Errhandler_set ISC_Errhandler_set
#define MPI_Errhandler_get ISC_Errhandler_get
#define MPI_Errhandler_free ISC_Errhandler_free
#define MPI_Error_string ISC_Error_string
#define MPI_Error_class ISC_Error_class
#define MPI_Wtime ISC_Wtime
#define MPI_Wtick ISC_Wtick
#define MPI_Init ISC_Init
#define MPI_Finalize ISC_Finalize
#define MPI_Initialized ISC_Initialized
#define MPI_Abort ISC_Abort
#define MPI_Pcontrol ISC_Pcontrol
#define MPI_Close_port ISC_Close_port
#define MPI_Comm_accept ISC_Comm_accept
#define MPI_Comm_connect ISC_Comm_connect
#define MPI_Comm_disconnect ISC_Comm_disconnect
#define MPI_Comm_get_parent ISC_Comm_get_parent
#define MPI_Comm_join ISC_Comm_join
#define MPI_Comm_spawn ISC_Comm_spawn
#define MPI_Comm_spawn_multiple ISC_Comm_spawn_multiple
#define MPI_Lookup_name ISC_Lookup_name
#define MPI_Open_port ISC_Open_port
#define MPI_Publish_name ISC_Publish_name
#define MPI_Unpublish_name ISC_Unpublish_name
#define MPI_Accumulate ISC_Accumulate
#define MPI_Get ISC_Get
#define MPI_Put ISC_Put
#define MPI_Get_accumulate ISC_Get_accumulate
#define MPI_Raccumulate ISC_Raccumulate
#define MPI_Rget ISC_Rget
#define MPI_Rput ISC_Rput
#define MPI_Rget_accumulate ISC_Rget_accumulate
#define MPI_Win_complete ISC_Win_complete
#define MPI_Win_create ISC_Win_create
#define MPI_Win_create_dynamic ISC_Win_create_dynamic
#define MPI_Win_detach ISC_Win_detach
#define MPI_Win_attach ISC_Win_attach
#define MPI_Win_shared_query ISC_Win_shared_query
#define MPI_Win_allocate ISC_Win_allocate
#define MPI_Win_allocate_shared ISC_Win_allocate_shared
#define MPI_Win_fence ISC_Win_fence
#define MPI_Win_free ISC_Win_free
#define MPI_Win_get_group ISC_Win_get_group
#define MPI_Win_get_info ISC_Win_get_info
#define MPI_Win_set_info ISC_Win_set_info
#define MPI_Win_lock ISC_Win_lock
#define MPI_Win_post ISC_Win_post
#define MPI_Win_start ISC_Win_start
#define MPI_Win_test ISC_Win_test
#define MPI_Win_unlock ISC_Win_unlock
#define MPI_Win_wait ISC_Win_wait
#define MPI_Win_sync ISC_Win_sync
#define MPI_Win_allocate ISC_Win_allocate
#define MPI_Win_allocate_shared ISC_Win_allocate_shared
#define MPI_Alloc_mem ISC_Alloc_mem
#define MPI_Free_mem ISC_Free_mem   
#define MPI_Alltoallw ISC_Alltoallw
#define MPI_Exscan ISC_Exscan
#define MPI_Add_error_class ISC_Add_error_class
#define MPI_Add_error_code ISC_Add_error_code
#define MPI_Add_error_string ISC_Add_error_string
#define MPI_Comm_call_errhandler ISC_Comm_call_errhandler
#define MPI_Comm_delete_attr ISC_Comm_delete_attr
#define MPI_Comm_get_attr ISC_Comm_get_attr
#define MPI_Comm_get_name ISC_Comm_get_name
#define MPI_Comm_set_attr ISC_Comm_set_attr
#define MPI_Comm_set_name ISC_Comm_set_name
#define MPI_Comm_set_info ISC_Comm_set_info
#define MPI_Comm_get_info ISC_Comm_get_info
#define MPI_Comm_set_errhandler ISC_Comm_set_errhandler
#define MPI_File_get_view ISC_File_get_view
#define MPI_File_set_view ISC_File_set_view
#define MPI_File_set_info ISC_File_set_info
#define MPI_File_get_errhandler ISC_File_get_errhandler
#define MPI_File_call_errhandler ISC_File_call_errhandler
#define MPI_Grequest_complete ISC_Grequest_complete
#define MPI_Grequest_start ISC_Grequest_start
#define MPI_Init_thread ISC_Init_thread
#define MPI_Is_thread_main ISC_Is_thread_main
#define MPI_Query_thread ISC_Query_thread
#define MPI_Status_set_cancelled ISC_Status_set_cancelled
#define MPI_Status_set_elements ISC_Status_set_elements
#define MPI_Status_set_elements_x ISC_Status_set_elements_x
#define MPI_Comm_call_errhandler ISC_Comm_call_errhandler
#define MPI_Comm_create_errhandler ISC_Comm_create_errhandler
#define MPI_Comm_get_errhandler ISC_Comm_get_errhandler
#define MPI_Comm_create_keyval ISC_Comm_create_keyval
#define MPI_Comm_free_keyval ISC_Comm_free_keyval
#define MPI_Type_create_keyval ISC_Type_create_keyval
#define MPI_Type_delete_attr ISC_Type_delete_attr
#define MPI_Type_dup ISC_Type_dup
#define MPI_Type_free_keyval ISC_Type_free_keyval
#define MPI_Type_get_attr ISC_Type_get_attr
#define MPI_Type_get_contents ISC_Type_get_contents
#define MPI_Type_get_envelope ISC_Type_get_envelope
#define MPI_Type_get_name ISC_Type_get_name
#define MPI_Type_set_attr ISC_Type_set_attr
#define MPI_Type_set_name ISC_Type_set_name
#define MPI_Type_match_size ISC_Type_match_size
#define MPI_Win_create_errhandler ISC_Win_create_errhandler
#define MPI_Win_call_errhandler ISC_Win_call_errhandler
#define MPI_Win_get_errhandler ISC_Win_get_errhandler
#define MPI_Win_create_keyval ISC_Win_create_keyval
#define MPI_Win_delete_attr ISC_Win_delete_attr
#define MPI_Win_free_keyval ISC_Win_free_keyval
#define MPI_Win_get_attr ISC_Win_get_attr
#define MPI_Win_get_name ISC_Win_get_name
#define MPI_Win_set_attr ISC_Win_set_attr
#define MPI_Win_set_name ISC_Win_set_name

#define MPI_Comm_errhandler_function ISC_Comm_errhandler_fn
#define MPI_Comm_call_errhandler ISC_Comm_call_errhandler
#define MPI_Comm_errhandler_fn ISC_Comm_errhandler_fn
#define MPI_File_errhandler_fn ISC_File_errhandler_fn
#define MPI_File_errhandler_function ISC_File_errhandler_fn
#define MPI_Win_errhandler_fn ISC_Win_errhandler_fn
#define MPI_Win_errhandler_function ISC_Win_errhandler_fn
#define MPI_Win_set_errhandler ISC_Win_set_errhandler

#define MPI_Grequest_cancel_function ISC_Grequest_cancel_function
#define MPI_Grequest_free_function ISC_Grequest_free_function
#define MPI_Grequest_query_function ISC_Grequest_query_function

#define MPI_Datarep_conversion_function ISC_Datarep_conversion_function
#define MPI_Datarep_extent_function ISC_Datarep_extent_function

#define MPI_Comm_copy_attr_function ISC_Comm_copy_attr_function
#define MPI_Comm_delete_attr_function ISC_Comm_delete_attr_function

#define MPI_Type_copy_attr_function ISC_Type_copy_attr_function
#define MPI_Type_delete_attr_function ISC_Type_delete_attr_function

#define MPI_Win_copy_attr_function ISC_Win_copy_attr_function
#define MPI_Win_delete_attr_function ISC_Win_delete_attr_function

#define MPI_Info_set ISC_Info_set
#define MPI_Info_free ISC_Info_free
#define MPI_Info_get_nkeys ISC_Info_get_nkeys
#define MPI_Info_get_nthkey ISC_Info_get_nthkey
#define MPI_Info_get_valuelen ISC_Info_get_valuelen

#define MPI_File_open ISC_File_open
#define MPI_File_close ISC_File_close
#define MPI_File_delete ISC_File_delete
#define MPI_File_set_size ISC_File_set_size
#define MPI_File_preallocate ISC_File_preallocate
#define MPI_File_get_size ISC_File_get_size
#define MPI_File_get_group ISC_File_get_group
#define MPI_File_get_amode ISC_File_get_amode
#define MPI_File_set_info ISC_File_set_info
#define MPI_File_get_info ISC_File_get_info
#define MPI_File_set_view ISC_File_set_view
#define MPI_File_get_view ISC_File_get_view
#define MPI_File_read_at ISC_File_read_at
#define MPI_File_read_at_all ISC_File_read_at_all
#define MPI_File_write_at ISC_File_write_at
#define MPI_File_write_at_all ISC_File_write_at_all
#define MPI_File_iread_at ISC_File_iread_at
#define MPI_File_iread_at_all ISC_File_iread_at_all
#define MPI_File_iwrite_at ISC_File_iwrite_at
#define MPI_File_iwrite_at_all ISC_File_iwrite_at_all
#define MPI_File_read ISC_File_read
#define MPI_File_read_all ISC_File_read_all
#define MPI_File_write ISC_File_write
#define MPI_File_write_all ISC_File_write_all
#define MPI_File_iread ISC_File_iread
#define MPI_File_iwrite ISC_File_iwrite
#define MPI_File_iread_all ISC_File_iread_all
#define MPI_File_iwrite_all ISC_File_iwrite_all
#define MPI_File_seek ISC_File_seek
#define MPI_File_get_position ISC_File_get_position
#define MPI_File_get_byte_offset ISC_File_get_byte_offset
#define MPI_File_read_shared ISC_File_read_shared
#define MPI_File_write_shared ISC_File_write_shared
#define MPI_File_iread_shared ISC_File_iread_shared
#define MPI_File_iwrite_shared ISC_File_iwrite_shared
#define MPI_File_read_ordered ISC_File_read_ordered
#define MPI_File_write_ordered ISC_File_write_ordered
#define MPI_File_seek_shared ISC_File_seek_shared
#define MPI_File_get_position_shared ISC_File_get_position_shared
#define MPI_File_read_at_all_begin ISC_File_read_at_all_begin
#define MPI_File_read_at_all_end ISC_File_read_at_all_end
#define MPI_File_write_at_all_begin ISC_File_write_at_all_begin
#define MPI_File_write_at_all_end ISC_File_write_at_all_end
#define MPI_File_read_all_begin ISC_File_read_all_begin
#define MPI_File_read_all_end ISC_File_read_all_end
#define MPI_File_write_all_begin ISC_File_write_all_begin
#define MPI_File_write_all_end ISC_File_write_all_end
#define MPI_File_read_ordered_begin ISC_File_read_ordered_begin
#define MPI_File_read_ordered_end ISC_File_read_ordered_end
#define MPI_File_write_ordered_begin ISC_File_write_ordered_begin
#define MPI_File_write_ordered_end ISC_File_write_ordered_end
#define MPI_File_get_type_extent ISC_File_get_type_extent
#define MPI_Register_datarep ISC_Register_datarep
#define MPI_File_set_atomicity ISC_File_set_atomicity
#define MPI_File_get_atomicity ISC_File_get_atomicity
#define MPI_File_sync ISC_File_sync
#define MPI_Type_create_subarray ISC_Type_create_subarray
#define MPI_Type_create_darray ISC_Type_create_darray
#define MPI_File_create_errhandler ISC_File_create_errhandler
#define MPI_File_get_errhandler ISC_File_get_errhandler
#define MPI_File_set_errhandler ISC_File_set_errhandler

/* Previously missing - maybe redo in a more logical location? */
#define MPI_Comm_c2f ISC_Comm_c2f
#define MPI_Comm_f2c ISC_Comm_f2c
#define MPI_Errhandler_c2f ISC_Errhandler_c2f
#define MPI_Errhandler_f2c ISC_Errhandler_f2c
#define MPI_File_c2f ISC_File_c2f
#define MPI_File_f2c ISC_File_f2c
#define MPI_Group_c2f ISC_Group_c2f
#define MPI_Group_f2c ISC_Group_f2c
#define MPI_Info_c2f ISC_Info_c2f
#define MPI_Info_f2c ISC_Info_f2c
#define MPI_Message_c2f ISC_Message_c2f
#define MPI_Message_f2c ISC_Message_f2c
#define MPI_Op_c2f ISC_Op_c2f
#define MPI_Op_f2c ISC_Op_f2c
#define MPI_Request_c2f ISC_Request_c2f
#define MPI_Request_f2c ISC_Request_f2c
#define MPI_Status_c2f ISC_Status_c2f
#define MPI_Status_f2c ISC_Status_f2c
#define MPI_Type_c2f ISC_Type_c2f
#define MPI_Type_f2c ISC_Type_f2c
#define MPI_Win_c2f ISC_Win_c2f
#define MPI_Win_f2c ISC_Win_f2c

/* MPI 3 functions */
#define MPI_Improbe ISC_Improbe
#define MPI_Mprobe ISC_Mprobe
#define MPI_Imrecv ISC_Imrecv
#define MPI_Mrecv ISC_Mrecv

#define MPI_Compare_and_swap ISC_Compare_and_swap
#define MPI_Fetch_and_op ISC_Fetch_and_op
#define MPI_Finalized ISC_Finalized
#define MPI_Get_accumulate ISC_Get_accumulate
#define MPI_Get_address ISC_Get_address
#define MPI_Iallgather ISC_Iallgather
#define MPI_Iallgatherv ISC_Iallgatherv
#define MPI_Iallreduce ISC_Iallreduce
#define MPI_Ialltoall ISC_Ialltoall
#define MPI_Ialltoallv ISC_Ialltoallv
#define MPI_Ialltoallw ISC_Ialltoallw
#define MPI_Ibarrier ISC_Ibarrier
#define MPI_Ibcast ISC_Ibcast
#define MPI_Iexscan ISC_Iexscan
#define MPI_Igather ISC_Igather
#define MPI_Igatherv ISC_Igatherv
#define MPI_Info_create ISC_Info_create
#define MPI_Info_delete ISC_Info_delete
#define MPI_Info_dup ISC_Info_dup
#define MPI_Info_get ISC_Info_get
#define MPI_Ireduce ISC_Ireduce
#define MPI_Ireduce_scatter_block ISC_Ireduce_scatter_block
#define MPI_Ireduce_scatter ISC_Ireduce_scatter
#define MPI_Iscan ISC_Iscan
#define MPI_Iscatter ISC_Iscatter
#define MPI_Iscatterv ISC_Iscatterv
#define MPI_Pack_external ISC_Pack_external
#define MPI_Unpack_external ISC_Unpack_external
#define MPI_Type_create_hindexed ISC_Type_create_hindexed
#define MPI_Type_create_struct ISC_Type_create_struct
#define MPI_Win_flush ISC_Win_flush
#define MPI_Win_flush_all ISC_Win_flush_all
#define MPI_Win_flush_local ISC_Win_flush_local
#define MPI_Win_flush_local_all ISC_Win_flush_local_all
#define MPI_Win_flush ISC_Win_flush
#define MPI_Win_lock_all ISC_Win_lock_all
#define MPI_Win_unlock_all ISC_Win_unlock_all

#define MPI_Graph_neighbors_count ISC_Graph_neighbors_count
#define MPI_Graph_neighbors ISC_Graph_neighbors
#define MPI_Dist_graph_neighbors_count ISC_Dist_graph_neighbors_count
#define MPI_Dist_graph_neighbors ISC_Dist_graph_neighbors
#define MPI_Dist_graph_create_adjacent ISC_Dist_graph_create_adjacent
#define MPI_Dist_graph_create ISC_Dist_graph_create

#define MPI_Ineighbor_allgather ISC_Ineighbor_allgather
#define MPI_Ineighbor_allgatherv ISC_Ineighbor_allgatherv
#define MPI_Ineighbor_alltoall ISC_Ineighbor_alltoall
#define MPI_Ineighbor_alltoallv ISC_Ineighbor_alltoallv
#define MPI_Ineighbor_alltoallw ISC_Ineighbor_alltoallw
#define MPI_Neighbor_allgather ISC_Neighbor_allgather
#define MPI_Neighbor_allgatherv ISC_Neighbor_allgatherv
#define MPI_Neighbor_alltoall ISC_Neighbor_alltoall
#define MPI_Neighbor_alltoallv ISC_Neighbor_alltoallv
#define MPI_Neighbor_alltoallw ISC_Neighbor_alltoallw

#define MPI_NULL_COPY_FN ((ISC_Copy_function *)ISC_NULL_COPY_FN)
#define MPI_NULL_DELETE_FN ((ISC_Delete_function *)ISC_NULL_DELETE_FN)
#define MPI_COMM_NULL_COPY_FN ((ISC_Copy_function *)ISC_NULL_COPY_FN)
#define MPI_COMM_NULL_DELETE_FN ((ISC_Delete_function *)ISC_NULL_DELETE_FN)
#define MPI_WIN_NULL_COPY_FN MPI_NULL_COPY_FN
#define MPI_WIN_NULL_DELETE_FN MPI_NULL_DELETE_FN
#define MPI_TYPE_NULL_COPY_FN MPI_NULL_COPY_FN
#define MPI_TYPE_NULL_DELETE_FN MPI_NULL_DELETE_FN
#define MPI_DUP_FN ISC_Dup_fn

#define MPI_Aint_add ISC_Aint_add
#define MPI_Aint_diff ISC_Aint_diff

#define MPI_THREAD_SINGLE ISC_THREAD_SINGLE
#define MPI_THREAD_FUNNELED ISC_THREAD_FUNNELED
#define MPI_THREAD_SERIALIZED ISC_THREAD_SERIALIZED
#define MPI_THREAD_MULTIPLE ISC_THREAD_MULTIPLE

#if 0
#define MPIX_Status_set_source ISCX_Status_set_source
#define MPIX_Status_get_source ISCX_Status_get_source
#define MPIX_Status_set_tag ISCX_Status_set_tag
#define MPIX_Status_get_tag ISCX_Status_get_tag
#define MPIX_Status_set_error ISCX_Status_set_error
#define MPIX_Status_get_error ISCX_Status_get_error
#endif

extern int ISC_Dup_fn(ISC_Comm oldcomm, int keyval, void *extra, void *attr_in, void *attr_out, int *flag);

#define TYPESHARED(t) (((t) != ISC_COMM_TYPE_SHARED) ? (t) : ((api_use_ints *)(active_miscs->api_declared))[ISC_COMM_TYPE_SHARED].mpi_const)
#define UNDEFINED(t) (((t) != ISC_UNDEFINED) ? (t) : ((api_use_ints *)(active_miscs->api_declared))[ISC_UNDEFINED_].mpi_const)
#define UNCOLOR(c) (((c) != ISC_UNDEFINED) ? (c) : ((api_use_ints *)(active_miscs->api_declared))[ISC_UNDEFINED_].mpi_const)
#define MSGNOPROC(m) (((m) != ISC_MESSAGE_NO_PROC) ? (m) : ((api_use_ints *)(active_miscs->api_declared))[ISC_MESSAGE_NO_PROC_].mpi_const)
#define PROCNULL(p) (((p) != ISC_PROC_NULL) ? (p) : ((api_use_ints *)(active_miscs->api_declared))[ISC_PROC_NULL_].mpi_const)
#define ISROOT(p) (((p) != ISC_ROOT) ? (p) : ((api_use_ints *)(active_miscs->api_declared))[ISC_ROOT_].mpi_const)
#define ANYSRC(s) (((s) == ISC_ANY_SOURCE) ? ((api_use_ints *)(active_miscs->api_declared))[ISC_ANY_SOURCE_].mpi_const : PROCNULL(s))
#define ANYTAG(t) (((t) != ISC_ANY_TAG) ? (t) : ((api_use_ints *)(active_miscs->api_declared))[ISC_ANY_TAG_].mpi_const)
#define SIGNORE(s) (((s) != (MPI_Status *)ISC_STATUS_IGNORE) ? (MPI_Status *)s->reserved : ((api_use_ptrs *)(active_addrs->api_declared))[ISC_STATUS_IGNORE].mpi_const)
#define ERRIGNORE(e) (((e) != (int *)ISC_ERRCODES_IGNORE) ? (e) : ((api_use_ptrs *)(active_addrs->api_declared))[ISC_ERRCODES_IGNORE].mpi_const)
#define BOTTOM(buf) (((buf) != (void *)ISC_BOTTOM) ? (buf) : ((api_use_ptrs *)(active_addrs->api_declared))[ISC_BOTTOM].mpi_const)
#define UNWEIGHTED(w) (((w) != (void *)ISC_UNWEIGHTED) ? (w) : ((api_use_ptrs *)(active_addrs->api_declared))[ISC_UNWEIGHTED].mpi_const)
#define INPLACE(buf) (((buf) != (void *)ISC_IN_PLACE) ? BOTTOM(buf) : ((api_use_ptrs *)(active_addrs->api_declared))[ISC_IN_PLACE].mpi_const)
#define ARGVNULL(arg) (((arg) != (char **)ISC_ARGV_NULL) ? (arg) : ((api_use_ptrs *)(active_addrs->api_declared))[ISC_ARGV_NULL].mpi_const)
#define NULLCOPYFN(f) (((f) != (void *)ISC_NULL_COPY_FN) ? ((callbacks_use_integers > 0) ? \
                                (MPI_Copy_function *)ISC_Integer_comm_copy_function : \
                                (MPI_Copy_function *)ISC_Pointer_comm_copy_function) : \
               ((api_use_ptrs *)(active_addrs->api_declared))[ISC_NULL_COPY_FN].mpi_const)
#define NULLDELFN(f)  (((f) != (void *)ISC_NULL_DELETE_FN) ? ((callbacks_use_integers > 0) ? \
                                  (MPI_Delete_function *)ISC_Integer_comm_delete_function : \
                                  (MPI_Delete_function *)ISC_Pointer_comm_delete_function) : \
               ((api_use_ptrs *)(active_addrs->api_declared))[ISC_NULL_DELETE_FN].mpi_const)
#define NULLTYPCOPYFN(f) (((f) != (void *)ISC_NULL_COPY_FN) ? ((callbacks_use_integers > 0) ? \
                                   (MPI_Type_copy_attr_function *)ISC_Integer_datatype_copy_function : \
                                   (MPI_Type_copy_attr_function *)ISC_Pointer_datatype_copy_function) : \
              ((api_use_ptrs *)(active_addrs->api_declared))[ISC_NULL_COPY_FN].mpi_const)
#define NULLTYPDELFN(f)  (((f) != (void *)ISC_NULL_DELETE_FN) ? ((callbacks_use_integers > 0) ? \
                                 (MPI_Type_delete_attr_function *)ISC_Integer_datatype_delete_function : \
                                 (MPI_Type_delete_attr_function *)ISC_Pointer_datatype_delete_function) : \
              ((api_use_ptrs *)(active_addrs->api_declared))[ISC_NULL_DELETE_FN].mpi_const)
#define NULLWINCOPYFN(f) (((f) != (void *)ISC_NULL_COPY_FN) ? ((callbacks_use_integers > 0) ? \
                                   (MPI_Win_copy_attr_function *)ISC_Integer_win_copy_function : \
                                   (MPI_Win_copy_attr_function *)ISC_Pointer_win_copy_function) : \
              ((api_use_ptrs *)(active_addrs->api_declared))[ISC_NULL_COPY_FN].mpi_const)
#define NULLWINDELFN(f)  (((f) != (void *)ISC_NULL_DELETE_FN) ? ((callbacks_use_integers > 0) ? \
                                 (MPI_Win_delete_attr_function *)ISC_Integer_win_delete_function : \
                                 (MPI_Win_delete_attr_function *)ISC_Pointer_win_delete_function) : \
              ((api_use_ptrs *)(active_addrs->api_declared))[ISC_NULL_DELETE_FN].mpi_const)

/* Fortran versions of the above macros */
#define FBOTTOM(buf) (((buf) != (void *)__true_fortran_bottom) ? (buf) : MPI_BOTTOM)
#define FINPLACE(buf) (((buf) != (void *)__true_fortran_in_place) ? FBOTTOM(buf) : MPI_IN_PLACE)


extern int true_mpi_status_size;
extern int callbacks_use_integers;

extern f_common_t *__true_fortran_bottom;
extern int *__true_fortran_in_place;
extern int *__true_fortran_argv_null;
extern int *__true_fortran_argvs_null;
extern int *__true_fortran_errcodes_ignore;
extern int *__true_fortran_status_ignore;
extern int *__true_fortran_statuses_ignore;

extern int locate_saved_copy_callback(int, int, callback_t, keyvalpair_t **);
extern int locate_saved_delete_callback(int, int, callback_t, keyvalpair_t **);
extern int save_user_copy_callback(void *, int, int, callback_t );
extern int save_user_delete_callback(void *, int, int, callback_t);  
extern int maybe_update_callbacks(int, int, callback_t);
extern int remove_object_keyval_callbacks(int, int, callback_t);
extern int maybe_dup_internal_reference(int, int, int, callback_t);
extern int attr_reference_exists(int, int, callback_t);

extern int ISC_Integer_comm_copy_function (int , int , void *, void *, void *, int *);
extern int ISC_Integer_comm_delete_function (int, int , void *, void *);
extern int ISC_Pointer_comm_copy_function (void * , int , void *, void *, void *, int *);
extern int ISC_Pointer_comm_delete_function (void *, int , void *, void *);

extern int ISC_Integer_datatype_copy_function (int , int , void *, void *, void *, int *);
extern int ISC_Integer_datatype_delete_function (int, int , void *, void *);
extern int ISC_Pointer_datatype_copy_function (void * , int , void *, void *, void *, int *);
extern int ISC_Pointer_datatype_delete_function (void *, int , void *, void *);

extern int ISC_Integer_win_copy_function (int , int , void *, void *, void *, int *);
extern int ISC_Integer_win_delete_function (int, int , void *, void *);
extern int ISC_Pointer_win_copy_function (void * , int , void *, void *, void *, int *);
extern int ISC_Pointer_win_delete_function (void *, int , void *, void *);


#if defined(__cplusplus)
}
#endif

#endif
