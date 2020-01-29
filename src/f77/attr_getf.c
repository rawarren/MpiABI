
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Attr_get
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_ATTR_GET() __attribute__ ((weak, alias("iscf_attr_get")));
void mpi_attr_get() __attribute__ ((weak, alias("iscf_attr_get")));
void mpi_attr_get_() __attribute__ ((weak, alias("iscf_attr_get")));
void mpi_attr_get__() __attribute__ ((weak, alias("iscf_attr_get")));
#endif

void iscf_attr_get(int *comm, int *keyval, void *attribute_val, int *flag, int *ierr)
{
    void *attrv_to_spec;
    *ierr = MPI_Attr_get (*comm, *keyval, &attrv_to_spec, flag);
    *(int *)attribute_val = (int)(MPI_Aint)attrv_to_spec;
}
