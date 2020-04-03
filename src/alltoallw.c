
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Alltoallw
 */

#include <_mpi.h>
#include <stdlib.h>
#include <string.h>

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
MPI_Alltoallw (void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm)
{
    static void *address=0;
    int mpi_return;
    int is_intercomm = 0;
    int i, size, lsize, asize = 0;

    if (!address) {
	if ((address = dlsym(MPI_libhandle,"MPI_Alltoallw")) == NULL) {
	  address = (void *)-1;
	}
    }

    MPI_Comm_size(comm,&size);
    MPI_Comm_test_inter(comm,&is_intercomm);
    if (is_intercomm) {
	lsize = size;
	MPI_Comm_remote_size(comm,&size);
	// asize = (remote_size > size ? remote_size : size);
    }

    if (active_datatypes->use_ptrs) { api_use_ptrs *local_a0 = active_datatypes->api_declared;
       api_use_ptrs *local_a1= active_datatypes->api_declared;
       api_use_ptrs *local_a2= active_comms->api_declared;
       void *temp[128],**dtemp=0, **dfill;
       if (size > 64) {
	 dfill = dtemp = (void *)calloc(size*2,sizeof(void *));
       } else dfill = temp;
       if (sendbuf == (void *)ISC_IN_PLACE) 
	   memset(dfill,0, sizeof(void *) *size);
       else {
	   for(i=0; i<size; i++) {
	       dfill[i] = local_a0[sendtypes[i]].mpi_const;
	   }
       }
       if (recvbuf == (void *)ISC_IN_PLACE)
	   memset(&dfill[size],0, sizeof(void *) *size);
       else {
	   for(i=0; i<size; i++) {
	       dfill[size + i] = local_a1[recvtypes[i]].mpi_const;
	   }
       }
       int (*VendorMPI_Alltoallw)(void *sendbuf,int sendcounts[],int sdispls[],void *,void *recvbuf,int recvcounts[],int rdispls[],void *,void *) = address;
       mpi_return = (*VendorMPI_Alltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const);
       if (dtemp) free(dtemp);
    } else { api_use_ints *local_a0 = active_datatypes->api_declared;
       api_use_ints *local_a1= active_datatypes->api_declared;
       api_use_ints *local_a2= active_comms->api_declared;
       int temp[128],*dtemp=0, *dfill;
       if (size > 64)
	 dfill = dtemp = (int *)calloc(size*2,sizeof(int));
       else dfill = temp;

       if (sendbuf == (void *)ISC_IN_PLACE) 
	   memset(dfill,0, sizeof(int) *size);
       else {
	   for(i=0; i<size; i++) {
	       dfill[i] = local_a0[sendtypes[i]].mpi_const;
	   }
       }
       if (recvbuf == (void *)ISC_IN_PLACE)
	   memset(&dfill[size],0, sizeof(int) *size);	   
       else {
	   for(i=0; i<size; i++) {
	       dfill[size + i] = local_a1[recvtypes[i]].mpi_const;
	   }
       }
       int (*VendorMPI_Alltoallw)(void *sendbuf,int sendcounts[],int sdispls[],int *,void *recvbuf,int recvcounts[],int rdispls[],int *,int) = address;
       mpi_return = (*VendorMPI_Alltoallw)(INPLACE(sendbuf),sendcounts,sdispls,dfill,INPLACE(recvbuf),recvcounts,rdispls,&dfill[size],local_a2[comm].mpi_const);
       if (dtemp) free(dtemp);
    }
    return mpi_return;
}
