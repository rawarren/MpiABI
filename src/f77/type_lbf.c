
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_lb
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_TYPE_LB() __attribute__ ((weak, alias("iscf_type_lb")));
void mpi_type_lb() __attribute__ ((weak, alias("iscf_type_lb")));
void mpi_type_lb_() __attribute__ ((weak, alias("iscf_type_lb")));
void mpi_type_lb__() __attribute__ ((weak, alias("iscf_type_lb")));
#endif

void iscf_type_lb(int *type, int *lb, int *ierr)
{
    MPI_Aint true_lb;
    *ierr = MPI_Type_lb (*type, &true_lb);
    *lb = (int)true_lb & 0x0ffffffff;
}
