
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Pack_external
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_PACK_EXTERNAL() __attribute__ ((weak, alias("iscf_pack_external")));
void mpi_pack_external() __attribute__ ((weak, alias("iscf_pack_external")));
void mpi_pack_external_() __attribute__ ((weak, alias("iscf_pack_external")));
void mpi_pack_external__() __attribute__ ((weak, alias("iscf_pack_external")));
#endif

void iscf_pack_external(char *v1 FORT_MIXED_LEN(d1), void *inbuf, int *incount, int *datatype, void *outbuf, int *outsize, int *position, int *ierr FORT_END_LEN(d1))
{
  char *datarep = NULL;
  {
    int  li;
    char *p = v1 + d1 - 1;

    while (*p == ' ' && p > v1) p--;
    p++;
    datarep = (char *)malloc( p-v1 + 1 );
    for (li=0; li<(p-v1); li++) { 
      datarep[li] = v1[li]; 
    }
    datarep[li] = 0; 
  }

  *ierr = MPI_Pack_external (datarep, FBOTTOM(inbuf), *incount, *datatype, FBOTTOM(outbuf), *outsize, (MPI_Aint *)(position));
  if (datarep != NULL) free(datarep);
  
}
