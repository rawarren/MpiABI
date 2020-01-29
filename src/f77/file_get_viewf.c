
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_get_view
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_GET_VIEW() __attribute__ ((weak, alias("iscf_file_get_view")));
void mpi_file_get_view() __attribute__ ((weak, alias("iscf_file_get_view")));
void mpi_file_get_view_() __attribute__ ((weak, alias("iscf_file_get_view")));
void mpi_file_get_view__() __attribute__ ((weak, alias("iscf_file_get_view")));
#endif

void iscf_file_get_view(int *fh, int *disp, int *etype, int *filetype,  char *datarep, int *ierr)
{
    MPI_Offset offset = *disp;
    *ierr = MPI_File_get_view (*fh, &offset, etype, filetype, datarep);
    *disp = offset & ISC_INT32MASK;
}
