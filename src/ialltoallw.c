
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Alltoallw
 */

#include <_mpi.h>
#include <stdlib.h>

static int
__ISC_Alltoallw (void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm)
{
    int i, rank, size;
    int status, nreqs;
    char *sbuf,*rbuf;
    MPI_Request rcache[128],*reqs,*rnext,*rtemp=0;

    MPI_Comm_size(comm,&size);
    MPI_Comm_rank(comm,&rank);

    sbuf = ((char *) sendbuf) + sdispls[rank];
    rbuf = ((char *) recvbuf) + rdispls[rank];

    /* Send to self */
    status = MPI_Sendrecv(sbuf,sendcounts[rank], sendtypes[rank], rank, 0x0abba,
			  rbuf,recvcounts[rank], recvtypes[rank], rank, 0x0abba,comm, MPI_STATUS_IGNORE);

    if (status || size == 1)
      return status;

    if (size > 64) {
      reqs = rtemp = (MPI_Request *)calloc(size*2,sizeof(MPI_Request));
    } else {
      reqs = rcache;
    }
    
    rnext = reqs;
    for(i=0; i< size; i++) {
      if (i == rank) continue;
      rbuf = ((char *) recvbuf) + rdispls[i];
      status = MPI_Irecv(rbuf,recvcounts[i],recvtypes[i],i,0x0abba, comm, rnext++);
      if (status) {
	/* What now?*/
      }
    }
    for(i=0; i< size; i++) {
      if (i == rank) continue;
      sbuf = ((char *) sendbuf) + sdispls[i];
      status = MPI_Isend(sbuf,sendcounts[i],sendtypes[i],i,0x0abba, comm, rnext++);
      if (status) {
	/* What now?*/
      }
    }
    
    nreqs = (size-1)*2;
    status = MPI_Waitall(nreqs, reqs, MPI_STATUSES_IGNORE);

    if (rtemp) free(rtemp);

    return status;
}


int
MPI_Ialltoallw (void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
{
#if 1
    static void *address=0;
#else
    static void *address= (void *)-1; /* Just for testing... */
#endif
    int mpi_return;
    int i, size;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Ialltoallw")) == NULL) {
	    printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Ialltoallw",SYM_MISSING_TRAILER);
	    return -1;
	}
    }
    MPI_Comm_size(comm,&size);

    *request = new_index(active_requests);
    if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
       api_use_ptrs *local_a1= active_datatypes->api_declared;
       api_use_ptrs *local_a2= active_comms->api_declared;
       void *temp[128],**dtemp=0, **dfill;
       if (size > 64) {
	 dfill = dtemp = (void *)calloc(size*2,sizeof(void *));
       } else dfill = temp;
       for(i=0; i<size; i++) {
	 dfill[i] = local_a0[sendtypes[i]].mpi_const;
       }
       for(i=0; i<size; i++) {
	 dfill[size + i] = local_a1[recvtypes[i]].mpi_const;
       }

       if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ialltoallw)(void *sendbuf,int sendcounts[],int sdispls[],void *,void *recvbuf,int recvcounts[],int rdispls[],void *,void *, void **) = address;
	   mpi_return = (*VendorMPI_Ialltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       }
       else { api_use_ints *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ialltoallw)(void *sendbuf,int sendcounts[],int sdispls[],void *,void *recvbuf,int recvcounts[],int rdispls[],void *,void *, int *) = address;
	   mpi_return = (*VendorMPI_Ialltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       }
       if (dtemp) free(dtemp);
    } else { api_use_ints *local_a0 = active_datatypes->api_declared;
       api_use_ints *local_a1= active_datatypes->api_declared;
       api_use_ints *local_a2= active_comms->api_declared;
       int temp[128],*dtemp=0, *dfill;
       if (size > 64)
	 dfill = dtemp = (int *)calloc(size*2,sizeof(int));
       else dfill = temp;
       for(i=0; i<size; i++) {
	 dfill[i] = local_a0[sendtypes[i]].mpi_const;
       }
       for(i=0; i<size; i++) {
	 dfill[size + i] = local_a1[recvtypes[i]].mpi_const;
       }
       if (active_requests->use_ptrs) { api_use_ptrs *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ialltoallw)(void *sendbuf,int sendcounts[],int sdispls[],int *,void *recvbuf,int recvcounts[],int rdispls[],int *,int, void **) = address;
	   mpi_return = (*VendorMPI_Ialltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       } else { api_use_ints *local_a3=active_requests->api_declared;
	   int (*VendorMPI_Ialltoallw)(void *sendbuf,int sendcounts[],int sdispls[],int *,void *recvbuf,int recvcounts[],int rdispls[],int *,int, int *) = address;	   
	   mpi_return = (*VendorMPI_Ialltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const, &local_a3[*request].mpi_const);
       }
       if (dtemp) free(dtemp);
    }
    return mpi_return;
}
