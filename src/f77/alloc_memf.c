
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Alloc_mem
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ALLOC_MEM() __attribute__ ((weak, alias("iscf_alloc_mem")));
void mpi_alloc_mem() __attribute__ ((weak, alias("iscf_alloc_mem")));
void mpi_alloc_mem_() __attribute__ ((weak, alias("iscf_alloc_mem")));
void mpi_alloc_mem__() __attribute__ ((weak, alias("iscf_alloc_mem")));
#endif

void iscf_alloc_mem(MPI_Aint *size, int *info,  void *baseptr, int *ierr)
{
    *ierr = MPI_Alloc_mem (*size, *info, baseptr);
}
