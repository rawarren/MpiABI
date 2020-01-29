
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Request_free
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_REQUEST_FREE() __attribute__ ((weak, alias("iscf_request_free")));
void mpi_request_free() __attribute__ ((weak, alias("iscf_request_free")));
void mpi_request_free_() __attribute__ ((weak, alias("iscf_request_free")));
void mpi_request_free__() __attribute__ ((weak, alias("iscf_request_free")));
#endif

void iscf_request_free(int *request, int *ierr)
{
    *ierr = MPI_Request_free (request);
}
