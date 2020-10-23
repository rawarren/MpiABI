ISCMPI = src
ISCBIN = bin
MAP_SRCDIR=mapping
ISCMPI_INCLUDE=src/include
ISCMPI_DIRS = src src/f77
ABIDIR = $(HOME)/mpiabi

VPATH = src:src/f77:$(MAP_SRCDIR)
ISCMPI_SRC := $(foreach DIR,$(ISCMPI_DIRS),$(wildcard $(DIR)/*.c))
ISCMPI_OBJS := $(notdir $(ISCMPI_SRC:.c=.o))

CFLAGS = -g -pthread -fPIC -shared

#
# Compilation of the iscmpi -> vendor_mpi mapping support
# -------------------------------------------------------
# INTEL
# 
INTEL_INCLUDE=/opt/intel/parallel_studio_xe_2019.5.075/compilers_and_libraries_2019/linux/mpi/intel64/include
INTELMPI_INCLUDE = -I$(INTEL_INCLUDE)
# -------------------------------------------------------
# MPICH
# 
MPICH_INCLUDE = -I$(HOME)/mpich-install-3.3/include
# -------------------------------------------------------
# HPMPI
# 
HPMPI_INCLUDE = -I$(HP_INCLUDE)
# -------------------------------------------------------
# SGI
# 
SGI_INCLUDE = -I/usr/include
SGIICE_INCLUDE = -IVENDOR/SGI/include
# -------------------------------------------------------
# OpenMPI
# 
OMPI_INCLUDE = -I$(HOME)/openmpi-install-4.0.5/include

default:	install

intel_map: 
	$(CC) $(CFLAGS) -I$(ISCMPI_INCLUDE) $(INTELMPI_INCLUDE) -DVENDOR_MPI_SO=\"libmpi.so\" \
        $(MAP_SRCDIR)/iscmpi_mapping.c -o isc_mapping_intelmpi.so

#
# FIXME:  The building of the mapping library for HPMPI currently
#         requires that we link directly against the MPI library
#         due to the fact that we "dlopen" the MPI library AFTER
#         opening the "isc_mapping.so" library to get the libray
#         name (see: -DVENDOR_MPI_SO)
#
hpmpi_map: 
	$(CC) $(CFLAGS) -I$(ISCMPI_INCLUDE) $(HPMPI_INCLUDE) -DHPMPI -DVENDOR_MPI_SO=\"libmpi.so,libmpio.so\" \
        $(MAP_SRCDIR)/iscmpi_mapping.c -o isc_mapping_hpmpi.so

mpich_map: 
	$(CC) $(CFLAGS) $(MPICH_INCLUDE) -I$(ISCMPI_INCLUDE) -DVENDOR_MPI_SO=\"libmpich.so\" \
        $(MAP_SRCDIR)/iscmpi_mapping.c -o $(ABIDIR)/mapper/MPICH/isc_mapping.so

altix_map: 
	$(CC) $(CFLAGS) -I$(ISCMPI_INCLUDE) $(SGI_INCLUDE) -DSGI -DVENDOR_MPI_SO=\"libmpi.so\" \
        $(MAP_SRCDIR)/iscmpi_mapping.c -o isc_mapping_altixmpi.so

sgi_ice_map: 
	$(CC) $(CFLAGS) -I$(ISCMPI_INCLUDE) $(SGIICE_INCLUDE) -DSGI -DVENDOR_MPI_SO=\"libmpi.so\" \
        $(MAP_SRCDIR)/iscmpi_mapping.c -o isc_mapping_sgiicempi.so

#
# OpenMPI like HP_MPI, is linked directly against the mapping library to allow the
# Pointer references to be resolved...
#
openmpi_map: 
	$(CC) $(CFLAGS) -I$(ISCMPI_INCLUDE) $(OMPI_INCLUDE) -DOPENMPI -DVENDOR_MPI_SO=\"libmpi.so\" \
        $(MAP_SRCDIR)/iscmpi_mapping.c -L$(HOME)/openmpi-install-4.0.5/lib -lmpi -o $(ABIDIR)/mapper/OpenMPI/isc_mapping.so

openmpi_ia32_map: 
	$(CC) $(CFLAGS) -I$(ISCMPI_INCLUDE) $(OMPI_INCLUDE) -DOPENMPI -DVENDOR_MPI_SO=\"libmpi.so\" \
        $(MAP_SRCDIR)/iscmpi_mapping.c -L/usr/local/lib -lmpi -o isc_mapping_openmpi_ia32.so 


maplibs: intel_map hpmpi_map openmpi_map

pre_install:	
	mkdir -p $(ABIDIR)/bin
	mkdir -p $(ABIDIR)/lib
	mkdir -p $(ABIDIR)/include
	mkdir -p $(ABIDIR)/mapper
	mkdir -p $(ABIDIR)/mapper/MPICH
	mkdir -p $(ABIDIR)/mapper/OpenMPI
	cp $(ISCMPI)/include/iscmpi_constants.h $(ABIDIR)/include/iscmpi_constants.h
	cp $(ISCMPI)/include/mpi2isc.h $(ABIDIR)/include/mpi2isc.h
	cp $(ISCMPI)/include/mpif-common.h $(ABIDIR)/include/mpif-common.h
	cp $(ISCMPI)/include/_mpi.h $(ABIDIR)/include/mpi.h
	cp $(ISCMPI)/include/_mpif.h $(ABIDIR)/include/mpif.h
	cp $(ISCBIN)/mpicc $(ABIDIR)/bin
	echo "/* Dummy mpio.h include for hdf5 and others... */" > $(ABIDIR)/include/mpio.h
	(cd include; ln -fs mpi.h iscmpi.h)

libiscmpi: $(ARCH_NAME) $(ISCMPI_OBJS)
	$(CC) -shared -pthread *.o -o libiscmpi.so -ldl

install:	libiscmpi pre_install
	cp libiscmpi.so $(ABIDIR)/lib/libiscmpi.so
#	cp libiscmpi.so $(PLATFORMDIR)

em64t_linux:	pre_install
	@echo INSTALLING ISCMPI for $(ARCH_NAME)
	cp $(ARCH_NAME)/*.so $(LIBSDIR)/$(PLATFORM)_intel/

ia64_linux:	pre_install
	@echo INSTALLING ISCMPI for $(ARCH_NAME)
	cp $(ARCH_NAME)/*.so $(LIBSDIR)/$(PLATFORM)_intel/

em64t_win64:	
	@echo NO ISCMPI action required for $(ARCH_NAME)

ia32_darwin:	
	@echo NO ISCMPI action required for $(ARCH_NAME)

ia32_linux:	
	@echo NO ISCMPI action required for $(ARCH_NAME)

ia32_win:	
	@echo NO ISCMPI action required for $(ARCH_NAME)

%.o: %.c
	cc $(CFLAGS) -I$(ISCMPI)/include -c $< -o $@

clean:
	rm -f *.o
	rm -f *.so*

realclean:	clean
	rm -rf $(ARCHOUTDIR)/iscmpi
	rm -f $(LIBSDIR)/$(PLATFORM)_intel/libiscmpi.so
	rm -f $(LIBSDIR)/$(PLATFORM)_intel/isc_mapping*.so

