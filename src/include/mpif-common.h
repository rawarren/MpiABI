!
!  The constants defined within this file should meet the requirements
!  for a fortran 77 style interface as defined by the MPI-1.2 and MPI-2.0
!  standards:
!   “MPI: A Message-Passing Interface Standard, June 12, 1995”
!          (MPI-1.1) from the MPI-1 Forum, and
!   “MPI-2: Extensions to the Message-Passing Interface, July, 1997”
!  respectively, found at the MPI-2 Forum, along with errata documents 
!  also at the MPI Forum.
!
!  The general format of the fortran include files is taken from
!  the OpenMPI distribution.  The Interactive SuperComputing
!  version differs in the parameter declarations to match the
!  'C' definitions and thus avoids translating between these
!  common languages.
!
!  Notice:         - This file is based in part on 
!                    contributions from the following group
!
!  -  OpenMPI ( version 1.2.3 )
!     Copyright (c) 2004-2006 The Trustees of Indiana University and
!               Indiana University Research and Technology Corporation.
!     Copyright (c) 2004-2005 The University of Tennessee and The University
!               Tennessee Research Foundation.
!     Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
!               University of Stuttgart.
!     Copyright (c) 2004-2005 The Regents of the University of California.
!     Copyright (c) 2006      Cisco Systems, Inc.

!
!     MPI version
!
      integer MPI_VERSION, MPI_SUBVERSION

      parameter (MPI_VERSION=2)
      parameter (MPI_SUBVERSION=0)
