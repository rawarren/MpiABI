
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_ub
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_UB() __attribute__ ((weak, alias("iscf_type_ub")));
void mpi_type_ub() __attribute__ ((weak, alias("iscf_type_ub")));
void mpi_type_ub_() __attribute__ ((weak, alias("iscf_type_ub")));
void mpi_type_ub__() __attribute__ ((weak, alias("iscf_type_ub")));
#endif

void iscf_type_ub(int *mtype, int *ub, int *ierr)
{
   MPI_Aint true_ub;
   *ierr = MPI_Type_ub (*mtype, &true_ub);
   *ub = (int)true_ub & 0x0ffffffff;
}
