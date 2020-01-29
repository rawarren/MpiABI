
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get_count
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GET_COUNT() __attribute__ ((weak, alias("iscf_get_count")));
void mpi_get_count() __attribute__ ((weak, alias("iscf_get_count")));
void mpi_get_count_() __attribute__ ((weak, alias("iscf_get_count")));
void mpi_get_count__() __attribute__ ((weak, alias("iscf_get_count")));
#endif

void iscf_get_count(int *status, int *datatype, int *count, int *ierr)
{
    *ierr = MPI_Get_count ((MPI_Status *)status, *datatype, count);
}
