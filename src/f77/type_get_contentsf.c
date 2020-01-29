
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_get_contents
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_GET_CONTENTS() __attribute__ ((weak, alias("iscf_type_get_contents")));
void mpi_type_get_contents() __attribute__ ((weak, alias("iscf_type_get_contents")));
void mpi_type_get_contents_() __attribute__ ((weak, alias("iscf_type_get_contents")));
void mpi_type_get_contents__() __attribute__ ((weak, alias("iscf_type_get_contents")));
#endif

void iscf_type_get_contents(int *mtype, int *max_integers, int *max_addresses, int *max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], int array_of_datatypes[], int *ierr)
{
    *ierr = MPI_Type_get_contents (*mtype, *max_integers, *max_addresses, *max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes);
}
