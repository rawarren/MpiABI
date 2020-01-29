
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Accumulate
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ACCUMULATE() __attribute__ ((weak, alias("iscf_accumulate")));
void mpi_accumulate() __attribute__ ((weak, alias("iscf_accumulate")));
void mpi_accumulate_() __attribute__ ((weak, alias("iscf_accumulate")));
void mpi_accumulate__() __attribute__ ((weak, alias("iscf_accumulate")));
#endif

void iscf_accumulate(void *origin_addr, int *origin_count, int *origin_datatype, int *target_rank, MPI_Aint *target_disp, int *target_count, int *target_datatype, int *op, int *win, int *ierr)
{
    *ierr = MPI_Accumulate (origin_addr, *origin_count, *origin_datatype, *target_rank, *target_disp, *target_count, *target_datatype, *op, *win);
}
