
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Register_datarep
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_REGISTER_DATAREP() __attribute__ ((weak, alias("iscf_register_datarep")));
void mpi_register_datarep() __attribute__ ((weak, alias("iscf_register_datarep")));
void mpi_register_datarep_() __attribute__ ((weak, alias("iscf_register_datarep")));
void mpi_register_datarep__() __attribute__ ((weak, alias("iscf_register_datarep")));
#endif

void iscf_register_datarep(char *datarep, int *read_conversion_fn, int *write_conversion_fn, int *dtype_file_extent_fn,  void *extra_state, int *ierr)
{
  *ierr = MPI_Register_datarep (datarep, (MPI_Datarep_conversion_function *)read_conversion_fn, 
				(MPI_Datarep_conversion_function *)write_conversion_fn,
				(MPI_Datarep_extent_function *)dtype_file_extent_fn, extra_state);
}
