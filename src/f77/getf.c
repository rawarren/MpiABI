
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Get
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_GET() __attribute__ ((weak, alias("iscf_get")));
void mpi_get() __attribute__ ((weak, alias("iscf_get")));
void mpi_get_() __attribute__ ((weak, alias("iscf_get")));
void mpi_get__() __attribute__ ((weak, alias("iscf_get")));
#endif

void iscf_get(void *origin_addr, int *origin_count, int *origin_datatype, int *target_rank, MPI_Aint *target_disp, int *target_count, int *target_datatype, int *win, int *ierr)
{
  *ierr = MPI_Get (FBOTTOM(origin_addr), *origin_count, *origin_datatype, *target_rank, *target_disp, *target_count, *target_datatype, *win);
}
