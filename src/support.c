
#if defined(__unix__)
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

#include "iscmpi_constants.h"


void *MPI_libhandle=0;
void *MPIO_libhandle=0;
void *ISC_maphandle=0;
void (*post_MPI_processing)()=0;

isc_const *active_comms=0;
isc_const *active_groups=0;
isc_const *active_requests=0;
isc_const *active_ops=0;
isc_const *active_datatypes=0;
isc_const *active_errhandlers=0;
isc_const *active_infos=0;
isc_const *active_wins=0;
isc_const *active_files=0;
isc_const *active_errcodes=0;
isc_const *active_miscs=0;
isc_const *active_addrs=0;
isc_const *active_msgs=0;
isc_const *active_amodebitfield=0;
isc_const *active_winassertbitfield=0;

int callbacks_use_integers = 1;	/* Most common mode, e.g. MPICH and others */

#define N_OBJ_TYPES 15
static struct {
  char *obj_name;
  isc_const **obj_ptr;
} builtin_obj_store[N_OBJ_TYPES] = {
  {"isc_builtin_comms",&active_comms},
  {"isc_builtin_groups",&active_groups},
  {"isc_builtin_requests",&active_requests},
  {"isc_builtin_ops",&active_ops},
  {"isc_builtin_dtypes",&active_datatypes},
  {"isc_builtin_errhandler",&active_errhandlers},
  {"isc_builtin_info",&active_infos},
  {"isc_builtin_win",&active_wins},
  {"isc_builtin_file",&active_files},
  {"isc_builtin_errcodes",&active_errcodes},
  {"isc_builtin_miscs",&active_miscs},
  {"isc_builtin_addr",&active_addrs},
  {"isc_builtin_msgs",&active_msgs},
  {"isc_builtin_amodebitfield",&active_amodebitfield},
  {"isc_builtin_winassertbitfield",&active_winassertbitfield}
};


int true_mpi_status_size=0;
int (*native_status_to_isc)(int count, int *native_stat, int *isc_stat) = 0;

int (*map_errcode_to_isc)(int native_err) = 0;

int isc_mpi_rank=-1;
int isc_mpi_size=-1;


static void
resolve_mpi_library(void)
{
  void *address=0;
  void *libhandle=0;
  void *self=0;

  char *vendor_mpi_library=0;
  char *vendor_mpio_library=0;
  char *temp=0;

  char *(*get_vendor_mpilib)() = 0;  

  if ((self = dlopen("libiscmpi.so", RTLD_NOW|RTLD_GLOBAL)) == NULL) {
      printf("A self dlopen failed: %s\n", dlerror());
  }

  if (!(libhandle = ISC_maphandle)) {
    libhandle = dlopen("isc_mapping.so", RTLD_LAZY);
    if (!libhandle) {
      printf("Error opening isc_mapping.so: %s\n",dlerror());
      exit(1);
    }
    ISC_maphandle = libhandle;
  }

  address = dlsym(libhandle,"get_vendor_mpilib");
  get_vendor_mpilib = address;
  vendor_mpi_library = get_vendor_mpilib();
  temp = strdup(vendor_mpi_library);
  vendor_mpi_library = temp;

  /* Cache the map_errcode_to_isc(int) utility entry point */
  address = dlsym(libhandle,"map_errcode_to_isc");
  map_errcode_to_isc = address;
  
  if (vendor_mpi_library) {	/* Returned string may be a comma seperated form */
    char *comma;		/* identifing both the mpi and mpi-io libraries. */
    if (comma = strchr(vendor_mpi_library,',')) {
      *comma = 0;
      vendor_mpio_library = comma+1;
    }
  }

  if (!MPI_libhandle) 
    MPI_libhandle = dlopen(vendor_mpi_library, RTLD_LAZY|RTLD_GLOBAL);

  if (!MPI_libhandle) {
      printf("FATAL: unable to open the MPI library: %s\n", dlerror());
      exit(1);
  }

  /* Most modern implementations don't seperate the MPI-IO parts
   * from the standard MPI functions.  For these, we assign
   * the MPIO_libhandle to be the same as the MPI_libhandle
   * before going about our business.
   * For those
   */
  if (!vendor_mpio_library) {
    MPIO_libhandle = MPI_libhandle;
  } else {
    MPIO_libhandle = dlopen(vendor_mpio_library, RTLD_LAZY|RTLD_GLOBAL);
    if (!MPIO_libhandle) {
      printf("WARNING: unable to open the MPIO library: %s\n", dlerror());
    }
  }
  if (temp) free(temp);

}

static void
allocate_and_fill(void *libhandle,
		  char *handleID,
		  isc_const **new,
		  int elems)
{
  int i=0;
  isc_const *vendor_defs, *prev = *new;

  if (!prev) {
    vendor_defs = dlsym(libhandle,handleID);
    if (!vendor_defs) {
      printf("FATAL: Unable to resolve isc_builtin_comms\n");
      exit(1);
    }
    *new = malloc(sizeof(isc_const));
    if (*new == 0) {
      perror("resolve_mpi_constants/malloc");
      exit(1);
    }
    memcpy(*new,vendor_defs,sizeof(isc_const));
  }
  else vendor_defs = prev;
  
  if (vendor_defs->use_ptrs) {
    api_use_ptrs *next, *from = vendor_defs->api_declared;
    (*new)->api_declared = calloc(elems, sizeof(api_use_ptrs));
    if (!(*new)->api_declared) {
      perror("resolve_mpi_constants/calloc");
      exit(1);
    }
    next = (*new)->api_declared;
    (*new)->limit = elems;
    for(i=0; i < vendor_defs->limit; i++) {
      next[i] = from[i];
    }
    if (prev)
      free(from);
  }
  else {
    api_use_ints *next,*from = vendor_defs->api_declared;
    (*new)->api_declared = calloc(elems, sizeof(api_use_ints));
    if (!(*new)->api_declared) {
      perror("resolve_mpi_constants/calloc");
      exit(1);
    }
    next = (*new)->api_declared;
    (*new)->limit = elems;
    for(i=0; i < vendor_defs->limit; i++) {
      next[i] = from[i];
    }
    if (prev)
      free(from);
  }
}


