
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Unpack
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_UNPACK() __attribute__ ((weak, alias("iscf_unpack")));
void mpi_unpack() __attribute__ ((weak, alias("iscf_unpack")));
void mpi_unpack_() __attribute__ ((weak, alias("iscf_unpack")));
void mpi_unpack__() __attribute__ ((weak, alias("iscf_unpack")));
#endif

void iscf_unpack(void *inbuf, int *insize, int *position, void *outbuf, int *outcount, int *datatype, int *comm, int *ierr)
{
    *ierr = MPI_Unpack (inbuf, *insize, position, outbuf, *outcount, *datatype, *comm);
}
