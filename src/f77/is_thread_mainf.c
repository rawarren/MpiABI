
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Is_thread_main
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_IS_THREAD_MAIN() __attribute__ ((weak, alias("iscf_is_thread_main")));
void mpi_is_thread_main() __attribute__ ((weak, alias("iscf_is_thread_main")));
void mpi_is_thread_main_() __attribute__ ((weak, alias("iscf_is_thread_main")));
void mpi_is_thread_main__() __attribute__ ((weak, alias("iscf_is_thread_main")));
#endif

void iscf_is_thread_main(int *flag, int *ierr)
{
    *ierr = MPI_Is_thread_main (flag);
}
