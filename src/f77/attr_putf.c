
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Attr_put
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ATTR_PUT() __attribute__ ((weak, alias("iscf_attr_put")));
void mpi_attr_put() __attribute__ ((weak, alias("iscf_attr_put")));
void mpi_attr_put_() __attribute__ ((weak, alias("iscf_attr_put")));
void mpi_attr_put__() __attribute__ ((weak, alias("iscf_attr_put")));
#endif

void iscf_attr_put(int *comm, int *keyval,  void *attribute_val, int *ierr)
{
    *ierr = MPI_Attr_put (*comm, *keyval, attribute_val);
}