!
!     Miscellaneous constants
!
      integer MPI_ANY_SOURCE, MPI_ANY_TAG
      integer MPI_PROC_NULL, MPI_MAX_PROCESSOR_NAME
      integer MPI_ROOT, MPI_MAX_DATAREP_STRING
      integer MPI_MAX_ERROR_STRING, MPI_UNDEFINED
      integer MPI_CART, MPI_GRAPH, MPI_KEYVAL_INVALID
      integer MPI_SOURCE, MPI_TAG, MPI_ERROR
      integer MPI_TAG_UB, MPI_HOST, MPI_IO, MPI_WTIME_IS_GLOBAL
      integer MPI_APPNUM, MPI_LASTUSEDCODE, MPI_UNIVERSE_SIZE
      integer MPI_BSEND_OVERHEAD
      integer MPI_MAX_INFO_KEY, MPI_MAX_INFO_VAL
      integer MPI_MAX_PORT_NAME, MPI_MAX_OBJECT_NAME
      integer MPI_ORDER_C, MPI_ORDER_FORTRAN
      integer MPI_DISTRIBUTE_BLOCK, MPI_DISTRIBUTE_CYCLIC
      integer MPI_DISTRIBUTE_NONE, MPI_DISTRIBUTE_DFLT_DARG
      integer MPI_TYPECLASS_INTEGER, MPI_TYPECLASS_REAL
      integer MPI_TYPECLASS_COMPLEX
      integer MPI_SEEK_SET, MPI_SEEK_CUR, MPI_SEEK_END 
      integer MPI_MODE_CREATE
      integer MPI_MODE_RDONLY, MPI_MODE_WRONLY, MPI_MODE_RDWR
      integer MPI_MODE_DELETE_ON_CLOSE, MPI_MODE_UNIQUE_OPEN
      integer MPI_MODE_EXCL, MPI_MODE_APPEND, MPI_MODE_SEQUENTIAL
      integer MPI_DISPLACEMENT_CURRENT
      integer MPI_MODE_NOCHECK, MPI_MODE_NOPRECEDE, MPI_MODE_NOPUT
      integer MPI_MODE_NOSTORE, MPI_MODE_NOSUCCEED
      integer MPI_LOCK_EXCLUSIVE, MPI_LOCK_SHARED
      integer MPI_WIN_BASE, MPI_WIN_SIZE, MPI_WIN_DISP_UNIT
      
      parameter (MPI_PROC_NULL=-1)
      parameter (MPI_ANY_SOURCE=-2)
      parameter (MPI_ANY_TAG=-3)
      parameter (MPI_ROOT=-4)
      parameter (MPI_MAX_PROCESSOR_NAME=255)
      parameter (MPI_MAX_ERROR_STRING=255)
      parameter (MPI_MAX_DATAREP_STRING=255)
      parameter (MPI_UNDEFINED=-5)
      parameter (MPI_CART=16)
      parameter (MPI_GRAPH=17)
      parameter (MPI_KEYVAL_INVALID=-6)
      parameter (MPI_SOURCE=1)
      parameter (MPI_TAG=2)
      parameter (MPI_ERROR=3)
      parameter (MPI_TAG_UB=6)
      parameter (MPI_HOST=7)
      parameter (MPI_IO=8)
      parameter (MPI_WTIME_IS_GLOBAL=9)
      parameter (MPI_APPNUM=4)
      parameter (MPI_LASTUSEDCODE=5)
      parameter (MPI_UNIVERSE_SIZE=6)
      parameter (MPI_WIN_BASE=7)
      parameter (MPI_WIN_SIZE=8)
      parameter (MPI_WIN_DISP_UNIT=9)
      
      parameter (MPI_TYPECLASS_REAL=1)
      parameter (MPI_TYPECLASS_INTEGER=2)
      parameter (MPI_TYPECLASS_COMPLEX=3)
      parameter (MPI_BSEND_OVERHEAD=128)
      parameter (MPI_MAX_INFO_KEY=35)
      parameter (MPI_MAX_INFO_VAL=255)
      parameter (MPI_MAX_PORT_NAME=35)
      parameter (MPI_MAX_OBJECT_NAME=63)
      parameter (MPI_ORDER_C=0)
      parameter (MPI_ORDER_FORTRAN=1)
      parameter (MPI_DISTRIBUTE_BLOCK=12)
      parameter (MPI_DISTRIBUTE_CYCLIC=13)
      parameter (MPI_DISTRIBUTE_NONE=14)
      parameter (MPI_DISTRIBUTE_DFLT_DARG=15)
      parameter (MPI_DISPLACEMENT_CURRENT=42)
      parameter (MPI_MODE_CREATE=43)
      parameter (MPI_MODE_RDONLY=44)
      parameter (MPI_MODE_WRONLY=45)
      parameter (MPI_MODE_RDWR=46)
      parameter (MPI_MODE_DELETE_ON_CLOSE=47)
      parameter (MPI_MODE_UNIQUE_OPEN=48)
      parameter (MPI_MODE_EXCL=49)
      parameter (MPI_MODE_APPEND=50)
      parameter (MPI_MODE_SEQUENTIAL=51)
      parameter (MPI_MODE_NOCHECK=52)
      parameter (MPI_MODE_NOPRECEDE=53)
      parameter (MPI_MODE_NOPUT=54)
      parameter (MPI_MODE_NOSTORE=55)
      parameter (MPI_MODE_NOSUCCEED=56)
      parameter (MPI_LOCK_EXCLUSIVE=57)
      parameter (MPI_LOCK_SHARED=58)
      parameter (MPI_SEEK_SET=59)
      parameter (MPI_SEEK_CUR=60)
      parameter (MPI_SEEK_END=61)

      integer MPI_BOTTOM
      integer MPI_IN_PLACE
      integer MPI_ARGV_NULL
      integer MPI_ARGVS_NULL
      integer MPI_ERRCODES_IGNORE
      integer MPI_STATUS_IGNORE
      integer MPI_STATUSES_IGNORE
      
      common/mpi_fortran_bottom/MPI_BOTTOM, MPI_IN_PLACE
      common/mpi_fortran_bottom/MPI_ARGV_NULL, MPI_ARGVS_NULL
      common/mpi_fortran_bottom/MPI_ERRCODES_IGNORE
      common/mpi_fortran_bottom/MPI_STATUS_IGNORE,MPI_STATUSES_IGNORE
      save /mpi_fortran_bottom/
!     
!     NULL "handles" (indices)
!     
      integer MPI_GROUP_NULL, MPI_COMM_NULL, MPI_DATATYPE_NULL
      integer MPI_REQUEST_NULL, MPI_OP_NULL, MPI_ERRHANDLER_NULL
      integer MPI_INFO_NULL, MPI_WIN_NULL
      
      parameter (MPI_GROUP_NULL=0)
      parameter (MPI_COMM_NULL=0)
      parameter (MPI_DATATYPE_NULL=0)
      parameter (MPI_REQUEST_NULL=0)
      parameter (MPI_OP_NULL=0)
      parameter (MPI_ERRHANDLER_NULL=0)
      parameter (MPI_INFO_NULL=0)
      parameter (MPI_WIN_NULL=0)
