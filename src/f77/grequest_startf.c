
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Grequest_start
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GREQUEST_START() __attribute__ ((weak, alias("iscf_grequest_start")));
void mpi_grequest_start() __attribute__ ((weak, alias("iscf_grequest_start")));
void mpi_grequest_start_() __attribute__ ((weak, alias("iscf_grequest_start")));
void mpi_grequest_start__() __attribute__ ((weak, alias("iscf_grequest_start")));
#endif

void iscf_grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, int *request, int *ierr)
{
    *ierr = MPI_Grequest_start (query_fn, free_fn, cancel_fn, extra_state, request);
}
