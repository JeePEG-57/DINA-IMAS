FCOMPILER?=gfortran
ACTOR=dina_imas
INCDIR:=../../../src/include

DEBUG=-g -O0

PACKAGES=
PACKAGES+=imas-$(FCOMPILER)
#PACKAGES+=al-fortran
#PACKAGES+=libxml-2.0
PACKAGES+=xmllib

F90LIB=
F90INC=-I$(INCDIR)

# COMPILER-SPECIFIC FLAGS
ifeq ($(FCOMPILER), ifort)
  F90FLAGS=-fPIC -fpp -g
else ifeq ($(FCOMPILER), gfortran)
  F90FLAGS=-fPIC -cpp
else
  $(error Unsupported Fortran compiler)
endif

F90FLAGS+=-w -freal-4-real-8 -fno-second-underscore -ffree-line-length-none
F90FLAGS+=$(DEBUG)

F90=$(FCOMPILER)

# FLAGS OF PACKAGES
F90LIB+=`pkg-config $(PACKAGES) --libs`
F90INC+=`pkg-config $(PACKAGES) --cflags`

# LIST OF OBJECT FILES
OBJS_ACTOR = ../../../src/scenario/dina_99.a dina_imas.o dina_params_imas.o
OBJS_TEST  = test_actor.o 

IWRAP_ACTORS_DIR ?= $(HOME)/IWRAP_ACTORS

TEST=test_$(ACTOR)

all: lib exe

lib: $(ACTOR).a

exe: $(TEST).exe

actor : lib ## Builds the IWrap actor
	iwrap -a $(ACTOR) -f iwrap_settings.yaml
	
actor-gui : lib ## Opens IWrap GUI 
	iwrap-gui -a $(ACTOR) -f iwrap_settings.yaml
	
$(TEST).exe: $(OBJS_TEST) $(ACTOR).a
	$(F90) $(F90FLAGS) -o $@ $^ $(F90LIB)

$(ACTOR).a: $(OBJS_ACTOR)
	@cp $< $@
	ar -rcs $@ $^

%.o:%.f90
	$(F90) $(F90FLAGS) -c $< $(F90INC)

validate:
	xmllint --noout $(TEST)_parameters.xsd $(TEST)_parameters.xml
	xmllint --noout --schema $(TEST)_parameters.xsd $(TEST)_parameters.xml
	xmllint --noout $(ACTOR).xsd $(ACTOR).xml
	xmllint --noout --schema $(ACTOR).xsd $(ACTOR).xml

clean:
	rm -rf *.exe *.a *.mod *.o
	rm -rf $(IWRAP_ACTORS_DIR)/$(ACTOR)

