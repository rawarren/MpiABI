#include <_mpi.h>

#ifdef __GNUC__
#undef MPI_NULL_DELETE_FN
void MPI_NULL_DELETE_FN() __attribute__ ((weak, alias("iscf_null_delete_fn")));
void mpi_null_delete_fn() __attribute__ ((weak, alias("iscf_null_delete_fn")));
void mpi_null_delete_fn_() __attribute__ ((weak, alias("iscf_null_delete_fn")));
void mpi_null_delete_fn__() __attribute__ ((weak, alias("iscf_null_delete_fn")));
#endif

void iscf_null_delete_fn (int *comm, int *keyval, void *attr_in, void *extra, int *ierr)
{
}

#ifdef __GNUC__
#undef MPI_COMM_NULL_DELETE_FN
void MPI_COMM_NULL_DELETE_FN() __attribute__ ((weak, alias("iscf_comm_null_delete_fn")));
void mpi_comm_null_delete_fn() __attribute__ ((weak, alias("iscf_comm_null_delete_fn")));
void mpi_comm_null_delete_fn_() __attribute__ ((weak, alias("iscf_comm_null_delete_fn")));
void mpi_comm_null_delete_fn__() __attribute__ ((weak, alias("iscf_comm_null_delete_fn")));
#endif

void iscf_comm_null_delete_fn (int *comm, int *keyval, void *attr_in, void *extra, int *ierr)
{
}

#ifdef __GNUC__
#undef MPI_WIN_NULL_DELETE_FN
void MPI_WIN_NULL_DELETE_FN() __attribute__ ((weak, alias("iscf_win_null_delete_fn")));
void mpi_win_null_delete_fn() __attribute__ ((weak, alias("iscf_win_null_delete_fn")));
void mpi_win_null_delete_fn_() __attribute__ ((weak, alias("iscf_win_null_delete_fn")));
void mpi_win_null_delete_fn__() __attribute__ ((weak, alias("iscf_win_null_delete_fn")));
#endif
void iscf_win_null_delete_fn (int *win, int *keyval, void *attr_in, void *extra, int *ierr)
{
}

#ifdef __GNUC__
#undef MPI_TYPE_NULL_DELETE_FN
void MPI_TYPE_NULL_DELETE_FN() __attribute__ ((weak, alias("iscf_type_null_delete_fn")));
void mpi_type_null_delete_fn() __attribute__ ((weak, alias("iscf_type_null_delete_fn")));
void mpi_type_null_delete_fn_() __attribute__ ((weak, alias("iscf_type_null_delete_fn")));
void mpi_type_null_delete_fn__() __attribute__ ((weak, alias("iscf_type_null_delete_fn")));
#endif
void iscf_type_null_delete_fn (int *dtype, int *keyval, void *attr_in, void *extra, int *ierr)
{
}

/* NULL DELETE FUNCTIONS */
#ifdef __GNUC__
#undef MPI_NULL_COPY_FN
void MPI_NULL_COPY_FN() __attribute__ ((weak, alias("iscf_null_copy_fn")));
void mpi_null_copy_fn() __attribute__ ((weak, alias("iscf_null_copy_fn")));
void mpi_null_copy_fn_() __attribute__ ((weak, alias("iscf_null_copy_fn")));
void mpi_null_copy_fn__() __attribute__ ((weak, alias("iscf_null_copy_fn")));
#endif

void iscf_null_copy_fn (int *comm, int *keyval,  void *extra , void *attr_in, void *attr_out, int *flag, int *ierr)
{
}

#ifdef __GNUC__
#undef MPI_COMM_NULL_COPY_FN
void MPI_COMM_NULL_COPY_FN() __attribute__ ((weak, alias("iscf_comm_null_copy_fn")));
void mpi_comm_null_copy_fn() __attribute__ ((weak, alias("iscf_comm_null_copy_fn")));
void mpi_comm_null_copy_fn_() __attribute__ ((weak, alias("iscf_comm_null_copy_fn")));
void mpi_comm_null_copy_fn__() __attribute__ ((weak, alias("iscf_comm_null_copy_fn")));
#endif

void iscf_comm_null_copy_fn (int *comm, int *keyval,  void *extra , void *attr_in, void *attr_out, int *flag, int *ierr)
{
}

#ifdef __GNUC__
#undef MPI_WIN_NULL_COPY_FN
void MPI_WIN_NULL_COPY_FN() __attribute__ ((weak, alias("iscf_win_null_copy_fn")));
void mpi_win_null_copy_fn() __attribute__ ((weak, alias("iscf_win_null_copy_fn")));
void mpi_win_null_copy_fn_() __attribute__ ((weak, alias("iscf_win_null_copy_fn")));
void mpi_win_null_copy_fn__() __attribute__ ((weak, alias("iscf_win_null_copy_fn")));
#endif

void iscf_win_null_copy_fn (int* window, int *keyval, void* extra, void *attr_in, void *attr_out,int *flag, int *ierr)
{
}

#ifdef __GNUC__
#undef MPI_TYPE_NULL_COPY_FN
void MPI_TYPE_NULL_COPY_FN() __attribute__ ((weak, alias("iscf_type_null_copy_fn")));
void mpi_type_null_copy_fn() __attribute__ ((weak, alias("iscf_type_null_copy_fn")));
void mpi_type_null_copy_fn_() __attribute__ ((weak, alias("iscf_type_null_copy_fn")));
void mpi_type_null_copy_fn__() __attribute__ ((weak, alias("iscf_type_null_copy_fn")));
#endif

void iscf_type_null_copy_fn (int* dtype, int *keyval, void* extra, void *attr_in, void *attr_out,int *flag, int *ierr)
{
}
