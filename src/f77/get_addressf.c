
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get_address
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GET_ADDRESS() __attribute__ ((weak, alias("iscf_get_address")));
void mpi_get_address() __attribute__ ((weak, alias("iscf_get_address")));
void mpi_get_address_() __attribute__ ((weak, alias("iscf_get_address")));
void mpi_get_address__() __attribute__ ((weak, alias("iscf_get_address")));
#endif

void iscf_get_address(void *location, MPI_Aint *address, int *ierr)
{
    *ierr = MPI_Get_address (location, address);
}
