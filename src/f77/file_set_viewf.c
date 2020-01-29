
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_File_set_view
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_FILE_SET_VIEW() __attribute__ ((weak, alias("iscf_file_set_view")));
void mpi_file_set_view() __attribute__ ((weak, alias("iscf_file_set_view")));
void mpi_file_set_view_() __attribute__ ((weak, alias("iscf_file_set_view")));
void mpi_file_set_view__() __attribute__ ((weak, alias("iscf_file_set_view")));
#endif

void iscf_file_set_view(int *fh, int *disp, int *etype, int *filetype, char *datarep, int *info, int *ierr)
{
    *ierr = MPI_File_set_view (*fh, *disp, *etype, *filetype, datarep, *info);
}
