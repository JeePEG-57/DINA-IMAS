LOCAL_DIR := $(PWD)
# ----------------------------
# User-selectable compiler
# ----------------------------
FCOMPILER ?= gfortran
CCOMPILER ?= gcc

ACTOR = tcv_controller

INCDIR := ../../../src/include
CODEGEN_DIR := ./codegen_dina



DEBUG = -g -O0 -fno-inline -fbacktrace
# ----------------------------
# Packages
# ----------------------------
PACKAGES =
PACKAGES += al-fortran
PACKAGES += xmllib

F90LIB =
F90INC = -I$(INCDIR)

# ----------------------------
# Fortran preprocessor defines
# ----------------------------
F90DEF += -D'GIT_URL="$(GIT_URL)"'
F90DEF += -D'GIT_COMMIT_ID="$(GIT_COMMIT_ID)"'
F90DEF += -D'GIT_VERSION="$(GIT_VERSION)"'

# ----------------------------
# Compiler flags
# ----------------------------
ifeq ($(FCOMPILER), gfortran)
  F90FLAGS = -fPIC -cpp
else ifeq ($(FCOMPILER), ifort)
  F90FLAGS = -fPIC -fpp -g
else
  $(error Unsupported Fortran compiler)
endif

F90FLAGS += -w -freal-4-real-8 -fno-second-underscore -ffree-line-length-none -Wl,--no-relax
F90FLAGS += $(F90DEF)
F90FLAGS += $(DEBUG)

# pkg-config flags
F90LIB += `pkg-config $(PACKAGES) --libs`
F90INC += `pkg-config $(PACKAGES) --cflags`

# ----------------------------
# MATLAB generated library
# ----------------------------
MATLAB_LIB = $(CODEGEN_DIR)/hybctrl_step_IDS.a
MATLAB_INC = -I$(CODEGEN_DIR)
ifneq ("$(wildcard $(MATLAB_LIB))","")
$(info The hybctrl_step_IDS.a library exists. Continuing...)
else
$(info No hybctrl_step_IDS.a library found.)
$(error Compile the controller on LAC first !)
endif




# ----------------------------
# Fortran object files
# ----------------------------
F90_OBJS = \
    hybctrl_types_mod.o \
    hybctrl_c_interface_mod.o \
    tcv_controller_state_mod.o \
    $(ACTOR).o

# ----------------------------
# Build rules
# ----------------------------
all: lib test

lib: $(ACTOR).a

# Static library for actor
$(ACTOR).a: $(F90_OBJS)
	ar -rcs $@ $(F90_OBJS) 

# Fortran compilation rule
%.o : %.f90
	$(FCOMPILER) $(F90FLAGS) $(F90INC) $(MATLAB_INC) -c $<

# ----------------------------
# Build test executable
# ----------------------------
test: test_actor.exe



test_actor.exe: test_actor.o $(ACTOR).a
	$(FCOMPILER) -o $@ test_actor.o $(ACTOR).a $(MATLAB_LIB) $(F90LIB) 

# ----------------------------
# Validation
# ----------------------------
validate:
	xmllint --noout test_wf_parameters.xsd test_wf_parameters.xml
	xmllint --noout --schema test_wf_parameters.xsd test_wf_parameters.xml
	xmllint --noout code_parameters.xsd code_parameters.xml
	xmllint --noout --schema code_parameters.xsd code_parameters.xml

# ----------------------------
# Clean
# ----------------------------
clean:
	rm -f *.exe *.a *.o *.mod
