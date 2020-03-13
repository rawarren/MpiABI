
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_spawn_multiple
 */

#include <_mpi.h>
#include <stdlib.h>

int
MPI_Comm_spawn_multiple (int count, char **array_of_commands, char ***array_of_argv, int *array_of_maxprocs, MPI_Info *array_of_info, int root, MPI_Comm comm, MPI_Comm *intercomm, int *array_of_errcodes)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_spawn_multiple")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_spawn_multiple",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  *intercomm = new_index(active_comms);

  if (active_infos->use_ptrs) { api_use_ptrs *local_a0=active_infos->api_declared;
    int i;
    void *temp[64],**itemp=0, **ifill;
    if (count > 64)
      ifill = itemp = (void **)calloc(count,sizeof(void *));
    else ifill = temp;

    for(i=0; i<count; i++) 
      ifill[i] = local_a0[ array_of_info[i] ].mpi_const;

    if (active_comms->use_ptrs) {
      api_use_ptrs *local_a1= active_comms->api_declared;
      api_use_ptrs *local_a2= active_comms->api_declared;
      int (*VendorMPI_Comm_spawn_multiple)(int count,char **array_of_commands,char ***array_of_argv,int *array_of_maxprocs,void **,int root , void *,void **, int *array_of_errcodes) = address;
      mpi_return = (*VendorMPI_Comm_spawn_multiple)(count,array_of_commands,array_of_argv,array_of_maxprocs,ifill,root,local_a1[comm].mpi_const,&local_a2[*intercomm].mpi_const,ERRIGNORE(array_of_errcodes));
    } else {
      api_use_ints *local_a1= active_comms->api_declared;
      api_use_ints *local_a2= active_comms->api_declared;
      int (*VendorMPI_Comm_spawn_multiple)(int count,char **array_of_commands,char ***array_of_argv,int *array_of_maxprocs,void **,int root,int,int *, int *array_of_errcodes) = address;
      mpi_return = (*VendorMPI_Comm_spawn_multiple)(count,array_of_commands,array_of_argv,array_of_maxprocs,ifill,root,local_a1[comm].mpi_const,&local_a2[*intercomm].mpi_const,ERRIGNORE(array_of_errcodes));
    }

    if (itemp) free(itemp);

  } else { api_use_ints *local_a0=active_infos->api_declared;
    int i;
    int temp[64], *itemp=0, *ifill;
    if (count > 64)
      ifill = itemp = (int *)calloc(count,sizeof(int));
    else ifill = temp;

    for(i=0; i<count; i++) 
      ifill[i] = local_a0[ array_of_info[i] ].mpi_const;

    if (active_comms->use_ptrs) {
      api_use_ptrs *local_a1= active_comms->api_declared;
      api_use_ptrs *local_a2= active_comms->api_declared;
      int (*VendorMPI_Comm_spawn_multiple)(int count,char **array_of_commands,char ***array_of_argv,int *array_of_maxprocs,int *,int root , void *,void **, int *array_of_errcodes) = address;
      mpi_return = (*VendorMPI_Comm_spawn_multiple)(count,array_of_commands,array_of_argv,array_of_maxprocs,ifill,root,local_a1[comm].mpi_const,&local_a2[*intercomm].mpi_const,ERRIGNORE(array_of_errcodes));
    } else {
      api_use_ints *local_a1= active_comms->api_declared;
      api_use_ints *local_a2= active_comms->api_declared;
      int (*VendorMPI_Comm_spawn_multiple)(int count,char **array_of_commands,char ***array_of_argv,int *array_of_maxprocs,int *,int root, int,int *, int *array_of_errcodes) = address;
      mpi_return = (*VendorMPI_Comm_spawn_multiple)(count,array_of_commands,array_of_argv,array_of_maxprocs,ifill,root,local_a1[comm].mpi_const,&local_a2[*intercomm].mpi_const,ERRIGNORE(array_of_errcodes));
    }
    if (itemp) free(itemp);
  }
  return mpi_return;
}
