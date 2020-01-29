
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_spawn
 */

#include <_mpi.h>

#ifdef __GNUC__
void MPI_COMM_SPAWN() __attribute__ ((weak, alias("iscf_comm_spawn")));
void mpi_comm_spawn() __attribute__ ((weak, alias("iscf_comm_spawn")));
void mpi_comm_spawn_() __attribute__ ((weak, alias("iscf_comm_spawn")));
void mpi_comm_spawn__() __attribute__ ((weak, alias("iscf_comm_spawn")));
#endif

void iscf_comm_spawn(char *command, char **argv, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ierr)
{
    *ierr = MPI_Comm_spawn (command, argv, *maxprocs, *info, *root, *comm, intercomm, array_of_errcodes);
}
