
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Error_string
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ERROR_STRING() __attribute__ ((weak, alias("iscf_error_string")));
void mpi_error_string() __attribute__ ((weak, alias("iscf_error_string")));
void mpi_error_string_() __attribute__ ((weak, alias("iscf_error_string")));
void mpi_error_string__() __attribute__ ((weak, alias("iscf_error_string")));
#endif

void iscf_error_string(int *errorcode, char *string, int *resultlen, int *ierr)
{
    *ierr = MPI_Error_string (*errorcode, string, resultlen);
}