static int use_mutex = 0;
static pthread_mutex_t funnel_new_index;
#define LOCK(x,line) if (use_mutex) {pthread_mutex_lock(&(x));}
#define UNLOCK(x,line) if (use_mutex) {pthread_mutex_unlock(&(x));}


void
expand_store(isc_const *store, int elems)
{
  int i;
  if (store->use_ptrs) {
    api_use_ptrs *old,*new = (api_use_ptrs *)calloc(elems, sizeof(api_use_ptrs));
    old = store->api_declared;
    for(i=0; i < store->limit; i++) {
      new[i] = old[i];
    }
    for(; i < elems; i++) {
      new[i].self = i;
    }
    store->limit = elems;
    store->api_declared = new;
    free(old);
  } else {
    api_use_ints *old,*new = (api_use_ints *)calloc(elems, sizeof(api_use_ints));
    old = store->api_declared;
    for(i=0; i < store->limit; i++) {
      new[i] = old[i];
      new[i].self = i;
    }
    for(; i < elems; i++) {
      new[i].self = i;
    }
    store->limit = elems;
    store->api_declared = new;
    free(old);
  }
}

int
get_index(isc_const *store, void *value)
{
  int i;
  if (store->use_ptrs) {
    api_use_ptrs *next=store->api_declared;
    void **vptr = value;
    for(i=0; i<store->how_many; i++) {
      if (next[i].mpi_const == vptr[0])
	return next[i].self;
    }
  }
  else {
    api_use_ints *next=store->api_declared;
    int *vptr = value;
    for(i=0; i<store->how_many; i++) {
      if (next[i].mpi_const == vptr[0])
	return next[i].self;
    }
  }
  return 0;
}

int
new_index(isc_const *store) 
{
  LOCK(funnel_new_index, __LINE__);
  int index;
  isc_freelist *nextfree;
  if ((nextfree = store->freed) != NULL) {
    if (store->use_ptrs) {
      api_use_ptrs *elem = (api_use_ptrs *)nextfree->element;
      store->freed = nextfree->next;
      elem->MPI_name = NULL;
      elem->mpi_const = 0;
      free(nextfree);
      UNLOCK(funnel_new_index, __LINE__);
      return elem->self;
    }
    else {
      api_use_ints *elem = (api_use_ints *)nextfree->element;
      store->freed = nextfree->next;
      elem->MPI_name = NULL;
      elem->mpi_const = 0;
      free(nextfree);
      UNLOCK(funnel_new_index, __LINE__);
      return elem->self;
    }
  }
  index = store->how_many++;
  if (store->how_many == store->limit) 
    expand_store(store,(store->limit <<1)); /* Double the current size */

  if (store->use_ptrs) {
    api_use_ptrs *next=store->api_declared;
    next[index].self = index;
    next[index].mpi_const = NULL;
  } else {
    api_use_ints *next=store->api_declared;
    next[index].self = index;
    next[index].mpi_const = 0;
  }
  UNLOCK(funnel_new_index, __LINE__);
  return index;
}

void
free_index(isc_const *store, int index) 
{
  /* Don't attempt to free a builtin object */
  if (index < store->permlimit) return;
  LOCK(funnel_new_index,__LINE__);
#if 0  
  if (store->freed) {
    if (store->use_ptrs) {
      api_use_ptrs *next = store->freed;
      api_use_ptrs *base = store->api_declared;
      while(next->MPI_name) {
	next = (api_use_ptrs *)next->MPI_name;
      }
      next->MPI_name = (char *)&base[index];
    } else {
      api_use_ints *next = store->freed;
      api_use_ints *base = store->api_declared;
      while(next->MPI_name) {
	next = (api_use_ints *)next->MPI_name;
      }
      next->MPI_name = (char *)&base[index];
    }
  } else {
    if (store->use_ptrs) {
      api_use_ptrs *base = store->api_declared;
      store->freed = &base[index];
      base[index].MPI_name = NULL;
    } else {
      api_use_ints *base = store->api_declared;
      store->freed = &base[index];
      base[index].MPI_name = NULL;
    }
  }
#else
  isc_freelist *thisobj, *nextfree = NULL;
  if ((thisobj = (isc_freelist *)malloc(sizeof(isc_freelist))) != NULL) {
     thisobj->next = NULL;
     if (store->use_ptrs) {
        api_use_ptrs *base = store->api_declared;
	api_use_ptrs *elem = &base[index];
	thisobj->element   = elem;
        if ((nextfree = store->freed) == NULL)
            store->freed = thisobj;
        else {
            isc_freelist *prev = NULL;
            while(nextfree->next) {
               prev = nextfree;
               nextfree = nextfree->next;
	    }
            nextfree->next = thisobj;
	}
     }
     else {
        api_use_ints *base = store->api_declared;
	api_use_ints *elem = &base[index];
	thisobj->element   = elem;
        if ((nextfree = store->freed) == NULL)
            store->freed = thisobj;
        else {
            isc_freelist *prev = NULL;
            while(nextfree->next) {
               prev = nextfree;
               nextfree = nextfree->next;
	    }
            nextfree->next = thisobj;
	}
     }

  }
#endif
  UNLOCK(funnel_new_index,__LINE__);

  return;
}

