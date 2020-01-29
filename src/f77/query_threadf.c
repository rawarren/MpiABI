
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Query_thread
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_QUERY_THREAD() __attribute__ ((weak, alias("iscf_query_thread")));
void mpi_query_thread() __attribute__ ((weak, alias("iscf_query_thread")));
void mpi_query_thread_() __attribute__ ((weak, alias("iscf_query_thread")));
void mpi_query_thread__() __attribute__ ((weak, alias("iscf_query_thread")));
#endif

void iscf_query_thread(int *provided, int *ierr)
{
    *ierr = MPI_Query_thread (provided);
}
