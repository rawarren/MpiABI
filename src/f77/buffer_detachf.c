
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Buffer_detach
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_BUFFER_DETACH() __attribute__ ((weak, alias("iscf_buffer_detach")));
void mpi_buffer_detach() __attribute__ ((weak, alias("iscf_buffer_detach")));
void mpi_buffer_detach_() __attribute__ ((weak, alias("iscf_buffer_detach")));
void mpi_buffer_detach__() __attribute__ ((weak, alias("iscf_buffer_detach")));
#endif

void iscf_buffer_detach(void *buffer, int *size, int *ierr)
{
    *ierr = MPI_Buffer_detach (buffer, size);
}
