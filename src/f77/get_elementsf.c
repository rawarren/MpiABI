
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get_elements
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GET_ELEMENTS() __attribute__ ((weak, alias("iscf_get_elements")));
void mpi_get_elements() __attribute__ ((weak, alias("iscf_get_elements")));
void mpi_get_elements_() __attribute__ ((weak, alias("iscf_get_elements")));
void mpi_get_elements__() __attribute__ ((weak, alias("iscf_get_elements")));
#endif

void iscf_get_elements(int *status, int *datatype, int *count, int *ierr)
{
    *ierr = MPI_Get_elements ((MPI_Status *)status, *datatype, count);
}
