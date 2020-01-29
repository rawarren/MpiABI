
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_envelope
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_GET_ENVELOPE() __attribute__ ((weak, alias("iscf_type_get_envelope")));
void mpi_type_get_envelope() __attribute__ ((weak, alias("iscf_type_get_envelope")));
void mpi_type_get_envelope_() __attribute__ ((weak, alias("iscf_type_get_envelope")));
void mpi_type_get_envelope__() __attribute__ ((weak, alias("iscf_type_get_envelope")));
#endif

void iscf_type_get_envelope(int *type, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner, int *ierr)
{
    *ierr = MPI_Type_get_envelope (*type, num_integers, num_addresses, num_datatypes, combiner);
}