!     
!     MPI_Init_thread constants
!     
      integer MPI_THREAD_SINGLE, MPI_THREAD_FUNNELED
      integer MPI_THREAD_SERIALIZED, MPI_THREAD_MULTIPLE
      
      parameter (MPI_THREAD_SINGLE=0)
      parameter (MPI_THREAD_FUNNELED=1)
      parameter (MPI_THREAD_SERIALIZED=2)
      parameter (MPI_THREAD_MULTIPLE=3)
!     
!     error classes
!     
      integer MPI_SUCCESS                    
      integer MPI_ERR_BUFFER                
      integer MPI_ERR_COUNT                 
      integer MPI_ERR_TYPE                  
      integer MPI_ERR_TAG                   
      integer MPI_ERR_COMM                  
      integer MPI_ERR_RANK                  
      integer MPI_ERR_REQUEST               
      integer MPI_ERR_ROOT                  
      integer MPI_ERR_GROUP                 
      integer MPI_ERR_OP                    
      integer MPI_ERR_TOPOLOGY              
      integer MPI_ERR_DIMS                  
      integer MPI_ERR_ARG                   
      integer MPI_ERR_UNKNOWN               
      integer MPI_ERR_TRUNCATE              
      integer MPI_ERR_OTHER                 
      integer MPI_ERR_INTERN                
      integer MPI_ERR_IN_STATUS             
      integer MPI_ERR_PENDING               
      integer MPI_ERR_ACCESS                
      integer MPI_ERR_AMODE                 
      integer MPI_ERR_ASSERT                
      integer MPI_ERR_BAD_FILE              
      integer MPI_ERR_BASE                  
      integer MPI_ERR_CONVERSION            
      integer MPI_ERR_DISP                  
      integer MPI_ERR_DUP_DATAREP           
      integer MPI_ERR_FILE_EXISTS           
      integer MPI_ERR_FILE_IN_USE           
      integer MPI_ERR_FILE                  
      integer MPI_ERR_INFO_KEY              
      integer MPI_ERR_INFO_NOKEY            
      integer MPI_ERR_INFO_VALUE            
      integer MPI_ERR_INFO                  
      integer MPI_ERR_IO                    
      integer MPI_ERR_KEYVAL                
      integer MPI_ERR_LOCKTYPE              
      integer MPI_ERR_NAME                  
      integer MPI_ERR_NO_MEM                
      integer MPI_ERR_NOT_SAME              
      integer MPI_ERR_NO_SPACE              
      integer MPI_ERR_NO_SUCH_FILE          
      integer MPI_ERR_PORT                  
      integer MPI_ERR_QUOTA                 
      integer MPI_ERR_READ_ONLY             
      integer MPI_ERR_RMA_CONFLICT          
      integer MPI_ERR_RMA_SYNC              
      integer MPI_ERR_SERVICE               
      integer MPI_ERR_SIZE                  
      integer MPI_ERR_SPAWN                 
      integer MPI_ERR_UNSUPPORTED_DATAREP   
      integer MPI_ERR_UNSUPPORTED_OPERATION 
      integer MPI_ERR_WIN                   
       
      integer MPI_ERR_SYSRESOURCE          
      integer MPI_ERR_LASTCODE              
       
      parameter( MPI_SUCCESS                  = 0)
      parameter( MPI_ERR_BUFFER               = 1)
      parameter( MPI_ERR_COUNT                = 2)
      parameter( MPI_ERR_TYPE                 = 3)
      parameter( MPI_ERR_TAG                  = 4)
      parameter( MPI_ERR_COMM                 = 5)
      parameter( MPI_ERR_RANK                 = 6)
      parameter( MPI_ERR_ROOT                 = 7)
      parameter( MPI_ERR_GROUP                = 8)
      parameter( MPI_ERR_OP                   = 9)
      parameter( MPI_ERR_TOPOLOGY             = 10)
      parameter( MPI_ERR_DIMS                 = 11)
      parameter( MPI_ERR_ARG                  = 12)
      parameter( MPI_ERR_UNKNOWN              = 13)
      parameter( MPI_ERR_TRUNCATE             = 14)
      parameter( MPI_ERR_OTHER                = 15)
      parameter( MPI_ERR_INTERN               = 16)
      parameter( MPI_ERR_IN_STATUS            = 17)
      parameter( MPI_ERR_PENDING              = 18)
      parameter( MPI_ERR_REQUEST              = 19)
      parameter( MPI_ERR_ACCESS               = 20)
      parameter( MPI_ERR_AMODE                = 21)
      parameter( MPI_ERR_BAD_FILE             = 22)
      parameter( MPI_ERR_CONVERSION           = 23)
      parameter( MPI_ERR_DUP_DATAREP          = 24)
      parameter( MPI_ERR_FILE_EXISTS          = 25)
      parameter( MPI_ERR_FILE_IN_USE          = 26)
      parameter( MPI_ERR_FILE                 = 27)
      parameter( MPI_ERR_INFO                 = 28)
      parameter( MPI_ERR_INFO_KEY             = 29)
      parameter( MPI_ERR_INFO_NOKEY           = 30)
      parameter( MPI_ERR_INFO_VALUE           = 31)
      parameter( MPI_ERR_IO                   = 32)
      parameter( MPI_ERR_NAME                 = 33)
      parameter( MPI_ERR_NO_MEM               = 34)
      parameter( MPI_ERR_NOT_SAME             = 35)
      parameter( MPI_ERR_NO_SPACE             = 36)
      parameter( MPI_ERR_NO_SUCH_FILE         = 37)
      parameter( MPI_ERR_PORT                 = 38)
      parameter( MPI_ERR_QUOTA                = 39)
      parameter( MPI_ERR_READ_ONLY            = 40)
      parameter( MPI_ERR_SERVICE              = 41)
      parameter( MPI_ERR_SPAWN                = 42)
      parameter( MPI_ERR_UNSUPPORTED_DATAREP  = 43)
      parameter( MPI_ERR_UNSUPPORTED_OPERATION= 44)
      parameter( MPI_ERR_WIN                  = 45)
      parameter( MPI_ERR_BASE                 = 46)
      parameter( MPI_ERR_LOCKTYPE             = 47)
      parameter( MPI_ERR_KEYVAL               = 48)
      parameter( MPI_ERR_RMA_CONFLICT         = 49)
      parameter( MPI_ERR_RMA_SYNC             = 50)
      parameter( MPI_ERR_SIZE                 = 51)
      parameter( MPI_ERR_DISP                 = 52)
      parameter( MPI_ERR_ASSERT               = 53)
      parameter( MPI_ERR_LASTCODE             = 54)
      
