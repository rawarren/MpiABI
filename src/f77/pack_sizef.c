
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Pack_size
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_PACK_SIZE() __attribute__ ((weak, alias("iscf_pack_size")));
void mpi_pack_size() __attribute__ ((weak, alias("iscf_pack_size")));
void mpi_pack_size_() __attribute__ ((weak, alias("iscf_pack_size")));
void mpi_pack_size__() __attribute__ ((weak, alias("iscf_pack_size")));
#endif

void iscf_pack_size(int *incount, int *datatype, int *comm, int *size, int *ierr)
{
    *ierr = MPI_Pack_size (*incount, *datatype, *comm, size);
}
