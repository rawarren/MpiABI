
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Status_set_elements
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_STATUS_SET_ELEMENTS() __attribute__ ((weak, alias("iscf_status_set_elements")));
void mpi_status_set_elements() __attribute__ ((weak, alias("iscf_status_set_elements")));
void mpi_status_set_elements_() __attribute__ ((weak, alias("iscf_status_set_elements")));
void mpi_status_set_elements__() __attribute__ ((weak, alias("iscf_status_set_elements")));
#endif

void iscf_status_set_elements(int *status, int *datatype, int *count, int *ierr)
{
    *ierr = MPI_Status_set_elements ((MPI_Status *)status, *datatype, *count);
}