!     
!     comparison results
!     
      integer MPI_IDENT, MPI_CONGRUENT, MPI_SIMILAR, MPI_UNEQUAL
      
      parameter (MPI_IDENT=0)
      parameter (MPI_CONGRUENT=1)
      parameter (MPI_SIMILAR=2)
      parameter (MPI_UNEQUAL=3)
!     
!     datatype combiners
!     
      integer MPI_COMBINER_NAMED
      integer MPI_COMBINER_DUP
      integer MPI_COMBINER_CONTIGUOUS
      integer MPI_COMBINER_VECTOR
      integer MPI_COMBINER_HVECTOR_INTEGER
      integer MPI_COMBINER_HVECTOR
      integer MPI_COMBINER_INDEXED
      integer MPI_COMBINER_HINDEXED_INTEGER
      integer MPI_COMBINER_HINDEXED
      integer MPI_COMBINER_INDEXED_BLOCK
      integer MPI_COMBINER_STRUCT_INTEGER
      integer MPI_COMBINER_STRUCT
      integer MPI_COMBINER_SUBARRAY
      integer MPI_COMBINER_DARRAY
      integer MPI_COMBINER_F90_REAL
      integer MPI_COMBINER_F90_COMPLEX
      integer MPI_COMBINER_F90_INTEGER
      integer MPI_COMBINER_RESIZED
      
      parameter (MPI_COMBINER_NAMED=18)
      parameter (MPI_COMBINER_DUP=19)
      parameter (MPI_COMBINER_CONTIGUOUS=20)
      parameter (MPI_COMBINER_VECTOR=21)
      parameter (MPI_COMBINER_HVECTOR_INTEGER=22)
      parameter (MPI_COMBINER_HVECTOR=23)
      parameter (MPI_COMBINER_INDEXED=24)
      parameter (MPI_COMBINER_HINDEXED_INTEGER=25)
      parameter (MPI_COMBINER_HINDEXED=26)
      parameter (MPI_COMBINER_INDEXED_BLOCK=27)
      parameter (MPI_COMBINER_STRUCT_INTEGER=28)
      parameter (MPI_COMBINER_STRUCT=29)
      parameter (MPI_COMBINER_SUBARRAY=30)
      parameter (MPI_COMBINER_DARRAY=31)
      parameter (MPI_COMBINER_F90_REAL=32)
      parameter (MPI_COMBINER_F90_COMPLEX=33)
      parameter (MPI_COMBINER_F90_INTEGER=34)
      parameter (MPI_COMBINER_RESIZED=35)
