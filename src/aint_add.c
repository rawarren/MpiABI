
#include <_mpi.h>

MPI_Aint
MPI_Aint_add(MPI_Aint base, MPI_Aint disp)
{
  static void *address=0;
  MPI_Aint mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Aint_add")) == NULL) {
		/* OpenMPI now implements this function as a C macro. 
		 * How they do they handle FORTRAN?
		 */
#if 1
		return ((MPI_Aint) ((char *) (base) + (disp)));
#else
		printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Aint_add",SYM_MISSING_TRAILER);
		return -1;
#endif
    }
  }
  MPI_Aint (*VendorMPI_Aint_add)(MPI_Aint,MPI_Aint) = address;
  mpi_return = (*VendorMPI_Aint_add)(base,disp);
  return mpi_return;
}

MPI_Aint
MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2)
{
  static void *address=0;
  MPI_Aint mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Aint_diff")) == NULL) {
		/* OpenMPI now implements this function as a C macro. 
		 * How they do they handle FORTRAN?
		 */
#if 1
		return ((MPI_Aint) ((char *) (addr1) - (char *) (addr2)));
#else
		printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Aint_diff",SYM_MISSING_TRAILER);
		return -1;
#endif
    }
  }
  MPI_Aint (*VendorMPI_Aint_diff)(MPI_Aint,MPI_Aint) = address;
  mpi_return = (*VendorMPI_Aint_diff)(addr1,addr2);
  return mpi_return;
}
