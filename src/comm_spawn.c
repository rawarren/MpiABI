
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_spawn
 */

#include <_mpi.h>

int
MPI_Comm_spawn (char *command, char **argv, int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int *array_of_errcodes)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_spawn")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_spawn",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *intercomm = new_index(active_comms);
  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    api_use_ptrs *local_a2= active_comms->api_declared;
    int (*VendorMPI_Comm_spawn)(char *command,char **argv,int maxprocs,void *,int root,void *,void **, int *array_of_errcodes) = address;
    mpi_return = (*VendorMPI_Comm_spawn)(command,ARGVNULL(argv),maxprocs,local_a0[info].mpi_const,root,local_a1[comm].mpi_const,&local_a2[*intercomm].mpi_const,ERRIGNORE(array_of_errcodes));
  } else { api_use_ints *local_a0=active_infos->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    api_use_ints *local_a2= active_comms->api_declared;
    int (*VendorMPI_Comm_spawn)(char *command,char **argv,int maxprocs,int,int root,int,int *, int *array_of_errcodes) = address;
    mpi_return = (*VendorMPI_Comm_spawn)(command,ARGVNULL(argv),maxprocs,local_a0[info].mpi_const,root,local_a1[comm].mpi_const,&local_a2[*intercomm].mpi_const,ERRIGNORE(array_of_errcodes));
  }
  return mpi_return;
}
