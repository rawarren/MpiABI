
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Add_error_code
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ADD_ERROR_CODE() __attribute__ ((weak, alias("iscf_add_error_code")));
void mpi_add_error_code() __attribute__ ((weak, alias("iscf_add_error_code")));
void mpi_add_error_code_() __attribute__ ((weak, alias("iscf_add_error_code")));
void mpi_add_error_code__() __attribute__ ((weak, alias("iscf_add_error_code")));
#endif

void iscf_add_error_code(int *errorclass, int *errorcode, int *ierr)
{
    *ierr = MPI_Add_error_code (*errorclass, errorcode);
}
