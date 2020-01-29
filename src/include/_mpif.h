! -*- fortran -*-
!
!     The general format of the fortran include files is taken from
!     the OpenMPI distribution.  The Interactive SuperComputing
!     version differs in the parameter declarations to match the
!     'C' definitions and thus avoids translating between these
!     common languages.
!
!     Notice:         - This file is based in part on 
!                       contributions from the following group
!
!     - OpenMPI ( version 1.2.3 )
!     Copyright (c) 2004-2006 The Trustees of Indiana University and
!               Indiana University Research and Technology Corporation.
!     Copyright (c) 2004-2005 The University of Tennessee and The University
!               Tennessee Research Foundation.
!     Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
!               University of Stuttgart.
!     Copyright (c) 2004-2005 The Regents of the University of California.
!     Copyright (c) 2006      Cisco Systems, Inc.

      include 'mpif-common.h'

!
!     These "external" statements are specific to the MPI F77 interface
!     (and are toxic to the MPI F90 interface), and are therefore in the
!     MPI F77-specific header file (i.e., this one).
!     
      external MPI_NULL_COPY_FN, MPI_NULL_DELETE_FN
      external MPI_COMM_NULL_COPY_FN, MPI_COMM_NULL_DELETE_FN
      external MPI_TYPE_NULL_COPY_FN, MPI_TYPE_NULL_DELETE_FN
      external MPI_DUP_FN, MPI_COMM_DUP_FN, MPI_TYPE_DUP_FN
      external MPI_WIN_NULL_COPY_FN
      external MPI_WIN_NULL_DELETE_FN
      external MPI_WIN_DUP_FN
      
!     
!     double precision functions
!     
      external MPI_WTIME, MPI_WTICK 
      double precision MPI_WTIME, MPI_WTICK 
      
