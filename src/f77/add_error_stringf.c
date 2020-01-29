
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Add_error_string
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ADD_ERROR_STRING() __attribute__ ((weak, alias("iscf_add_error_string")));
void mpi_add_error_string() __attribute__ ((weak, alias("iscf_add_error_string")));
void mpi_add_error_string_() __attribute__ ((weak, alias("iscf_add_error_string")));
void mpi_add_error_string__() __attribute__ ((weak, alias("iscf_add_error_string")));
#endif

void iscf_add_error_string(int *errorcode,  char *string, int *ierr)
{
    *ierr = MPI_Add_error_string (*errorcode, string);
}
