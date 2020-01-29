
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Pack
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_PACK() __attribute__ ((weak, alias("iscf_pack")));
void mpi_pack() __attribute__ ((weak, alias("iscf_pack")));
void mpi_pack_() __attribute__ ((weak, alias("iscf_pack")));
void mpi_pack__() __attribute__ ((weak, alias("iscf_pack")));
#endif

void iscf_pack(void *inbuf, int *incount, int *datatype, void *outbuf, int *outsize, int *position, int *comm, int *ierr)
{
  *ierr = MPI_Pack (FBOTTOM(inbuf), *incount, *datatype, FBOTTOM(outbuf), *outsize, position, *comm);
}