/*
 * Fortran datatypes used by 'C' which are expressed
 * in terms of MPI_Type_f2c
 * Note:
 *   Currently only HP does this in their mpi.h file
 */

void
__resolve_fdtype(int isc_index, int ftnvalue)
{
  void *address = dlsym(MPI_libhandle,"MPI_Type_f2c");
  if (active_datatypes && address) {
    if (active_datatypes->use_ptrs) {
      api_use_ptrs *objstore;
      if (objstore = active_datatypes->api_declared) {
	void *(*convert)(int) = address;
	objstore[isc_index].mpi_const =
	  convert(ftnvalue);
      }
    }
    else {
      /* Perverse situation where Fortran constants
       * aren't the same as those used by 'C'!
       */
      api_use_ints *objstore;
      if (objstore = active_datatypes->api_declared) {
	int(*convert)(int) = address;
	objstore[isc_index].mpi_const =
	  convert(ftnvalue);
      }
    }
  }
  return;
}

/* Here's another workaround for HP.  */

void
__resolve_ptr_builtin(int isc_index, char *symbol)
{
  void *address = dlsym(MPI_libhandle,symbol);
  if (address && active_addrs) {
    api_use_ptrs *objstore = active_addrs->api_declared;
    objstore[isc_index].mpi_const = address;
  }
}


static void
resolve_mpi_constants(void)
{
  int i=0;
  isc_const *vendor_defs;
  void *address, (*dolazy)();
  void *libhandle;

  if (!(libhandle = ISC_maphandle)) {
    libhandle = dlopen("isc_mapping.so", RTLD_LAZY);
    if (!libhandle) {
      printf("Error opening isc_mapping.so: %s\n",dlerror());
      exit(1);
    }
    ISC_maphandle =libhandle;
  }

  for(i=0; i<N_OBJ_TYPES; i++) {
    allocate_and_fill(libhandle,
		      builtin_obj_store[i].obj_name,
		      builtin_obj_store[i].obj_ptr,
		      128);	/* Initial bucket size */
  }

  address = dlsym(libhandle,"native_mpi_status_to_isc");
  if (address == 0) {
    printf("No support for native_status_to_isc!\n");
  }
  else native_status_to_isc = address;

  address = dlsym(libhandle,"maybe_do_lazy_evaluations");
  if (address) {
    void (*register_callback)(void *);
    post_MPI_processing = address;

    address = dlsym(libhandle,"register_callback_1");
    if (address) {
      register_callback = address;
      register_callback(__resolve_fdtype);
    }
    address = dlsym(libhandle,"register_callback_2");
    if (address) {
      register_callback = address;
      register_callback(__resolve_ptr_builtin);
    }
  }

  address = dlsym(libhandle,"native_mpi_status_size");
  if (address) {
    int *get_value = address;
    true_mpi_status_size = *get_value;
  }

  address = dlsym(libhandle,"api_native_comms_are_integers");
  if (address) {
    int (*get_callback_type)(void) = address;
    callbacks_use_integers = get_callback_type();
  }
}

#ifndef CALLBACK_TYPES_DEFINED
#define CALLBACK_TYPES_DEFINED 1

typedef enum {
  COMM_CALLBACK=1,
  DATATYPE_CALLBACK
} callback_t;

#endif


typedef struct keyvalpair {
  int keyval;
  int isc_object;
  void *ftn_pointer;
  struct keyvalpair *next;
} keyvalpair_t;

static keyvalpair_t *comm_attr_copy_callbacks = NULL;
static keyvalpair_t *comm_attr_delete_callbacks = NULL;
static keyvalpair_t *datatype_attr_copy_callbacks = NULL;
static keyvalpair_t *datatype_attr_delete_callbacks = NULL;

static pthread_mutex_t funnel_new_callback;

int save_user_copy_callback(void *copyfn, int keyval, callback_t this_callback_type)
{
  keyvalpair_t *new_callback = (keyvalpair_t *)calloc(1, sizeof(keyvalpair_t));
  if (new_callback == NULL) return -1;
  LOCK(funnel_new_callback,__LINE__);
  new_callback->keyval = keyval;
  new_callback->ftn_pointer = copyfn;
  if (this_callback_type == COMM_CALLBACK) {
    new_callback->next = comm_attr_copy_callbacks;
    comm_attr_copy_callbacks = new_callback;
  }
  else if (this_callback_type == DATATYPE_CALLBACK) {
    new_callback->next = datatype_attr_copy_callbacks;
    datatype_attr_copy_callbacks = new_callback;
  }
  UNLOCK(funnel_new_callback,__LINE__);
  return 0;
}

int save_user_delete_callback(void *delfn, int keyval, callback_t this_callback_type)
{
  keyvalpair_t *new_callback = (keyvalpair_t *)calloc(1, sizeof(keyvalpair_t));
  if (new_callback == NULL) return -1;
  LOCK(funnel_new_callback,__LINE__);
  new_callback->keyval = keyval;
  new_callback->ftn_pointer = delfn;
  if (this_callback_type == COMM_CALLBACK) {
    new_callback->next = comm_attr_delete_callbacks;
    comm_attr_delete_callbacks = new_callback;
  }
  else if (this_callback_type == DATATYPE_CALLBACK) {
    new_callback->next = datatype_attr_delete_callbacks;
    datatype_attr_delete_callbacks = new_callback;
  }
  UNLOCK(funnel_new_callback, __LINE__);
  return 0;
}

