
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Buffer_attach
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_BUFFER_ATTACH() __attribute__ ((weak, alias("iscf_buffer_attach")));
void mpi_buffer_attach() __attribute__ ((weak, alias("iscf_buffer_attach")));
void mpi_buffer_attach_() __attribute__ ((weak, alias("iscf_buffer_attach")));
void mpi_buffer_attach__() __attribute__ ((weak, alias("iscf_buffer_attach")));
#endif

void iscf_buffer_attach(void *buffer, int *size, int *ierr)
{
    *ierr = MPI_Buffer_attach (buffer, *size);
}
