#include <_mpi.h>
#ifdef __GNUC__
#undef MPI_DUP_FN
void MPI_DUP_FN() __attribute__ ((weak, alias("iscf_dup_fn")));
void mpi_dup_fn() __attribute__ ((weak, alias("iscf_dup_fn")));
void mpi_dup_fn_() __attribute__ ((weak, alias("iscf_dup_fn")));
void mpi_dup_fn__() __attribute__ ((weak, alias("iscf_dup_fn")));
#endif

extern int Isc_dup_fn (int oldcomm, int keyval, void *extra, void *attr_in, void *attr_out, int *flag );

void iscf_dup_fn (int *comm, int *keyval,  void *extra , void *attr_in, void *attr_out, int *flag, int *ierr)
{
  *ierr = Isc_dup_fn(*comm,*keyval, extra, attr_in, attr_out, flag);
}

#ifdef __GNUC__
void MPI_COMM_DUP_FN() __attribute__ ((weak, alias("iscf_comm_dup_fn")));
void mpi_comm_dup_fn() __attribute__ ((weak, alias("iscf_comm_dup_fn")));
void mpi_comm_dup_fn_() __attribute__ ((weak, alias("iscf_comm_dup_fn")));
void mpi_comm_dup_fn__() __attribute__ ((weak, alias("iscf_comm_dup_fn")));
#endif

void iscf_comm_dup_fn (int *comm, int *keyval,  void *extra , void *attr_in, void *attr_out, int *flag, int *ierr)
{
  *ierr = Isc_dup_fn(*comm,*keyval, extra, attr_in, attr_out, flag);
}

#ifdef __GNUC__
#ifndef MPI_WIN_DUP_FN
void MPI_WIN_DUP_FN() __attribute__ ((weak, alias("iscf_win_dup_fn")));
#endif
void mpi_win_dup_fn() __attribute__ ((weak, alias("iscf_win_dup_fn")));
void mpi_win_dup_fn_() __attribute__ ((weak, alias("iscf_win_dup_fn")));
void mpi_win_dup_fn__() __attribute__ ((weak, alias("iscf_win_dup_fn")));
#endif

void iscf_win_dup_fn (int* window, int *keyval, void* extra, void *attr_in, void *attr_out,int *flag, int *ierr)
{
  *ierr = Isc_dup_fn(*window,*keyval, extra, attr_in, attr_out, flag);  
}

#ifdef __GNUC__
void MPI_TYPE_DUP_FN() __attribute__ ((weak, alias("iscf_type_dup_fn")));
void mpi_type_dup_fn() __attribute__ ((weak, alias("iscf_type_dup_fn")));
void mpi_type_dup_fn_() __attribute__ ((weak, alias("iscf_type_dup_fn")));
void mpi_type_dup_fn__() __attribute__ ((weak, alias("iscf_type_dup_fn")));
#endif

void iscf_type_dup_fn (int* dtype, int *keyval, void* extra, void *attr_in, void *attr_out,int *flag, int *ierr)
{
  *ierr = Isc_dup_fn(*dtype, *keyval, extra, attr_in, attr_out, flag);  
}

