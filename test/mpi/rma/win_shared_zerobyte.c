/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *
 *  (C) 2014 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <mpi.h>
#include "mpitest.h"

const int verbose = 0;

int main(int argc, char **argv)
{
    int i, rank, nproc;
    int shm_rank, shm_nproc;
    MPI_Aint size;
    int errors = 0, all_errors = 0;
    int **bases = NULL, *abs_base, *my_base;
    int disp_unit;
    MPI_Win shm_win;
    MPI_Comm shm_comm;
    int ELEM_PER_PROC = 0;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
#if MPI_VERSION > 2

    MPI_Comm_split_type(MPI_COMM_WORLD, MPI_COMM_TYPE_SHARED, rank, MPI_INFO_NULL, &shm_comm);

    MPI_Comm_rank(shm_comm, &shm_rank);
    MPI_Comm_size(shm_comm, &shm_nproc);

    /* Platform does not support shared memory, just return. */
    if (shm_nproc < 2) {
        goto exit;
    }

    bases = calloc(shm_nproc, sizeof(int *));

    if (shm_rank == 0 || shm_rank == shm_nproc - 1) {
        ELEM_PER_PROC = 16;
    }

    /* Allocate ELEM_PER_PROC integers for each process */
    MPI_Win_allocate_shared(sizeof(int) * ELEM_PER_PROC, sizeof(int), MPI_INFO_NULL,
                            shm_comm, &my_base, &shm_win);

    /* Locate absolute base */
    MPI_Win_shared_query(shm_win, MPI_PROC_NULL, &size, &disp_unit, &abs_base);

    if (verbose)
        printf("%d -- allocate shared: my_base = %p, absolute base = %p\n", shm_rank, my_base,
               abs_base);

    for (i = 0; i < shm_nproc; i++) {
        MPI_Win_shared_query(shm_win, i, &size, &disp_unit, &bases[i]);
        if (verbose)
            printf("%d --    shared query: base[%d]=%p, size %ld, unit %d\n",
                   shm_rank, i, bases[i], size, disp_unit);
    }

    MPI_Win_lock_all(MPI_MODE_NOCHECK, shm_win);

    /* Reset data */
    for (i = 0; i < ELEM_PER_PROC; i++) {
        my_base[i] = 0;
    }

    MPI_Win_sync(shm_win);
    MPI_Barrier(shm_comm);
    MPI_Win_sync(shm_win);

    /* Read and verify everyone's data */
    if (shm_rank == 0) {
        bases[0][0] = 1;
    }

    MPI_Win_sync(shm_win);
    MPI_Barrier(shm_comm);
    MPI_Win_sync(shm_win);

    if (bases[0][0] != 1) {
        errors++;
        printf("%d -- Got %d at rank %d index %d, expected %d\n", shm_rank, bases[0][0], 0, 0, 1);
    }

    if (bases[shm_nproc - 1][0] != 0) {
        errors++;
        printf("%d -- Got %d at rank %d index %d, expected %d\n", shm_rank,
               bases[shm_nproc - 1][0], shm_nproc - 1, 0, 0);
    }

    MPI_Win_unlock_all(shm_win);
    MPI_Win_free(&shm_win);

    MPI_Reduce(&errors, &all_errors, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  exit:

    if (rank == 0 && all_errors == 0)
        printf(" No Errors\n");

    MPI_Comm_free(&shm_comm);
#endif
    MPI_Finalize();

    if (bases)
        free(bases);

    return 0;
}
