
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Put
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_PUT() __attribute__ ((weak, alias("iscf_put")));
void mpi_put() __attribute__ ((weak, alias("iscf_put")));
void mpi_put_() __attribute__ ((weak, alias("iscf_put")));
void mpi_put__() __attribute__ ((weak, alias("iscf_put")));
#endif

void iscf_put(void *origin_addr, int *origin_count, int *origin_datatype, int *target_rank, MPI_Aint *target_disp, int *target_count, int *target_datatype, int *win, int *ierr)
{
    *ierr = MPI_Put (origin_addr, *origin_count, *origin_datatype, *target_rank, *target_disp, *target_count, *target_datatype, *win);
}
