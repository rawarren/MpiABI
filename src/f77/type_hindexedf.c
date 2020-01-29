
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Type_hindexed
 */

#include <_mpi.h>
#include <stdlib.h>

#ifdef __GNUC__
void MPI_TYPE_HINDEXED() __attribute__ ((weak, alias("iscf_type_hindexed")));
void mpi_type_hindexed() __attribute__ ((weak, alias("iscf_type_hindexed")));
void mpi_type_hindexed_() __attribute__ ((weak, alias("iscf_type_hindexed")));
void mpi_type_hindexed__() __attribute__ ((weak, alias("iscf_type_hindexed")));
#endif

#ifdef __LP64__
extern unsigned int __fort_addr( unsigned long *, int mode );
#endif


void iscf_type_hindexed(int *count, int array_of_blocklengths[], int array_of_displacements[], int *oldtype, int *newtype, int *ierr)
{
#ifdef __LP64__
    int i;
    MPI_Aint temp[64], *dtemp=0, *dfill;
    
    if (*count > 64) {
      dfill = dtemp = (MPI_Aint *)calloc(*count,sizeof(MPI_Aint));
    } else dfill = temp;
    for(i=0; i<*count; i++) {
      dfill[i] = array_of_displacements[i] & 0x0ffffffff;
      __fort_addr(&dfill[i],0);	/* Modify with cached values */
    }
    *ierr = MPI_Type_hindexed (*count, array_of_blocklengths, dfill, *oldtype, newtype);
    if (dtemp) free(dtemp);
#else
    *ierr = MPI_Type_hindexed (*count, array_of_blocklengths, (MPI_Aint *)array_of_displacements, *oldtype, newtype);
#endif
}
