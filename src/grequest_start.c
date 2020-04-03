
/*
 * This text was generated automatically
 * It provides the ISC implementation of
 * MPI_Grequest_start
 */

#include <_mpi.h>

typedef struct intercept_entry {
    MPI_Request request_id;
    MPI_Grequest_query_function *query_fn;
    MPI_Grequest_free_function *free_fn;
    void *extra_state;
    struct intercept_entry *next;
} intercept_entry_t;

static intercept_entry_t *grequests_head = NULL;
static int active_entries = 0;

static int add_intercept(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Request request_id, void *extra_state)
{
    intercept_entry_t *new_intercept = (intercept_entry_t *)malloc(sizeof(intercept_entry_t));
    if (new_intercept) {
	if (grequests_head == NULL) {
	    grequests_head = new_intercept;
	    new_intercept->next = NULL;
	}
	else {
	    new_intercept->next = grequests_head->next;
	    grequests_head = new_intercept;
	}
	new_intercept->query_fn = query_fn;
	new_intercept->free_fn = free_fn;
	new_intercept->request_id = request_id;
	new_intercept->extra_state = extra_state;
	active_entries++;
	return 0;
    }
    return -1;
}

static
int maybe_free_grequest_context_by_state(void *extra_state)
{
    int found = 0;
    intercept_entry_t *context = grequests_head;
    intercept_entry_t *prev = NULL;
    while(context != NULL) {
	if (context->extra_state == extra_state) {
	    found = 1;
	    if (prev == NULL) {
		grequests_head = context->next;
	    }
	    else prev->next = context->next;
	    free(context);
	    context = NULL;
	}
	else {
	    prev = context;
	    context = context->next;
	}
    }
    return found;
}

int ISC_Grequest_free_ftn_redirect(void *extra_state)
{
    int retval = 0;
    int searching = 1;
    if (grequests_head) {
	intercept_entry_t *context = grequests_head;
	while (searching && context) {
	    if (context->extra_state == extra_state) {
		searching = 0;
		retval = context->free_fn(extra_state);
	    }
	    else context = context->next;
	}
	if (retval < 0) {
	    puts("Free function failed!");
	}
	maybe_free_grequest_context_by_state(extra_state);
    }
    return 0;
}

/* As a grequest callback, the status object given as input is 
 * actually a NATVIE MPI Status object rather than out own.
 * Note too, that the actaul callback function itself expects to see
 * the local (ABI) MPI_Status object.  We'll provide the latter and
 * then copy back into the native version
 */
int ISC_Grequest_query_ftn_redirect(void *extra_state, MPI_Status *status)
{
    int retval = 0;
    int searching = 1;
    if (grequests_head) {
	MPI_Status local_status;
	intercept_entry_t *context = grequests_head;
	while (searching && context) {
	    if (context->extra_state == extra_state) {
		searching = 0;
		retval = context->query_fn(extra_state,&local_status);
		if (retval < 0) {
		    puts("Query function failed!");
		} else {
		    isc_status_to_native(1,(int *)&local_status, (int *)status);
		}
	    }
	    else context = context->next;
	}
    }
    return retval;
}

int
MPI_Grequest_start (MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Grequest_start")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Grequest_start",SYM_MISSING_TRAILER);
      return -1;
    }
  }
  *request = new_index(active_requests);
  if (query_fn != NULL) {
      if (add_intercept(query_fn, free_fn, *request, extra_state) < 0) {
	  puts("Error adding grequest intercept");
      }
  }
  if (active_requests->use_ptrs) { api_use_ptrs *local_a0=active_requests->api_declared;
    int (*VendorMPI_Grequest_start)(MPI_Grequest_query_function *query_fn,MPI_Grequest_free_function *free_fn,MPI_Grequest_cancel_function *cancel_fn,void *extra_state,void **) = address;
    mpi_return = (*VendorMPI_Grequest_start)(ISC_Grequest_query_ftn_redirect,ISC_Grequest_free_ftn_redirect,cancel_fn,extra_state,&local_a0[*request].mpi_const);
  } else { api_use_ints *local_a0=active_requests->api_declared;
    int (*VendorMPI_Grequest_start)(MPI_Grequest_query_function *query_fn,MPI_Grequest_free_function *free_fn,MPI_Grequest_cancel_function *cancel_fn,void *extra_state,int *) = address;
    mpi_return = (*VendorMPI_Grequest_start)(ISC_Grequest_query_ftn_redirect,ISC_Grequest_free_ftn_redirect,cancel_fn,extra_state,&local_a0[*request].mpi_const);
  }
  return mpi_return;
}
