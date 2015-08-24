SHELL=/bin/sh

ifeq "$(strip $(CC))" "icc"
 CXX=icpc
 LD=$(CXX)
 CXXFLAGS=-g -O0 -fPIC -shared-intel
 LDFLAGS= -g 
else
 CXX=g++
 LD=$(CXX)
 CXXFLAGS=-g -O0 -fPIC
 LDFLAGS= -g 
endif

AFS = /work/imas/projects
MDSPLUS_DIR = $(AFS)/mdsplus/mdsplus
BLITZ_DIR = $(AFS)/blitz/blitz-0.9_X86_64_GNU
INCDIR = -I$(UAL)/cppinterface -I$(UAL)/lowlevel -I$(BLITZ_DIR)/include -I$(BLITZ_DIR)
LIBDIR = -L$(MDSPLUS_DIR)/lib64 -L$(MDSPLUS_DIR)/lib -L$(UAL)/cppinterface -L$(UAL)/lowlevel -L$(HDF5_DIR)/lib -Wl,-rpath,$(UAL)/itmcatalog/lib
LIBS = -lUALCPPInterface -lUALLowLevel -lTreeShr -lTdiShr -lMdsShr -lMdsIpShr -lXTreeShr $(BLITZ_DIR)/lib/libblitz.a 

ALL_PROGS = test_getslice_PF

all:$(ALL_PROGS)

install:

clean:
	rm -f $(ALL_PROGS) *~ *.o

LoadIDSmex: LoadIDSmex.o
	$(LD) $(LDFLAGS) $@.o -o $@ $(LIBDIR) $(LIBS)

test_getslice_PF: test_getslice_PF.o
	$(LD) $(LDFLAGS) $@.o -o $@ $(LIBDIR) $(LIBS)
#	echo $(BLITZ_DIR)
#	echo $(HDF5_DIR)

#RULES
.SUFFIXES: .cpp

.cpp.o:
	$(CXX) $(INCDIR) $(CXXFLAGS) -c $< 

	