static int __maybe_update_callbacks(keyvalpair_t *head, int isc_object, int keyval)
{
  keyvalpair_t *this = head;
  while(this != NULL) {
    if (this->keyval == keyval) {
      this->isc_object = isc_object;
      return 1;
    }
    this = this->next;
  }
  return 0;
}

static keyvalpair_t * __maybe_delete_callbacks(keyvalpair_t *head, int isc_object, int keyval)
{
    keyvalpair_t *this = head;
    keyvalpair_t *prev = NULL;
    while(this != NULL) {
      if (isc_object == -1) { /* Any object */
	if (this->keyval == keyval) {
	  /* Unlink the entry from the list */
	  if (prev) {
	    prev->next = this->next;
	  }
	  return this;
	}
      } else if ((this->isc_object == isc_object) && (this->keyval == keyval)) {
	/* Unlink the entry from the list */
	if (prev) {
	  prev->next = this->next;
	}
	return this;
      } else if ((this->isc_object == isc_object) && (keyval == -1)) {
	/* Unlink the entry from the list */
	if (prev) {
	  prev->next = this->next;
	}
	return this;
      }
      prev = this;
      this = this->next;
    }
    return NULL;
}

int remove_object_keyval_callbacks(int isc_object, int keyval, callback_t this_callback_type)
{
    keyvalpair_t *callback = NULL;
    LOCK(funnel_new_callback, __LINE__);
    if (this_callback_type == COMM_CALLBACK) {
      if ((comm_attr_copy_callbacks != NULL) && 
	  ((callback = __maybe_delete_callbacks(comm_attr_copy_callbacks, isc_object, keyval)))) {
	if (callback == comm_attr_copy_callbacks)
	    comm_attr_copy_callbacks = callback->next;
	free(callback);
      }
      
      callback = NULL;
      if ((comm_attr_delete_callbacks != NULL) && 
	  ((callback = __maybe_delete_callbacks(comm_attr_delete_callbacks, isc_object, keyval)))) {
	if (callback == comm_attr_delete_callbacks)
	    comm_attr_delete_callbacks = callback->next;
	free(callback);
      }

    } else if (this_callback_type == DATATYPE_CALLBACK) {
      if ((datatype_attr_copy_callbacks != NULL) &&
	  ((callback = __maybe_delete_callbacks(datatype_attr_copy_callbacks, isc_object, keyval)))) {
	if (callback == datatype_attr_copy_callbacks)
	    datatype_attr_copy_callbacks = callback->next;
	free(callback);
      }

      callback = NULL;
      if ((datatype_attr_delete_callbacks != NULL) &&
	  ((callback = __maybe_delete_callbacks(datatype_attr_delete_callbacks, isc_object, keyval)))) {
	if (callback == datatype_attr_delete_callbacks)
	    datatype_attr_delete_callbacks = callback->next;
	free(callback);
      }
    }
    UNLOCK(funnel_new_callback, __LINE__);
    return 0;
}


int maybe_update_callbacks(int isc_object, int keyval, callback_t callback_type)
{
  int updates = 0;
  if (callback_type == COMM_CALLBACK) {
    updates += __maybe_update_callbacks(comm_attr_copy_callbacks, isc_object, keyval);
    updates += __maybe_update_callbacks(comm_attr_delete_callbacks, isc_object, keyval);
  }
  else if (callback_type == DATATYPE_CALLBACK) {
    updates += __maybe_update_callbacks(datatype_attr_copy_callbacks, isc_object, keyval);
    updates += __maybe_update_callbacks(datatype_attr_delete_callbacks, isc_object, keyval);
  }
  return updates;
}

int maybe_dup_internal_reference(int keyval, int isc_object, int new_isc_object , callback_t callback_type)
{
  int i, dups=0;
  keyvalpair_t *callback;

  LOCK(funnel_new_callback, __LINE__);

  for(i=0; i<2; i++) {
    int referenced = 0;
    if (callback_type == COMM_CALLBACK)
      callback = (i == 0 ? comm_attr_delete_callbacks : comm_attr_copy_callbacks);
    else if (callback_type == DATATYPE_CALLBACK)
      callback = (i == 0 ? datatype_attr_delete_callbacks : datatype_attr_copy_callbacks);

    while((callback != NULL) && (referenced == 0)) {
      if ((keyval > 0) && (callback->keyval == keyval)) referenced++;
      if ((isc_object > 0) && (callback->isc_object == isc_object)) referenced++;
      /* If we supply a non-zero new_isc_object,
       * this indicates that we want to duplicate the 
       */
      if ((referenced > 0) && (new_isc_object > 0)) {
	keyvalpair_t *dup_callback = (keyvalpair_t *)calloc(1, sizeof(keyvalpair_t));
	if (dup_callback != NULL) {
	  dup_callback->keyval = callback->keyval;
	  dup_callback->isc_object = new_isc_object;
	  dup_callback->ftn_pointer = callback->ftn_pointer;
	  /* Insert into the current list */
	  dup_callback->next = callback->next;
	  callback->next = dup_callback;
	  dups++;
	}
      } else {
	callback = callback->next;
      }
    }
  }  
  UNLOCK(funnel_new_callback, __LINE__);

  return dups;
}

