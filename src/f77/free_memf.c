
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Free_mem
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FREE_MEM() __attribute__ ((weak, alias("iscf_free_mem")));
void mpi_free_mem() __attribute__ ((weak, alias("iscf_free_mem")));
void mpi_free_mem_() __attribute__ ((weak, alias("iscf_free_mem")));
void mpi_free_mem__() __attribute__ ((weak, alias("iscf_free_mem")));
#endif

void iscf_free_mem(void *base, int *ierr)
{
    *ierr = MPI_Free_mem (base);
}
