
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Pack_external_size
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_PACK_EXTERNAL_SIZE() __attribute__ ((weak, alias("iscf_pack_external_size")));
void mpi_pack_external_size() __attribute__ ((weak, alias("iscf_pack_external_size")));
void mpi_pack_external_size_() __attribute__ ((weak, alias("iscf_pack_external_size")));
void mpi_pack_external_size__() __attribute__ ((weak, alias("iscf_pack_external_size")));
#endif

void iscf_pack_external_size(char *datarep, int *incount, int *datatype, int *size, int *ierr)
{
    MPI_Aint true_size;
    *ierr = MPI_Pack_external_size (datarep, *incount, *datatype, &true_size);
    *size = true_size & ISC_INT32MASK;
}
