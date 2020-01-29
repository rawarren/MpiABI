
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Address
 */

#include <_mpi.h>

/*
 * CAUTION!!
 * The following assumes that pointers are little endian!?
 */

#ifdef __LP64__
unsigned int
__fort_addr( unsigned long *faddr, int write_data )
{
  static unsigned long cacheline[16];
  static int next = -1;

  if (next < 0) {
    if (!write_data) {	/* Cache lookup without ever
			   having defined an entry! */
      return -1;
    }
    cacheline[1] = ((unsigned long)
		    *faddr & 0xfffffffff0000000);
    next = 2;
    return (int) (((unsigned long)
		   *faddr & 0x000000000fffffff) | 0x10000000);
  } else {
    int i;
    unsigned long tmp;
    unsigned long mask;

    if (!write_data) {
      /*
       * cache lookup::
       *
       * The index is contained in bits 28-31.
       * The cache simply contains the "tag" which
       * consists of bits 28-63 of the original.
       */

      tmp = ((unsigned long) *faddr & 0x00000000ffffffff);
      i = tmp >> 28;
      if (i == 0) {
	return 0; /* index 0 is never used! */
      }
      tmp = ((unsigned long) *faddr & 0x000000000fffffff);
      *faddr = cacheline[i] | tmp;
      return 0;
    } else {
      mask = *faddr & 0xfffffffff0000000;
      for (i=1; i<16; i++) {
	if (i == next)
	  break;
	else if (cacheline[i] == mask)
	  break;
      }
      if (i == next) {
	cacheline[next] = mask;
	next++;
      }
      if (i == 16) {
	puts("Error! Out of (a_cache) indices...");
      }
      else {
	mask = i << 28;
	tmp  = *faddr & 0x000000000fffffff;
	return (unsigned int) (mask | tmp);
      }
    }
  }
  return -1;
}
#endif


#ifdef __GNUC__
void MPI_ADDRESS() __attribute__ ((weak, alias("iscf_address")));
void mpi_address() __attribute__ ((weak, alias("iscf_address")));
void mpi_address_() __attribute__ ((weak, alias("iscf_address")));
void mpi_address__() __attribute__ ((weak, alias("iscf_address")));
#endif

void iscf_address(void *location, int *addr, int *ierr)
{
    MPI_Aint c_addr;
    *ierr = MPI_Address (location, &c_addr);
#ifndef __LP64__
    *addr = (int)c_addr;
#else
    *addr = (int)__fort_addr(&c_addr,1);
#endif
}
