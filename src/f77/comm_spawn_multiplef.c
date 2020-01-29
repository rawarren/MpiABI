
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_spawn_multiple
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_SPAWN_MULTIPLE() __attribute__ ((weak, alias("iscf_comm_spawn_multiple")));
void mpi_comm_spawn_multiple() __attribute__ ((weak, alias("iscf_comm_spawn_multiple")));
void mpi_comm_spawn_multiple_() __attribute__ ((weak, alias("iscf_comm_spawn_multiple")));
void mpi_comm_spawn_multiple__() __attribute__ ((weak, alias("iscf_comm_spawn_multiple")));
#endif

void iscf_comm_spawn_multiple(int *count, char **array_of_commands, char ***array_of_argv, int *array_of_maxprocs, int *array_of_info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ierr)
{
    *ierr = MPI_Comm_spawn_multiple (*count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, *root, *comm, intercomm, array_of_errcodes);
}