!     
!     lookup table indices
!     
      integer MPI_COMM_WORLD, MPI_COMM_SELF
      integer MPI_GROUP_EMPTY
      integer MPI_ERRORS_ARE_FATAL, MPI_ERRORS_RETURN
      
      parameter (MPI_COMM_WORLD=1)
      parameter (MPI_COMM_SELF=2)
      parameter (MPI_GROUP_EMPTY=1)
      parameter (MPI_ERRORS_ARE_FATAL=1)
      parameter (MPI_ERRORS_RETURN=2)
      
      integer MPI_BYTE, MPI_PACKED, MPI_UB, MPI_LB
      integer MPI_CHARACTER, MPI_LOGICAL
      integer MPI_INTEGER, MPI_INTEGER1, MPI_INTEGER2, MPI_INTEGER4
      integer MPI_INTEGER8
      integer MPI_REAL, MPI_REAL4, MPI_REAL8, MPI_REAL16
      integer MPI_DOUBLE_PRECISION
      integer MPI_COMPLEX
      integer MPI_DOUBLE_COMPLEX
      integer MPI_2REAL, MPI_2DOUBLE_PRECISION, MPI_2INTEGER
      integer MPI_2COMPLEX, MPI_2DOUBLE_COMPLEX
      
      parameter (MPI_INTEGER=16)
      parameter (MPI_REAL=17)
      parameter (MPI_DOUBLE_PRECISION=18)
      parameter (MPI_COMPLEX=19)
      parameter (MPI_DOUBLE_COMPLEX=20)
      parameter (MPI_LOGICAL=21)
      parameter (MPI_CHARACTER=22)
      parameter (MPI_INTEGER1=23)
      parameter (MPI_INTEGER2=24)
      parameter (MPI_INTEGER4=25) 
      parameter (MPI_INTEGER8=26)  
      parameter (MPI_REAL4=27)
      parameter (MPI_REAL8=28)
      parameter (MPI_REAL16=29)
      parameter (MPI_BYTE=30)
      parameter (MPI_PACKED=31)
      parameter (MPI_UB=32)
      parameter (MPI_LB=33)
      parameter (MPI_2REAL=40)
      parameter (MPI_2DOUBLE_PRECISION=41)
      parameter (MPI_2INTEGER=42)
      
      integer MPI_MAX, MPI_MIN, MPI_SUM, MPI_PROD, MPI_LAND
      integer MPI_BAND, MPI_LOR, MPI_BOR, MPI_LXOR, MPI_BXOR
      integer MPI_MAXLOC, MPI_MINLOC, MPI_REPLACE
      
      parameter (MPI_MAX=1)
      parameter (MPI_MIN=2)
      parameter (MPI_SUM=3)
      parameter (MPI_PROD=4)
      parameter (MPI_LAND=5)
      parameter (MPI_BAND=6)
      parameter (MPI_LOR=7)
      parameter (MPI_BOR=8)
      parameter (MPI_LXOR=9)
      parameter (MPI_BXOR=10)
      parameter (MPI_MAXLOC=11)
      parameter (MPI_MINLOC=12)
      parameter (MPI_REPLACE=13)

!
!     Kind parameters
!     
      integer MPI_OFFSET_KIND, MPI_ADDRESS_KIND, MPI_INTEGER_KIND
      integer MPI_COUNT_KIND
      parameter (MPI_INTEGER_KIND=4)
      parameter (MPI_ADDRESS_KIND=4)
      parameter (MPI_OFFSET_KIND=8)
      parameter (MPI_COUNT_KIND=8)
!     
!     Miscellaneous constants
!     
      integer MPI_STATUS_SIZE
      parameter (MPI_STATUS_SIZE=11)