#if 0
static int count_references(int keyval, keyvalpair_t *head)
{
  int count = 0;
  keyvalpair_t *this = head;
  while(this != NULL) {
    if (this->keyval == keyval) count++;
    this = this->next;
  }
  return count;
}

int attr_reference_exists(int keyval, callback_t callback_type)
{
  int references = 0;
  keyvalpair_t *callback;

  if (callback_type == COMM_CALLBACK) {
    references = count_references(keyval, comm_attr_copy_callbacks);
    references += count_references(keyval, comm_attr_delete_callbacks);
  }
  else if (callback_type == DATATYPE_CALLBACK) {
    references = count_references(keyval, datatype_attr_copy_callbacks);
    references += count_references(keyval, datatype_attr_delete_callbacks);
  }
  return references;
}
#else
static int count_references(int isc_object, int keyval, keyvalpair_t *head)
{
  int count = 0;
  keyvalpair_t *this = head;
  while(this != NULL) {
    if ((keyval == -1) ||
	(keyval == this->keyval)) {
      if ((isc_object == -1) ||
          (this->isc_object == isc_object)) count++;
    }
    this = this->next;
  }
  return count;
}

int attr_reference_exists(int isc_object, int keyval, callback_t callback_type)
{
  int references = 0;
  keyvalpair_t *callback;

  if (callback_type == COMM_CALLBACK) {
    references = count_references(isc_object, keyval, comm_attr_copy_callbacks);
    references += count_references(isc_object, keyval, comm_attr_delete_callbacks);
  }
  else if (callback_type == DATATYPE_CALLBACK) {
    references = count_references(isc_object, keyval, datatype_attr_copy_callbacks);
    references += count_references(isc_object, keyval, datatype_attr_delete_callbacks);
  }
  return references;
}
#endif


/* NOTE: 
 * The following functions are substitutes for the user specified
 * functons and are called directly from the underlying MPI library. 
 * The issue we address here, is that user defined functions all run
 * in the context of the MPIABI layer, but the actual input arguments
 * specifying the communicator and the key-value here are those supplied
 * by the underlying MPI library.   
 * We to translate those values back into their MPIABI equivelents
 * for calling the actual user defined function.
 */
int ISC_Integer_comm_copy_function (int comm, int comm_keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, int *flag) {
  keyvalpair_t *callback = comm_attr_copy_callbacks;
  api_use_ints *mpiabi_comm = active_comms->api_declared;
  api_use_ints *mpiabi_attr = active_miscs->api_declared;
  while(callback != NULL) {
    int native_keyval = mpiabi_attr[callback->keyval].mpi_const;
    if ((native_keyval == comm_keyval) &&
	(callback->ftn_pointer != NULL)) {
      int (*user_copy_fn)(int,int,void *,void *,void *,int *) = callback->ftn_pointer;
      return user_copy_fn(callback->isc_object, callback->keyval, extra_state, attribute_val_in, attribute_val_out, flag);
    }
    callback = callback->next;
  }
  return 0;
}

int ISC_Integer_comm_delete_function (int comm, int comm_keyval, void *attribute_val, void *extra_state) {
  keyvalpair_t *callback = comm_attr_delete_callbacks;
  api_use_ints *mpiabi_comm = active_comms->api_declared;
  api_use_ints *mpiabi_attr = active_miscs->api_declared;
  while(callback != NULL) {
    int native_keyval = mpiabi_attr[callback->keyval].mpi_const;
    int isc_object, keyval, result;
    if ((native_keyval == comm_keyval) &&
	(callback->ftn_pointer != NULL)) {
      int (*user_delete_fn)(int,int,void *,void *) = callback->ftn_pointer;
      isc_object = callback->isc_object;
      keyval = callback->keyval;
      return user_delete_fn(isc_object, keyval, attribute_val, extra_state);
    }
    callback = callback->next;
  }
  return 0;
}

int ISC_Pointer_comm_copy_function (void * oldcomm, int comm_keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, int *flag) {
  keyvalpair_t *callback = comm_attr_copy_callbacks;
  api_use_ptrs *mpiabi_comm = active_comms->api_declared;
  api_use_ints *mpiabi_attr = active_miscs->api_declared;
  while(callback != NULL) {
    int native_keyval = mpiabi_attr[callback->keyval].mpi_const;
    if ((native_keyval == comm_keyval) &&
	(callback->ftn_pointer != NULL)) {
      int (*user_copy_fn)(int,int,void *,void *,void *,int *) = callback->ftn_pointer;
      return user_copy_fn(callback->isc_object, callback->keyval, extra_state, attribute_val_in, attribute_val_out, flag);
    }
    callback = callback->next;
  }
  return 0;
}

int ISC_Pointer_comm_delete_function (void * comm, int comm_keyval, void *attribute_val, void *extra_state) {
  keyvalpair_t *callback = comm_attr_delete_callbacks;
  api_use_ptrs *mpiabi_comm = active_comms->api_declared;
  api_use_ints *mpiabi_attr = active_miscs->api_declared;
  while(callback != NULL) {
    int native_keyval = mpiabi_attr[callback->keyval].mpi_const;
    int isc_object, keyval, result;
    if ((native_keyval == comm_keyval) &&
	(callback->ftn_pointer != NULL)) {
      int (*user_delete_fn)(int,int,void *,void *) = callback->ftn_pointer;
      isc_object = callback->isc_object;
      keyval = callback->keyval;
      return user_delete_fn(isc_object, keyval, attribute_val, extra_state);
    }
    callback = callback->next;
  }
  return 0;
}

