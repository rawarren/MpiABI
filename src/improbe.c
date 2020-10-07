
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Mprobe
 */

#include <_mpi.h>

int
MPI_Improbe (int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status)
{
  static void *address=0;
  int mpi_return = MPI_SUCCESS;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Improbe")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Improbe",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  if (message) {
    int msgIndex = *message;
    if (active_comms->use_ptrs) {
        api_use_ptrs *local_a0= active_comms->api_declared;
        api_use_ptrs *local_a1= active_msgs->api_declared;
        void *native_ptr = NULL;
        if (msgIndex == MPI_MESSAGE_NO_PROC)
            native_ptr = local_a1[ISC_MESSAGE_NO_PROC_].mpi_const;
        else {
          native_ptr = local_a1[ISC_MESSAGE_NULL_].mpi_const;
          if (source != MPI_PROC_NULL) {
              msgIndex = new_index(active_msgs);
              local_a1[msgIndex].mpi_const = native_ptr;
              *message = msgIndex;
          }
        }

        int (*VendorMPI_Improbe)(int source,int tag,void *, int *, void **, MPI_Status *) = address;
        mpi_return = (*VendorMPI_Improbe)(ANYSRC(source),ANYTAG(tag),local_a0[comm].mpi_const, flag, &native_ptr, SIGNORE(status));
        if (status != MPI_STATUS_IGNORE) {
            if (mpi_return == 0) {
                if (*flag) {
                    native_status_to_isc_no_error(1,status->reserved, (int *)status);
                }
            }
            else native_status_to_isc(1,status->reserved,(int *)status);
        }
        if (msgIndex > 0) local_a1[msgIndex].mpi_const = native_ptr;
    } /* End if (use_ptrs) */
    else {
        api_use_ints *local_a0= active_comms->api_declared;
        api_use_ints *local_a1= active_msgs->api_declared;
        int native_int = 0;
        if (msgIndex == MPI_MESSAGE_NO_PROC)
            native_int = local_a1[ISC_MESSAGE_NO_PROC_].mpi_const;
        else {
            native_int = local_a1[ISC_MESSAGE_NULL_].mpi_const;
            if (source != MPI_PROC_NULL) {
                msgIndex = new_index(active_msgs);
                local_a1[msgIndex].mpi_const = native_int;
                *message = msgIndex;
            }
        }
        int (*VendorMPI_Improbe)(int source,int tag, int, int *, int *, MPI_Status *status) = address;
        mpi_return = (*VendorMPI_Improbe)(ANYSRC(source),ANYTAG(tag),local_a0[comm].mpi_const, flag, &native_int, SIGNORE(status));
        if (status != MPI_STATUS_IGNORE) {
            if (mpi_return == 0) {
                if (*flag)
                    native_status_to_isc_no_error(1,status->reserved, (int *)status);
            }
            else native_status_to_isc(1,status->reserved,(int *)status);
        }
        if (msgIndex > 0) local_a1[msgIndex].mpi_const = native_int;
    } /* End if (use_ints) */

    if ((mpi_return == 0) && (source == MPI_PROC_NULL)) {
        *message = MPI_MESSAGE_NO_PROC;
    }

    if (msgIndex > 0) free_index(active_msgs,msgIndex);
  } /* End if (message) */

  return mpi_return;
}
