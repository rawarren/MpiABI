
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Comm_split_type
 */

#include <_mpi.h>
#include <stdlib.h>

int
MPI_Comm_split_type (MPI_Comm comm, int split_type, int color, int key, MPI_Info info, MPI_Comm *newcomm)
{
  static void *address=0;
  int mpi_return;
  int vendor_split_type;
  api_use_ints *local_a2 = active_miscs->api_declared;
  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Comm_split_type")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Comm_split_type",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *newcomm = new_index(active_comms);
  vendor_split_type = UNDEFINED(split_type);
  if (vendor_split_type == split_type)
      vendor_split_type = TYPESHARED(split_type);

  if (active_comms->use_ptrs) { api_use_ptrs *local_a0= active_comms->api_declared;
    api_use_ptrs *local_a1= active_comms->api_declared;
    if (active_infos->use_ptrs) { api_use_ptrs *local_a2=active_infos->api_declared;
	int (*VendorMPI_Comm_split_type)(void *,int split_type,int color,int key,void *,void **) = address;
	mpi_return = (*VendorMPI_Comm_split_type)(local_a0[comm].mpi_const,vendor_split_type,UNCOLOR(color),key,local_a2[info].mpi_const,&local_a1[*newcomm].mpi_const);
    } else { api_use_ints *local_a2=active_infos->api_declared;
	int (*VendorMPI_Comm_split_type)(void *,int split_type,int color,int key,int,void **) = address;
	mpi_return = (*VendorMPI_Comm_split_type)(local_a0[comm].mpi_const,vendor_split_type,UNCOLOR(color),key,local_a2[info].mpi_const,&local_a1[*newcomm].mpi_const);
    }
    if (local_a1[*newcomm].mpi_const == local_a1[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }
  } else { api_use_ints *local_a0= active_comms->api_declared;
    api_use_ints *local_a1= active_comms->api_declared;
    if (active_infos->use_ptrs) { api_use_ptrs *local_a2=active_infos->api_declared;
	int (*VendorMPI_Comm_split_type)(int,int split_type,int color,int key,void *,int *) = address;
	mpi_return = (*VendorMPI_Comm_split_type)(local_a0[comm].mpi_const,vendor_split_type,UNCOLOR(color),key,local_a2[info].mpi_const,&local_a1[*newcomm].mpi_const);
    } else { api_use_ints *local_a2=active_infos->api_declared;
	int (*VendorMPI_Comm_split_type)(int,int split_type,int color,int key,int, int *) = address;
	mpi_return = (*VendorMPI_Comm_split_type)(local_a0[comm].mpi_const,vendor_split_type,UNCOLOR(color),key,local_a2[info].mpi_const,&local_a1[*newcomm].mpi_const);
    }
    if (local_a1[*newcomm].mpi_const == local_a1[MPI_COMM_NULL].mpi_const) {
      free_index(active_comms,*newcomm);
      *newcomm = MPI_COMM_NULL;
    }
  }

  return mpi_return;
}
