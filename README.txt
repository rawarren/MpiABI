Notes on maintaining this library.
1.  Adding ISC wrappers
    - The easiest way to add a new function to the library is to copy
      an existing file whose functionality is similar to that of the
      new API.
    - Add the new API function prototype into the src/include/_mpi.h file.
    - Make sure that the new API is added into the mpi2isc.h file
      which maps/redefines the MPI function name into the same
      API name with an ISC_ prefix which replaces MPI_.  This
      should prevent internal vendor implementations from mistakenly
      calling into the ISC layer, i.e. once the vendor library
      is called, any subsequent processing shall remain within
      the context of the vendor implemention, including calls to
      MPI_xxx functionality.

2.  Adding new Vendor mapping libraries.
