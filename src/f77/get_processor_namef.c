
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get_processor_name
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GET_PROCESSOR_NAME() __attribute__ ((weak, alias("iscf_get_processor_name")));
void mpi_get_processor_name() __attribute__ ((weak, alias("iscf_get_processor_name")));
void mpi_get_processor_name_() __attribute__ ((weak, alias("iscf_get_processor_name")));
void mpi_get_processor_name__() __attribute__ ((weak, alias("iscf_get_processor_name")));
#endif

void iscf_get_processor_name(char *name, int *resultlen, int *ierr)
{
    *ierr = MPI_Get_processor_name (name, resultlen);
}