int ISC_Integer_datatype_copy_function (int dtype, int type_keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, int *flag) {
  keyvalpair_t *callback = datatype_attr_copy_callbacks;
  api_use_ints *mpiabi_type = active_datatypes->api_declared;
  api_use_ints *mpiabi_attr = active_miscs->api_declared;
  while(callback != NULL) {
    int native_keyval = mpiabi_attr[callback->keyval].mpi_const;
    if ((native_keyval == type_keyval) &&
	(callback->ftn_pointer != NULL)) {
      int (*user_copy_fn)(int,int,void *,void *,void *,int *) = callback->ftn_pointer;
      return user_copy_fn(callback->isc_object, callback->keyval, extra_state, attribute_val_in, attribute_val_out, flag);
    }
    callback = callback->next;
  }
  return 0;
}

int ISC_Integer_datatype_delete_function (int dtype, int type_keyval, void *attribute_val, void *extra_state) {
  keyvalpair_t *callback = datatype_attr_delete_callbacks;
  api_use_ints *mpiabi_type = active_datatypes->api_declared;
  api_use_ints *mpiabi_attr = active_miscs->api_declared;
  while(callback != NULL) {
    int native_keyval = mpiabi_attr[callback->keyval].mpi_const;
    int isc_object, keyval;
    if ((native_keyval == type_keyval) &&
	(callback->ftn_pointer != NULL)) {
      int (*user_delete_fn)(int,int,void *,void *) = callback->ftn_pointer;
      isc_object = callback->isc_object;
      keyval = callback->keyval;
      return user_delete_fn(isc_object, keyval, attribute_val, extra_state);
    }
    callback = callback->next;
  }
  return 0;
}

int ISC_Pointer_datatype_copy_function (void * dtype, int type_keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, int *flag) {
  keyvalpair_t *callback = datatype_attr_copy_callbacks;
  api_use_ptrs *mpiabi_type = active_datatypes->api_declared;
  api_use_ints *mpiabi_attr = active_miscs->api_declared; /* Note use of 'int' usage for attributes */
  while(callback != NULL) {
    int isc_object, native_keyval = mpiabi_attr[callback->keyval].mpi_const;
    if ((native_keyval == type_keyval) &&
	(callback->ftn_pointer != NULL)) {
      int (*user_copy_fn)(int,int,void *,void *,void *,int *) = callback->ftn_pointer;
      isc_object = callback->isc_object;
      return user_copy_fn(isc_object, callback->keyval, extra_state, attribute_val_in, attribute_val_out, flag);
    }
    callback = callback->next;
  }
  return 0;
}

int ISC_Pointer_datatype_delete_function (void * dtype, int type_keyval, void *attribute_val, void *extra_state) {
  keyvalpair_t *callback = datatype_attr_delete_callbacks;
  api_use_ptrs *mpiabi_type = active_datatypes->api_declared;
  api_use_ints *mpiabi_attr = active_miscs->api_declared;
  while(callback != NULL) {
    int native_keyval = mpiabi_attr[callback->keyval].mpi_const;
    int isc_object, keyval;
    if ((native_keyval == type_keyval) &&
	(callback->ftn_pointer != NULL)) {
      int (*user_delete_fn)(void *,int,void *,void *) = callback->ftn_pointer;
      isc_object = callback->isc_object;
      keyval = callback->keyval;
      return user_delete_fn(dtype, keyval, attribute_val, extra_state);
    }
    callback = callback->next;
  }
  return 0;
}



/* --------------------------------------------------------
 * Here are the MPI functions invoked by our simple test
 * program ;-) Actually, we define MPI_Init and MPI_Finalize
 * here rather than translating them automagically since
 * these functions need to a bit of extra work...
 * --------------------------------------------------------
 */
#include "_mpi.h"

