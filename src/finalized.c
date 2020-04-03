
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Finalized
 */

#include <_mpi.h>

int
MPI_Finalized (int *flag)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Finalized")) == NULL) {
	/* Must be that we were never initialized? */
	*flag = 0;
	return 0;
    }
  }

  if (!MPI_libhandle) {
    /* Weirdness: If we've called finalize we actually
     * close up the library handles and set them to null!
     * As a result, if we're here we assume (possibly incorrectly)
     * that Init had been called successfully and Finalize has also
     * been called... meaning nothing in the vendor library is
     * resolvable again!  
     */
    *flag=1;
    return 0;
  }

  int (*VendorMPI_Finalized) (int *flag) = address;
  mpi_return = (*VendorMPI_Finalized)(flag);
  return mpi_return;
}
