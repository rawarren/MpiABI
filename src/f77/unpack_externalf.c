
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Unpack_external
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_UNPACK_EXTERNAL() __attribute__ ((weak, alias("iscf_unpack_external")));
void mpi_unpack_external() __attribute__ ((weak, alias("iscf_unpack_external")));
void mpi_unpack_external_() __attribute__ ((weak, alias("iscf_unpack_external")));
void mpi_unpack_external__() __attribute__ ((weak, alias("iscf_unpack_external")));
#endif

void iscf_unpack_external(char *datarep, void *inbuf, int *insize, int *position, void *outbuf, int *outcount, int *datatype, int *ierr)
{
  MPI_Aint i_size = (MPI_Aint)(*insize);
  *ierr = MPI_Unpack_external (datarep, inbuf, i_size, (MPI_Aint *)position, outbuf, *outcount, *datatype);
}