int
MPI_Initialized (int *flag)
{
  static void *address=0;
  int mpi_return;

  if (!address) {
    if (!MPI_libhandle) 
      resolve_mpi_library();

    if ((address = dlsym(MPI_libhandle,"MPI_Initialized")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Initialized",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Initialized) (int *flag) = address;
  mpi_return = (*VendorMPI_Initialized)(flag);
  return mpi_return;
}

#ifdef __GNUC__
void MPI_INITIALIZED() __attribute__ ((weak, alias("isc_initialized_f")));
void mpi_initialized() __attribute__ ((weak, alias("isc_initialized_f")));
void mpi_initialized_() __attribute__ ((weak, alias("isc_initialized_f")));
void mpi_initialized__() __attribute__ ((weak, alias("isc_initialized_f")));
#endif

/*
 * Entry point for all the fortran compiler varients
 * through the magic of weak symbols and/or aliases.
 */
void isc_initialized_f(int *flag, int *ierr)
{
  *ierr = MPI_Initialized(flag);
}


/*
 * Support for determining the initial process TOPOLOGY
 */

static int
cmphostid(const void *h1, const void *h2)
{
  return (*(int *)h1 > *(int *)h2);
}


static int *layout=0;
static int  *_ranks=0;
static int  *_nodes=0;
static int  *_peercounts=0;

typedef struct {
      int hostid;
      int rank;
} hr_tuple;

#define HR_RANK(R) ((int)hr_view[(R)].rank & 0xFFFF)
#define HR_ID(R)  (hr_view[(R)].hostid)
/* ---------------------------------------------------------
  The "layout" definition we use in determining the process
  topology is a regular array, but we use it as though it
  were a smaller array of tuples, e.g.
  
      struct {
       int hostid;
       int rank;
      }

  These get sorted by hostid (see cmphostid() above), which
  then allows us to process it to gather ranks-per-node,
  node-count, and to also determine distribution type:
  block vs. cyclic...
-----------------------------------------------------------*/

static int
__get_nodecount(void)
{
  static int nodecount = 0;
  if (nodecount) return nodecount;

  if (_ranks && _nodes && _peercounts && layout) {
    int i, basei=0;
    hr_tuple *hr_view = (hr_tuple *)layout;
    int checkid = HR_ID(0);
    _nodes[0] = 0;

    for(i=0; i < isc_mpi_size; i++) {
      _ranks[i] = HR_RANK(i);
      if (HR_ID(i) != checkid) {
	checkid = HR_ID(i);
	_peercounts[nodecount] = i - basei;
	basei = i;
	_nodes[nodecount++] = i;
      }
    }
    // We're done looking at every node, so
    // now we just fill in the peercount for the last node.
    if (nodecount) {
      _peercounts[nodecount] = isc_mpi_size - basei;
    }
    else _peercounts[nodecount] = isc_mpi_size;
  }

  return  ++nodecount;

}

static int
__get_peercount(int hostid)
{
  int peercount = 0;

  if (isc_mpi_size > 1) {
      int i, nodecount = __get_nodecount();
      hr_tuple *hr_view = (hr_tuple *)layout;
      for(i=0; i < nodecount; i++) {
	int sindex = _nodes[i];
	if (HR_ID(sindex) == hostid) {
	  return peercount = _peercounts[i];
	}
      }
  }
  return peercount = isc_mpi_size;
}

static void
__gather_topology_info(int myhost)
{
  int rank = isc_mpi_rank;
  int size = isc_mpi_size;

  int  count, status;

  if (size > 1) {
    _nodes = (int *)calloc(size,sizeof(int));
    _ranks = (int *)calloc(size,sizeof(int));
    _peercounts = (int *)calloc(size,sizeof(int));
    layout = (int *)calloc(size*2,sizeof(int));
    layout[rank*2] = myhost;
    layout[(rank*2)+1] = rank;
    status = MPI_Allgather(&layout[rank*2],2, MPI_INT,layout,2,MPI_INT,MPI_COMM_WORLD);
    if (size > 2) qsort(layout,size,sizeof(int)*2,cmphostid);
  }
  __get_nodecount();
  __get_peercount(myhost);
}


int
_ISCMPI_GetLocalPeers(void)
{
  static int localpeers = 0;
  if (!localpeers) {
    int hostid = gethostid();
    __gather_topology_info(hostid);
    localpeers = __get_peercount(hostid);
  }
  return localpeers;
}


int
_ISCMPI_Init()
{
  static int _argc;
  static char *_argv[2] = {"Unused",0};
  int status= MPI_Init(&_argc,(char ***)&_argv);
  if (status == MPI_SUCCESS) {
    /* 
     * Since we're collectively available, now
     * would be a good time to cache some info
     * about how this application is distributed.
     *
     */
    _ISCMPI_GetLocalPeers(); 
  }
  return status;
}


int
MPI_Init(int *argc, char ***argv)
{
  static int (*VendorMPI_Init)(int *,char ***) = 0;
  void *address;
  int status;
  resolve_mpi_library();
  resolve_mpi_constants();

  if ((address = dlsym(MPI_libhandle,"MPI_Init"))) {
    VendorMPI_Init = address;
    status = (*VendorMPI_Init)(argc,argv);
    if (post_MPI_processing) {
      post_MPI_processing();
    }
    /*
     * If things are working, then we can find the
     * rank and size this application.
     */
    MPI_Comm_rank(ISC_COMM_WORLD,&isc_mpi_rank);
    MPI_Comm_size(ISC_COMM_WORLD,&isc_mpi_size);
    return status;
  } else {
    dlclose(ISC_maphandle);
    dlclose(MPI_libhandle);
    if (MPIO_libhandle != MPI_libhandle) {
      dlclose(MPIO_libhandle);
    }
  }
  exit(1);
  return 0;
}


f_common_t *__true_fortran_bottom;
f_common_t __fortran_bottom = {-1,-1,-1,-1,};

int  *__true_fortran_in_place,
     *__true_fortran_argv_null,
     *__true_fortran_argvs_null,
     *__true_fortran_errcodes_ignore,
     *__true_fortran_status_ignore,
     *__true_fortran_statuses_ignore;

/* extern f_common_t MPI_FORTRAN_BOTTOM,mpi_fortran_bottom,mpi_fortran_bottom_,mpi_fortran_bottom__; */

#ifdef __GNUC__
/*
#pragma weak MPI_FORTRAN_BOTTOM = __fortran_bottom
#pragma weak mpi_fortran_bottom = __fortran_bottom
#pragma weak mpi_fortran_bottom_ = __fortran_bottom
#pragma weak mpi_fortran_bottom__ = __fortran_bottom
*/
static f_common_t MPI_FORTRAN_BOTTOM __attribute__ ((weakref, alias("__fortran_bottom")));
static f_common_t mpi_fortran_bottom __attribute__ ((weakref, alias("__fortran_bottom")));
static f_common_t mpi_fortran_bottom_ __attribute__ ((weakref, alias("__fortran_bottom")));
static f_common_t mpi_fortran_bottom__ __attribute__ ((weakref, alias("__fortran_bottom")));
#endif



#ifdef __GNUC__
void MPI_INIT() __attribute__ ((weak, alias("isc_init_f")));
void mpi_init() __attribute__ ((weak, alias("isc_init_f")));
void mpi_init_() __attribute__ ((weak, alias("isc_init_f")));
void mpi_init__() __attribute__ ((weak, alias("isc_init_f")));
#endif


static void
get_bottom(void)
{

  int **p1,**p2,**p3,**p4;

  p1 = (int **)&MPI_FORTRAN_BOTTOM;
  p2 = (int **)&mpi_fortran_bottom;
  p3 = (int **)&mpi_fortran_bottom_;
  p4 = (int **)&mpi_fortran_bottom__;

  if ((*p1 == *p2) ||
      (*p1 == *p3) ||
      (*p1 == *p4)) {
  } else {
    __true_fortran_bottom = *(f_common_t **)p1;
    return;
  }

  if ((*p2 == *p1) ||
      (*p2 == *p3) ||
      (*p2 == *p4)) {
  } else {
    __true_fortran_bottom = *(f_common_t **)p2;
    return;
  }
  
  if ((*p3 == *p1) ||
      (*p3 == *p2) ||
      (*p3 == *p4)) {
  } else {
    __true_fortran_bottom = *(f_common_t **)p3;
    return;
  }

  __true_fortran_bottom = *(f_common_t **)p4;
}

static void
get_inplace(void)
{
  __true_fortran_in_place = &__true_fortran_bottom->in_place;
}

static void
get_argv_null(void)
{
  __true_fortran_argv_null = &__true_fortran_bottom->argv_null;
}

static void
get_argvs_null(void)
{
  __true_fortran_argvs_null = &__true_fortran_bottom->argvs_null;
}

static void
get_errcodes_ignore(void)
{
  __true_fortran_errcodes_ignore = &__true_fortran_bottom->errcodes_ignore;
}

static void
get_status_ignore(void)
{
  __true_fortran_status_ignore = &__true_fortran_bottom->status_ignore;
}

static void
get_statuses_ignore(void)
{
  __true_fortran_statuses_ignore = &__true_fortran_bottom->statuses_ignore;
}

static void
get_fortran_constants(void)
{
  get_bottom();
  get_inplace();
  get_argv_null();
  get_argvs_null();
  get_errcodes_ignore();
  get_status_ignore();
  get_statuses_ignore();
}

void isc_init_f(int *ierr)
{
  int _Argc=1;
  char *_Argv[2] = {"fortran_app",0};

  *ierr = MPI_Init(&_Argc ,(char ***) &_Argv);
  /* Search for the correct common block name(s)...
   * which is to say, the one that isn't aliased
   * to __fortran_bottom 
   */
  get_fortran_constants();
}

int
MPI_Init_thread (int *argc, char ***argv, int required, int *provided)
{
  static void *address=0;
  int mpi_return;
  resolve_mpi_library();
  resolve_mpi_constants();

  if (!address) {
    if ((address = dlsym(MPI_libhandle,"MPI_Init_thread")) == NULL) {
      printf("%s %s %s",SYM_MISSING_PREFIX,"MPI_Init_thread",SYM_MISSING_TRAILER);
      return -1;
    }
  }

  int (*VendorMPI_Init_thread) (int *argc, char ***argv, int required, int *provided) = address;
  mpi_return = (*VendorMPI_Init_thread)(argc,argv,required,provided);

  /* initialize mutex operations */
  if ((mpi_return == MPI_SUCCESS) && (provided != NULL) && (*provided != ISC_THREAD_SINGLE)) {
    pthread_mutex_init(&funnel_new_index,NULL);
    use_mutex = 1;
  }
  return mpi_return;
}



#ifdef __GNUC__
void MPI_INIT_THREAD() __attribute__ ((weak, alias("isc_init_thread_f")));
void mpi_init_thread() __attribute__ ((weak, alias("isc_init_thread_f")));
void mpi_init_thread_() __attribute__ ((weak, alias("isc_init_thread_f")));
void mpi_init_thread__() __attribute__ ((weak, alias("isc_init_thread_f")));
#endif

void isc_init_thread_f(int *required, int *provided, int *ierr)
{
  int _Argc=1;
  char *_Argv[2] = {"fortran_app",0};

  *ierr = MPI_Init_thread(&_Argc ,(char ***) &_Argv,*required,provided);
}


int
MPI_Finalize(void)
{
  static int (*VendorMPI_Finalize)() = 0;
  int status;
  void *address;

  if ((address = dlsym(MPI_libhandle,"MPI_Finalize"))) {
    VendorMPI_Finalize = address;
    status = (*VendorMPI_Finalize)();
  }
  dlclose(MPI_libhandle);
  dlclose(ISC_maphandle);
  if (MPIO_libhandle != MPI_libhandle) {
    dlclose(MPIO_libhandle);
  }

  MPI_libhandle=0;
  MPIO_libhandle=0;
  ISC_maphandle=0;

  return status;
}

#ifdef __GNUC__
void MPI_FINALIZE() __attribute__ ((weak, alias("isc_finalize_f")));
void mpi_finalize() __attribute__ ((weak, alias("isc_finalize_f")));
void mpi_finalize_() __attribute__ ((weak, alias("isc_finalize_f")));
void mpi_finalize__() __attribute__ ((weak, alias("isc_finalize_f")));
#endif

void isc_finalize_f(int *ierr)
{
  *ierr = MPI_Finalize();
}

int Isc_dup_fn (ISC_Comm oldcomm, int keyval, void *extra, void *attr_in, void *attr_out, int *flag )
{
  (*(void **)attr_out) = attr_in;
  (*flag) = 1;
  return ISC_SUCCESS;
}






