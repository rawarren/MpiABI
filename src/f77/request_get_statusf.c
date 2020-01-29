
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Request_get_status
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_REQUEST_GET_STATUS() __attribute__ ((weak, alias("iscf_request_get_status")));
void mpi_request_get_status() __attribute__ ((weak, alias("iscf_request_get_status")));
void mpi_request_get_status_() __attribute__ ((weak, alias("iscf_request_get_status")));
void mpi_request_get_status__() __attribute__ ((weak, alias("iscf_request_get_status")));
#endif

void iscf_request_get_status(int *request, int *flag, int *status, int *ierr)
{
  *ierr = MPI_Request_get_status ((MPI_Request)*request, flag, (MPI_Status *)status);
}
